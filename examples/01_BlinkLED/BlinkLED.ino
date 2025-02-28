/*
 * BlinkLED.ino
 * Purpose: Introduce basic Arduino concepts by blinking the onboard LED.
 * Hardware: OpenRB-150 Starter Kit (no servo needed yet).
 * Learning Goals:
 * - Understand setup() and loop() functions.
 * - Use digital output to control an LED.
 * - Learn basic timing with delay().
 */

#include <Arduino.h>

#define LED_PIN 1

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // Turn LED on
  delay(1000);                  // Wait 1 second
  digitalWrite(LED_PIN, LOW);   // Turn LED off
  delay(1000);                  // Wait 1 second
}
