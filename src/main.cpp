// #include <Arduino.h>
#include <LovyanGFX.hpp>
#include "lgfx.hpp"

static WaveshareRoundLCD lcd;
static LGFX_Sprite sprite(&lcd);

const int star_num = 50;
static int star_x[star_num];
static int star_y[star_num];
static int star_r[star_num];
static int star_t[star_num];
static float star_color_r[star_num];
static float star_color_g[star_num];
static float star_color_b[star_num];
static int star_blink_speed[star_num];

void setup() {
  neopixelWrite(48, 0, 0, 0);
  lcd.init();
  sprite.createSprite(lcd.width(), lcd.height());
  
  for(int i = 0; i < star_num; i++){
    star_x[i] = random(lcd.width());
    star_y[i] = random(lcd.height());
    star_r[i] = random(1, 4);
    star_t[i] = random(0, 360);
    star_color_r[i] = random(0, 10)/10.0;
    star_color_g[i] = random(0, 3)/10.0;
    star_color_b[i] = random(0, 10)/10.0;
    star_blink_speed[i] = random(1, 10);
  }
}

void loop() {
  sprite.startWrite();
  for(int i = 0; i < star_num; i++){
    int x = star_x[i];
    int y = star_y[i];
    int radius = star_r[i];
    int t = star_t[i];

    int luminus = 127*(sin(t/180.0*PI)+1);
    int r = star_color_r[i]*luminus;
    int g = star_color_g[i]*luminus;
    int b = star_color_b[i]*luminus;
    uint32_t color = lcd.color888(r,g,b);

    sprite.fillCircle(x, y, radius, color);
  }
  sprite.endWrite();
  sprite.pushSprite(&lcd, 0, 0);
  
  for(int i = 0; i < star_num; i++){
    star_t[i] = (star_t[i] + star_blink_speed[i]) % 360;
  }
  delay(30);
}
