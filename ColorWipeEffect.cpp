#include "ColorWipeEffect.h"

ColorWipeEffect::ColorWipeEffect(PixelStrip* pixelStrip, uint32_t color, uint8_t wait)
	: Effect(pixelStrip) {
	myColor = color;
	myWaitTime = wait;
}

void ColorWipeEffect::init() {
	clear();
}

/*
 * Note, this is a really shitty implementation because we don't release
 * flow of logic between frames.  We should be able to easily improve this
 * by setting a total animation time on the effect and lerping the wipe
 * across the length of the strip over that duration based on the delta.
 */
void ColorWipeEffect::update(unsigned long delta) {
  for(int i=0; i < myPixelStrip->getNumPixels(); i++) {
    myPixelStrip->getPixel(i)->setColor(myColor);
    myPixelStrip->getPixel(i)->setBrightness(255);
    myPixelStrip->show();
    delay(myWaitTime);
  }
  clear();
}