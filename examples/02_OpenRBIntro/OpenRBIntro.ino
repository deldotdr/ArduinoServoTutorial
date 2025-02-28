/*
 * OpenRBIntro.ino
 * Purpose: Introduce the OpenRB-150 and DYNAMIXEL servo setup.
 * Hardware: OpenRB-150 with a DYNAMIXEL servo (e.g., XL-430) connected to a DYNAMIXEL port.
 * Dependencies: Install Dynamixel2Arduino library via Library Manager.
 * Learning Goals:
 * - Initialize the OpenRB-150 for DYNAMIXEL communication.
 * - Verify servo connection with a simple position command.
 */

#include <Arduino.h>
#include <Dynamixel2Arduino.h>

#define DXL_SERIAL   Serial1  // OpenRB-150 DYNAMIXEL port
#define DXL_DIR_PIN  2        // Direction pin
#define DXL_ID       1        // Servo ID
#define BAUDRATE     57600    // Default DYNAMIXEL baudrate

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

void setup() {
  Serial.begin(115200);  // Start Serial for debugging
  while (!Serial);

  dxl.begin(BAUDRATE);           // Initialize DYNAMIXEL communication
  dxl.setPortProtocolVersion(2.0);  // Use Protocol 2.0

  // Check if servo is connected
  if (dxl.ping(DXL_ID)) {
    Serial.println("Servo found!");
    
    // Set to position mode and enable torque
    dxl.torqueOff(DXL_ID);
    dxl.setOperatingMode(DXL_ID, OP_POSITION);
    dxl.torqueOn(DXL_ID);
    
    // Move to center position (2048 = middle of 0-4095 range)
    dxl.setGoalPosition(DXL_ID, 2048);
  } else {
    Serial.println("Servo not found! Check connections.");
    while (1);  // Stop if no servo
  }
}

void loop() {
  // Empty - one-time setup demo
}
