# 6-Axis Robotic Arm Control via Bluetooth

## Overview

This project controls a 6-axis robotic arm using Arduino and Bluetooth communication. A mobile or computer app sends commands over Bluetooth, which the Arduino parses and maps to servo positions for each joint.

## Features

- Real-time control of 6 servo motors
- Bluetooth communication (via SoftwareSerial)
- Simple serial protocol for sending commands
- Custom mapping for each servo’s movement range

## Hardware Used

- Arduino (Uno/Nano/etc.)
- 6 x Servo Motors
- HC-05 Bluetooth Module
- Power supply for servos

## Communication Protocol

The Bluetooth module receives data in the following format:


- **Servo ID** is a single character from `A` to `F`, each corresponding to a specific servo motor.
- **Angle Value** is an integer from `0` to `180`.

### Example:

- Sending `A90` will move Servo 1 (servo A) to the mapped position for input `90`.
- Sending `C45` will move Servo 3 (servo C) to the mapped position for input `45`.

Each servo has its own mapped range to ensure safe and precise movements.

## Wiring

| Servo | Arduino Pin |
|-------|--------------|
| A (Servo 1) | 3 |
| B (Servo 2) | 5 |
| C (Servo 3) | 6 |
| D (Servo 4) | 9 |
| E (Servo 5) | 10 |
| F (Servo 6) | 11 |

**Bluetooth module wiring:**

- `TX (Bluetooth)` ➔ `Pin 0 (RX Arduino)`
- `RX (Bluetooth)` ➔ `Pin 1 (TX Arduino)`

⚠️ **Note:** It’s recommended to use SoftwareSerial pins other than `0/1` to avoid conflicts with USB serial.

## How to Use

1. Upload the code to your Arduino.
2. Pair your Bluetooth module with your mobile device or PC.
3. Use any serial Bluetooth terminal app to send control commands.
4. The robotic arm will respond in real-time.
