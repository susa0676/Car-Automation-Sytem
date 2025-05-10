# Car-Automation-Sytem
 IOT
# 🚗 Car Automation System – IoT Lab Hackathon Project

A smart car automation prototype built using Arduino UNO, ultrasonic sensor, and temperature sensor. This system enhances vehicle safety by detecting obstacles and monitoring temperature, with immediate alerts through a buzzer and autonomous motion adjustments.

---

## 📘 Project Overview

The goal of this project is to integrate key IoT components in a small-scale car system to:
- Avoid obstacles using an **ultrasonic sensor**
- Monitor temperature conditions using a **temperature sensor**
- Alert users via a **buzzer**
- Control direction using **DC motors**

Developed as part of the **IoT Lab Hackathon** under the guidance of **Prof. Nithya S.**, this project is a demonstration of real-time embedded systems in automation and safety.

---

## 🧠 Core Components

### Sensors
- **Ultrasonic Sensor**: For obstacle detection and distance measurement
- **Temperature Sensor**: To monitor ambient or component temperature

### Actuator
- **Buzzer**: To provide sound alerts in critical situations (e.g., object too close)

### Controller
- **Arduino UNO**: The microcontroller used to interface sensors and control the car

---

## ⚙️ Materials Required

- Arduino UNO board  
- Ultrasonic Sensor (HC-SR04)  
- Temperature Sensor (e.g., LM35)  
- DC Motors  
- Motor Driver Module (L298N or equivalent)  
- Buzzer  
- Wheels  
- Battery Pack  
- Switch  
- Cardboard (for chassis)  
- Jumper wires

---

## 📦 Features

- Automatic forward movement unless obstacle detected
- Directional decision-making based on obstacle position
- Sound-based alerts for safety
- Custom control logic using real-time sensor feedback
- Basic self-navigation logic implemented in Arduino

---

## 💻 Code Structure

Main features:
- Distance measured using `pulseIn()` with ultrasonic sensor
- Threshold-based obstacle logic
- Conditional turning and movement
- Real-time buzzer alerts

Code snippet:
```cpp
if (distance < obstacleThreshold) {
  stopCar();
  if (checkObstacleOnRight()) {
    goBackward();
    turnLeft();
  } else {
    turnRight();
  }
} else {
  moveForward();
}
```
Full Arduino code is provided in the repository.
---

🖼️ Prototype & Demo

📸 Prototype Images: Screenshot Folder

📽️ Demo Video: https://drive.google.com/drive/folders/1BByc8SFzrKn9JXHAt_OGTketpXX6-i1W

👥 Team Members
Team Name: Gadget Freaks
Project Number: 66

Akash (22BIT0546)

Sudharsanan (22BIT0676)

Arnav Vadan (22BIT0240)

Daksh Rupani (21BIT0191)

Om Patro (21BIT0115)

Sudhanshu Shukla (21BIT0735)

📚 References
BuiltIn – IoT in Vehicles -  https://builtin.com/articles/iot-in-vehicles

Aimprosoft – Automotive IoT - https://www.aimprosoft.com/blog/automotive-iot- use-cases-for-cars-vehicles/ 

Arduino Official Store - https://store.arduino.cc/collections/boards-modules 

IEEE Xplore - https://ieeexplore.ieee.org/ 

📝 License
This project is for educational purposes only and follows open-source practices under the MIT License. See LICENSE for more information.