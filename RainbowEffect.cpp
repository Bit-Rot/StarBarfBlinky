#include "RainbowEffect.h"
#include "EffectUtils.h"

RainbowEffect::RainbowEffect(PixelStrip *pixelStrip, uint8_t mode, uint8_t wait)
	: Effect(pixelStrip) {
	myWaitTime = wait;
  myMode = mode;
}

void RainbowEffect::init(void) {
	clear();
}

void RainbowEffect::update(unsigned long delta) {
  uint16_t i, j;
  for(j = 0; j < 256; j++) {
    for(i = 0; i < myPixelStrip->getNumPixels(); i++) {
      uint8_t value = (myMode == RAINBOW_EFFECT_MODE_NORMAL)? 
        (i+j) & 255 : 
        ((i * 256 / myPixelStrip->getNumPixels()) + j) & 255;
      myPixelStrip->getPixel(i)->setColor(EffectUtils::wheel(value));
      myPixelStrip->getPixel(i)->setBrightness(255);
    }
    myPixelStrip->show();
    delay(myWaitTime);
  }
}