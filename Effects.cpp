#include "Effects.h"

void Effects::clear(PixelStrip &pixelStrip) {
  for (int i=0; i < pixelStrip.getNumPixels(); i++) {
    pixelStrip.getPixel(i)->setColor(0);
    pixelStrip.getPixel(i)->setBrightness(255);
  }
}

void Effects::colorWipe(PixelStrip &pixelStrip, uint32_t c, uint8_t wait) {
  for(int i=0; i< pixelStrip.getNumPixels(); i++) {
    pixelStrip.getPixel(i)->setColor(c);
    pixelStrip.getPixel(i)->setBrightness(255);
    pixelStrip.show();
    delay(wait);
  }
}

void Effects::colorShoot(PixelStrip &pixelStrip, uint32_t c, uint8_t width, boolean forward, uint8_t wait) {
  int i = forward? 0 : (pixelStrip.getNumPixels() - 1);
  while (forward? (i < pixelStrip.getNumPixels()) : (i > 0)) {
    clear(pixelStrip);
    for (int j=0; j < width; j++) {
      pixelStrip.getPixel((i+j) % pixelStrip.getNumPixels())->setColor(c);
    }
    pixelStrip.show();
    delay(wait);

    i = forward? (i+1) : (i-1);
  }
}

void Effects::patternShoot(PixelStrip &pixelStrip, uint32_t *pattern, uint8_t patternLength, boolean forward, uint8_t wait) {
  int i = forward? 0 : pixelStrip.getNumPixels();
  while (i< pixelStrip.getNumPixels()) {
    clear(pixelStrip);
    for (int j=0; j < patternLength; j++) {
      pixelStrip.getPixel((i+j) % pixelStrip.getNumPixels())->setColor(pattern[j]);
    }
    pixelStrip.show();
    delay(wait);

    i = forward? i+1 : i-1;
  }
}

void Effects::rainbow(PixelStrip &pixelStrip, uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<pixelStrip.getNumPixels(); i++) {
      pixelStrip.getPixel(i)->setColor(Wheel((i+j) & 255));
      pixelStrip.getPixel(i)->setBrightness(255);
    }
    pixelStrip.show();
    delay(wait);
  }
}

void Effects::rainbowCycle(PixelStrip &pixelStrip, uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i< pixelStrip.getNumPixels(); i++) {
      pixelStrip.getPixel(i)->setColor(Wheel(((i * 256 / pixelStrip.getNumPixels()) + j) & 255));
      pixelStrip.getPixel(i)->setBrightness(255);
    }
    pixelStrip.show();
    delay(wait);
  }
}

void Effects::theaterChase(PixelStrip &pixelStrip, uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < pixelStrip.getNumPixels(); i=i+3) {
        pixelStrip.getPixel(i+q)->setColor(c);    //turn every third pixel on
        pixelStrip.getPixel(i+q)->setBrightness(255);
      }
      pixelStrip.show();

      delay(wait);

      for (int i=0; i < pixelStrip.getNumPixels(); i=i+3) {
        pixelStrip.getPixel(i+q)->setColor(0);        //turn every third pixel off
        pixelStrip.getPixel(i+q)->setBrightness(255);
      }
    }
  }
}

void Effects::theaterChaseRainbow(PixelStrip &pixelStrip, uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < pixelStrip.getNumPixels(); i=i+3) {
        pixelStrip.getPixel(i+q)->setColor(Wheel( (i+j) % 255));    //turn every third pixel on
        pixelStrip.getPixel(i+q)->setBrightness(255);
      }
      pixelStrip.show();

      delay(wait);

      for (int i=0; i < pixelStrip.getNumPixels(); i=i+3) {
        pixelStrip.getPixel(i+q)->setColor(0);        //turn every third pixel off
        pixelStrip.getPixel(i+q)->setBrightness(255);
      }
    }
  }
}

uint32_t Effects::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return Adafruit_NeoPixel::Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return Adafruit_NeoPixel::Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return Adafruit_NeoPixel::Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

uint32_t Effects::colorBlend(uint32_t color1, uint32_t color2, uint8_t percent) {
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