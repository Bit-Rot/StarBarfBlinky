#include "Effects.h"
#include "EffectUtils.h"

void Effects::rainbow(PixelStrip &pixelStrip, uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<pixelStrip.getNumPixels(); i++) {
      pixelStrip.getPixel(i)->setColor(EffectUtils::wheel((i+j) & 255));
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
      pixelStrip.getPixel(i)->setColor(EffectUtils::wheel(((i * 256 / pixelStrip.getNumPixels()) + j) & 255));
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
        pixelStrip.getPixel(i+q)->setColor(EffectUtils::wheel( (i+j) % 255));    //turn every third pixel on
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