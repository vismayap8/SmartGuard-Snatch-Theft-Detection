# SmartGuard – Snatch Theft Detection and Alert System
## Overview
SmartGuard is an Arduino-based safety system designed to detect possible snatch theft incidents using an MPU6050 accelerometer. The system continuously monitors sudden movements and calculates the G-force generated. When the detected G-force exceeds a predefined threshold, it activates a buzzer and sends an alert through a Bluetooth module.

This project is developed as a low-cost prototype to enhance personal safety and can be extended in the future with GPS and GSM modules for real-time location tracking and SMS alerts.
## Features

- Detects sudden motion using the MPU6050 accelerometer.
- Calculates G-force in real time.
- Triggers a buzzer when the G-force exceeds the threshold.
- Sends alert messages via Bluetooth.
- Displays alert information on the Serial Monitor.
- Low-cost and easy-to-build prototype.
- Can be upgraded with GPS and GSM modules for real-time location tracking and SMS alerts.
- ## Hardware Components

| Component and its Purpose |

| Arduino Uno - Main microcontroller that controls the system |
| MPU6050 Accelerometer & Gyroscope - Detects sudden movement and calculates G-force |
| HC-05 Bluetooth Module - Sends alert messages to a paired mobile device |
| Active Buzzer - Produces an audible alarm when a snatch is detected |
| Breadboard - Used for prototyping the circuit |
| Jumper Wires - Connect all hardware components |
| USB Cable - Powers and programs the Arduino |
## Software & Libraries Used

### Software
- Arduino IDE

### Programming Language
- C++

### Libraries
- Wire.h
- MPU6050.h
- SoftwareSerial.h
- ## Working Principle

The SmartGuard system continuously monitors the user's movement using the MPU6050 accelerometer. The sensor measures acceleration along the X, Y, and Z axes. The Arduino calculates the resultant G-force using these values.

If the calculated G-force exceeds the predefined threshold (2.5g), the system identifies it as a potential snatch theft event. It then:

1. Activates the buzzer to provide an audible alert.
2. Sends an alert message through the HC-05 Bluetooth module.
3. Displays the alert and location information on the Serial Monitor.
4. Waits for a short interval before resuming monitoring.

This prototype demonstrates how sudden motion can be used to detect suspicious events and trigger immediate alerts.
## Project Workflow

```text
                Start
                  │
                  ▼
        Initialize Arduino
                  │
                  ▼
        Initialize MPU6050
                  │
                  ▼
     Read X, Y, Z Acceleration
                  │
                  ▼
        Calculate G-Force
                  │
                  ▼
      Is G-Force > 2.5g?
            │ │
          No Yes
           │ │
           ▼ ▼
 Continue Monitoring Activate Buzzer
                         │
                         ▼
                Send Bluetooth Alert
                         │
                         ▼
              Display Alert Message
                         │
                         ▼
              Resume Monitoring
```
## Installation & Usage

### Prerequisites

- Arduino IDE
- Arduino Uno
- MPU6050 Library
- Wire Library
- SoftwareSerial Library

### Steps

1. Clone this repository:
   ```bash
   git clone https://github.com/vismayap8/SmartGuard-Snatch-Theft-Detection.git
   ```
2. Open `Arduino_Code/SmartGuard.ino` in the Arduino IDE.
3. Install the required libraries if they are not already installed.
4. Connect the hardware according to the circuit diagram.
5. Select the correct Board (**Arduino Uno**) and COM Port.
6. Upload the code to the Arduino.
7. Open the Serial Monitor (9600 baud) or connect to the HC-05 Bluetooth module to view alerts.
