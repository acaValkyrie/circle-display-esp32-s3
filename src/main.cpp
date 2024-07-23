// #include <Arduino.h>
#include <LovyanGFX.hpp>
#include "lgfx.hpp"

WaveshareRoundLCD lcd;

void setup() {
  lcd.init();
  // lcd.setRotation(3);
  lcd.fillScreen(lcd.color888(255,0,255));
  lcd.fillCircle(lcd.width()*0.5, lcd.height()*0.5, 30, lcd.color888(255,0,0));
  lcd.printf("Hello, World!");
  // lcd.setBrightness(255);
  // pinMode(48, OUTPUT);
  neopixelWrite(48, 0, 0, 0);
}

void loop() {
  lcd.startWrite();
  lcd.fillCircle(lcd.width()*0.5, lcd.height()*0.5, 30, lcd.color888(255,0,0));
  lcd.printf("Hello, World!");
  lcd.endWrite();
  delay(500);
}
