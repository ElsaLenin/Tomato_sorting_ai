# 🍅 AI-Powered Automated Tomato Sorting System

An end-to-end Computer Vision and Hardware System designed to automatically detect and sort ripe and unripe tomatoes in real-time using **YOLOv11**, **Roboflow**, and **Arduino**.


---

## 📌 Features
* **Real-time Object Detection:** Uses YOLOv11 trained on a custom dataset to classify tomatoes by ripeness.
* **Roboflow Dataset Integration:** Streamlined dataset preparation and annotation pipeline.
* **Hardware Automation:** Python communicates with an Arduino microcontroller over Serial to trigger servo motor mechanisms for sorting.


---

## 🛠️ Tech Stack & Hardware

### **Software**
* **Language:** Python 3.x, C++ (Arduino)
* **Computer Vision:** YOLOv11 (`ultralytics`), OpenCV
* **Data Management:** Roboflow
* **Hardware Communication:** PySerial

### **Hardware**
* **Microcontroller:** Arduino Uno
* **Actuator:** SG90 Servo Motor
* **Camera:** USB Webcam
* **Power Supply:** External 5V DC supply for servos

---

## 📐 System Architecture

1. **Video Stream:** The camera captures live feed from the conveyor/sorting zone.
2. **Inference:** YOLOv11 processes frames and detects whether a tomato is **Ripe** or **Unripe**.
3. **Control Signal:** Python sends a command signal via Serial (`'r'` for Ripe, `'u'` for Unripe) to the Arduino.
4. **Actuation:** The Arduino drives the servo motor to rotate the chute/arm to route the tomato into its designated bin.

---



