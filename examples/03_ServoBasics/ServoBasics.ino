/*
 * ServoBasics.ino
 * Purpose: Demonstrate basic servo control concepts with OpenRB-150.
 * Hardware: OpenRB-150 with a DYNAMIXEL servo.
 * Learning Goals:
 * - Move servo to specific positions.
 * - Understand position control in pulses (0-4095 range).
 * - Use delay() for timing movements.
 */

#include <Arduino.h>
#include <Dynamixel2Arduino.h>

#define DXL_SERIAL   Serial1
#define DXL_DIR_PIN  2
#define DXL_ID       1
#define BAUDRATE     57600

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

void setup() {
  Serial.begin(115200);
  while (!Serial);

  dxl.begin(BAUDRATE);
  dxl.setPortProtocolVersion(2.0);

  if (!dxl.ping(DXL_ID)) {
    Serial.println("Servo not found!");
    while (1);
  }

  dxl.torqueOff(DXL_ID);
  dxl.setOperatingMode(DXL_ID, OP_POSITION);
  dxl.torqueOn(DXL_ID);

  Serial.println("Servo ready. Starting basic movements...");
}

void loop() {
  // Move to 0° (0 pulses)
  dxl.setGoalPosition(DXL_ID, 0);
  Serial.println("Moving to 0°");
  delay(2000);

  // Move to 180° (2048 pulses, half of 4096)
  dxl.setGoalPosition(DXL_ID, 2048);
  Serial.println("Moving to 180°");
  delay(2000);

  // Move to 300° (≈3413 pulses, 5/6 of 4096)
  dxl.setGoalPosition(DXL_ID, 3413);
  Serial.println("Moving to 300°");
  delay(2000);
}
