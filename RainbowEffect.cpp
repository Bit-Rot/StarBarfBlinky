#include "RainbowEffect.h"
#include "EffectUtils.h"

RainbowEffect::RainbowEffect(PixelStrip *pixelStrip, uint8_t mode, uint32_t duration)
	: Effect(pixelStrip) {
	myDuration = duration;
  myMode = mode;
}

void RainbowEffect::init(void) {
  Effect::init();
	clear();
  myCurrentTime = 0;
}

void RainbowEffect::update(unsigned long delta) {
  myCurrentTime = (myCurrentTime + delta) % myDuration;
  double percent = (double)myCurrentTime / (double)myDuration;
  uint8_t position = (uint8_t)(percent * (255));

  uint16_t i;
  for(i = 0; i < myPixelStrip->getNumPixels(); i++) {
    uint8_t value = (myMode == RAINBOW_EFFECT_MODE_NORMAL)?
      (i+position) & 255 :
      ((i * 256 / myPixelStrip->getNumPixels()) + position) & 255;
    myPixelStrip->getPixel(i)->setColor(EffectUtils::wheel(value));
    myPixelStrip->getPixel(i)->setBrightness(255);
  }
}