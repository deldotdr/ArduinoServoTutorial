# Introduction to Arduino and OpenRB-150 Servo Control

## What is Arduino?
Arduino is an open-source electronics platform based on easy-to-use hardware and software. It consists of microcontroller boards (like the OpenRB-150) and a development environment (Arduino IDE) for writing and uploading code. Arduino is widely used for learning electronics, prototyping, and creating interactive projects.

## What are Microcontrollers?
A microcontroller is a small, integrated computer on a single chip, containing a CPU, memory (RAM and ROM), and input/output peripherals. Unlike general-purpose computers, microcontrollers are designed for specific tasks, such as controlling devices like LEDs, sensors, or servos. The OpenRB-150 uses a 32-bit ARM Cortex-M4 microcontroller, ideal for robotics and precise control.

## Getting Started with Arduino Programming

### On Windows
1. **Download Arduino IDE:**
   - Visit [arduino.cc/en/software](https://www.arduino.cc/en/software) and download the latest Arduino IDE for Windows.
   - Install it by running the `.exe` file and following the prompts.
2. **Install Drivers:**
   - Connect your OpenRB-150 via USB. Windows should automatically install drivers, but if not, download them from [ROBOTIS Support](https://www.robotis.us/openrb-150-starter-kit/).
3. **Launch IDE:**
   - Open the Arduino IDE from the Start menu.

### On macOS
1. **Download Arduino IDE:**
   - Visit [arduino.cc/en/software](https://www.arduino.cc/en/software) and download the macOS version.
   - Drag the `.app` file to your Applications folder.
2. **Install Drivers:**
   - Connect the OpenRB-150 via USB; macOS typically handles drivers automatically.
3. **Launch IDE:**
   - Open the Arduino IDE from Applications.

### Installing Dependencies for OpenRB-150
The OpenRB-150 uses the `Dynamixel2Arduino` library to control DYNAMIXEL servos:
1. Open Arduino IDE.
2. Go to **Sketch > Include Library > Manage Libraries**.
3. Search for `Dynamixel2Arduino`, select it, and click **Install**.
4. Verify installation by checking **File > Examples** for `Dynamixel2Arduino` examples.

## Project Overview
This repository contains a series of sketches to teach Arduino basics and servo control with the OpenRB-150:
1. `BlinkLED.ino` - Basic Arduino setup and LED control.
2. `OpenRBIntro.ino` - Introduction to OpenRB-150 and DYNAMIXEL.
3. `ServoBasics.ino` - Basic servo control concepts.
4. `SerialControl.ino` - Using Serial for command input.
5. `CreativeServoDemo.ino` - Combining Serial and OpenRB-150 for creative servo demos.

Connect your OpenRB-150, upload each sketch, and follow the comments to learn!
