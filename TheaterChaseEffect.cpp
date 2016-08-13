#include "TheaterChaseEffect.h"
#include "EffectUtils.h"

TheaterChaseEffect::TheaterChaseEffect(PixelStrip *pixelStrip, uint32_t color, uint32_t duration)
	: Effect(pixelStrip) {
	myDuration = duration;
  myCurrentTime = 0;
  myColor = color;
}

void TheaterChaseEffect::init(void) {
  Effect::init();
	clear();
  myCurrentTime = 0;
}

void TheaterChaseEffect::update(unsigned long delta) {
  myCurrentTime = (myCurrentTime + delta) % myDuration;
  double percent = (double)myCurrentTime / (double)myDuration;
  uint8_t position = (uint8_t)(percent * (3));

  clear();
  for (int i = 0; i < myPixelStrip->getNumPixels(); i = i + 3) {
    myPixelStrip->getPixel(i+position)->setColor(myColor);    //turn every third pixel on
  }
}