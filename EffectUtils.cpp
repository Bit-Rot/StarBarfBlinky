#include "EffectUtils.h"

uint32_t EffectUtils::wheel(byte wheelPos) {
  wheelPos = 255 - wheelPos;
  if(wheelPos < 85) {
    return Adafruit_NeoPixel::Color(255 - wheelPos * 3, 0, wheelPos * 3);
  }
  if(wheelPos < 170) {
    wheelPos -= 85;
    return Adafruit_NeoPixel::Color(0, wheelPos * 3, 255 - wheelPos * 3);
  }
  wheelPos -= 170;
  return Adafruit_NeoPixel::Color(wheelPos * 3, 255 - wheelPos * 3, 0);
}

uint32_t EffectUtils::colorBlend(uint32_t color1, uint32_t color2, uint8_t percent) {
  uint32_t startRed = (color1 & (uint32_t)0xff0000) >> 16;
  uint32_t endRed = (color2 & (uint32_t)0xff0000) >> 16;
  uint32_t startGreen = (color1 & (uint32_t)0x00ff00) >> 8;
  uint32_t endGreen = (color2 & (uint32_t)0x00ff00) >> 8;
  uint32_t startBlue = color1 & (uint32_t)0x0000ff;
  uint32_t endBlue = color2 & (uint32_t)0x0000ff;
  uint32_t red = startRed * (uint32_t)percent / (uint32_t)100;
  red += endRed * (uint32_t)percent / (uint32_t)100;
  uint32_t green = startGreen * (uint32_t)percent / (uint32_t)100;
  green += endGreen * (uint32_t)percent / (uint32_t)100;
  uint32_t blue = startBlue * (uint32_t)percent / (uint32_t)100;
  blue += endBlue * (uint32_t)percent / (uint32_t)100;
  return ((uint32_t)red << 16) | ((uint32_t)green << 8) | (uint32_t)blue;
}