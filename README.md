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
This repository contains a series of sketches (in `examples` folder) to teach Arduino basics and servo control with the OpenRB-150:
1. `01_BlinkLED.ino` - Basic Arduino setup and LED control.
2. `02_OpenRBIntro.ino` - Introduction to OpenRB-150 and DYNAMIXEL.
3. `03_ServoBasics.ino` - Basic servo control concepts.
4. `04_SerialControl.ino` - Using Serial for command input.
5. `05_ServoDemo.ino` - Combining Serial and OpenRB-150 for creative servo demos.

Connect your OpenRB-150, upload each sketch, and follow the comments to learn!

## Selecting Board and Port

### Understanding Board Selection
When programming with Arduino IDE, you need to tell the software what type of microcontroller board you're using:

1. Go to **Tools > Board** in the Arduino IDE.
2. For the OpenRB-150, select **Arduino ARM (32-bits) Boards > OpenRB-150**.
   - If you don't see the OpenRB-150 option, you might need to install the board package:
     - Go to **Tools > Board > Boards Manager**
     - Search for "OpenRB" or "ROBOTIS"
     - Install the appropriate board package provided by ROBOTIS

### Understanding Port Selection
The Port is how your computer communicates with the microcontroller:

1. Connect your OpenRB-150 to your computer using a USB cable.
2. Go to **Tools > Port** in the Arduino IDE.
3. Select the port that corresponds to your OpenRB-150 board.

#### Identifying the Correct Port
- **On Windows**: Ports appear as COM# (e.g., COM3, COM4). The port associated with your OpenRB-150 typically appears as a new option when you connect the board.
- **On macOS**: Ports appear as /dev/cu.usbmodem#### or /dev/cu.usbserial-####.
- **On Linux**: Ports appear as /dev/ttyACM# or /dev/ttyUSB#.

If you're unsure which port corresponds to your board:
1. Note which ports are available in the menu.
2. Disconnect your OpenRB-150.
3. Check the menu again to see which port disappeared.
4. Reconnect your OpenRB-150 and select the port that reappears.

### Troubleshooting Connection Issues
- If no port appears when your board is connected:
  - Check your USB cable (try a different one if available)
  - Ensure drivers are properly installed
  - Restart the Arduino IDE
  - On Windows, check Device Manager for unknown devices that might need drivers
  - On macOS, check System Information > USB for unrecognized devices
