import tkinter as tk
from tkinter import messagebox
import speech_recognition as sr
import serial
import threading
import time

# UART Setup
try:
    ser = serial.Serial('COM6', 9600)
    time.sleep(2)
except Exception as e:
    print("Serial port error:", e)
    ser = None

# Command map
command_map = {
    "turn on led": 0,
    "turn off led": 1,
    "turn on music": 2,
    "turn off music": 3,
    "start counter": 4,
    "stop counter": 5,
    "turn on buzzer": 6,
    "turn off buzzer": 7,
    "stop everything": 8,
    "flash led": 9
}

# Initialize recognizer
recognizer = sr.Recognizer()

# --- Function to handle voice recognition ---
def recognize_speech():
    with sr.Microphone() as source:
        try:
            status_label.config(text="Listening...")
            root.update()

            recognizer.adjust_for_ambient_noise(source, duration=0.5)
            audio = recognizer.listen(source)

            text = recognizer.recognize_google(audio)
            text = text.lower().strip()

            recognized_text_var.set(text)
            status_label.config(text="Recognized.")

            if text in command_map:
                cmd = command_map[text]
                if ser:
                    ser.write(bytes([cmd]))
                    status_label.config(text=f"Command sent: {cmd}")
                else:
                    status_label.config(text="Serial not available.")
            else:
                status_label.config(text="Command not recognized.")

        except sr.UnknownValueError:
            recognized_text_var.set("Could not understand audio.")
            status_label.config(text="Try again.")
        except sr.RequestError as e:
            recognized_text_var.set(f"API error: {e}")
            status_label.config(text="API error.")

# Threaded version to avoid GUI freezing
def threaded_recognize():
    threading.Thread(target=recognize_speech).start()

# --- GUI Setup ---
root = tk.Tk()
root.title("Voice Command Interface")
root.geometry("400x200")

recognized_text_var = tk.StringVar()
recognized_text_var.set("Press 'Start Listening' to begin.")

label = tk.Label(root, textvariable=recognized_text_var, font=("Arial", 14), wraplength=380)
label.pack(pady=20)

start_button = tk.Button(root, text="Start Listening", command=threaded_recognize, font=("Arial", 12))
start_button.pack(pady=10)

status_label = tk.Label(root, text="", fg="blue", font=("Arial", 10))
status_label.pack()

root.mainloop()
