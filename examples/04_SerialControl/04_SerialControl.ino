/*
 * SerialControl.ino
 * Purpose: Introduce Serial communication for command and control.
 * Hardware: OpenRB-150 (no servo needed yet).
 * Learning Goals:
 * - Send commands via Serial Monitor.
 * - Parse simple text input.
 * - Control LED based on commands.
 */

#include <Arduino.h>

#define LED_PIN 13

void setup() {
  Serial.begin(115200);
  while (!Serial);
  
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Serial Control Demo");
  Serial.println("Commands: 'on' (LED on), 'off' (LED off), 'blink' (blink LED)");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');  // Read input until newline
    command.trim();  // Remove whitespace

    if (command == "on") {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED ON");
    } 
    else if (command == "off") {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED OFF");
    } 
    else if (command == "blink") {
      Serial.println("Blinking...");
      for (int i = 0; i < 5; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(200);
        digitalWrite(LED_PIN, LOW);
        delay(200);
      }
      Serial.println("Blink done");
    } 
    else {
      Serial.println("Unknown command. Use: on, off, blink");
    }
  }
}
