/*
 * CreativeServoDemo.ino
 * Purpose: Combine Serial commands and OpenRB-150 servo control for creative demos.
 * Hardware: OpenRB-150 with a DYNAMIXEL servo.
 * Learning Goals:
 * - Control servo position via Serial input.
 * - Create fun movement patterns (wave, dance, reset).
 * - Translate real-world units (mm) to servo pulses.
 */

#include <Arduino.h>
#include <Dynamixel2Arduino.h>

#define DXL_SERIAL   Serial1
#define DXL_DIR_PIN  2
#define DXL_ID       1
#define BAUDRATE     57600
#define PULSES_PER_ROTATION 4096
#define MM_PER_ROTATION 10.0  // Assuming 10mm ball screw pitch
#define PULSE_PER_MM (PULSES_PER_ROTATION / MM_PER_ROTATION)

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

  Serial.println("Creative Servo Demo");
  Serial.println("Commands:");
  Serial.println("- 'pos <mm>' (e.g., 'pos 50'): Move to position in mm");
  Serial.println("- 'wave': Oscillate like a wave");
  Serial.println("- 'dance': Random dance pattern");
  Serial.println("- 'reset': Return to 0mm");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command.startsWith("pos")) {
      float posMM = command.substring(4).toFloat();
      int posPulses = (int)(posMM * PULSE_PER_MM);
      dxl.setGoalPosition(DXL_ID, posPulses);
      Serial.print("Moving to ");
      Serial.print(posMM);
      Serial.println(" mm");
    }
    else if (command == "wave") {
      Serial.println("Waving...");
      for (int i = 0; i < 3; i++) {
        dxl.setGoalPosition(DXL_ID, (int)(50 * PULSE_PER_MM));  // 50mm
        delay(500);
        dxl.setGoalPosition(DXL_ID, (int)(30 * PULSE_PER_MM));  // 30mm
        delay(500);
      }
      Serial.println("Wave done");
    }
    else if (command == "dance") {
      Serial.println("Dancing...");
      for (int i = 0; i < 5; i++) {
        int randomPos = random(0, 100 * PULSE_PER_MM);  // 0-100mm
        dxl.setGoalPosition(DXL_ID, randomPos);
        delay(300);
      }
      Serial.println("Dance done");
    }
    else if (command == "reset") {
      dxl.setGoalPosition(DXL_ID, 0);
      Serial.println("Reset to 0mm");
    }
    else {
      Serial.println("Unknown command. Use: pos <mm>, wave, dance, reset");
    }
  }
}
