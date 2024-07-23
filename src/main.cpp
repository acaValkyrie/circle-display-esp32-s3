// #include <Arduino.h>
#include <LovyanGFX.hpp>
#include "lgfx.hpp"

static WaveshareRoundLCD lcd;
static LGFX_Sprite sprite(&lcd);

void setup() {
  neopixelWrite(48, 0, 0, 0);
  lcd.init();
  sprite.createSprite(lcd.width(), lcd.height());
}

void loop() {
  sprite.startWrite();
  sprite.fillCircle(lcd.width()*0.5, lcd.height()*0.5, 30, lcd.color888(255,0,0));
  sprite.printf("Hello, World!");
  sprite.endWrite();
  sprite.pushSprite(&lcd, 0, 0);
  delay(500);
}
