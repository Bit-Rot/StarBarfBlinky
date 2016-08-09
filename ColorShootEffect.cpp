#include "ColorShootEffect.h"

ColorShootEffect::ColorShootEffect(PixelStrip* pixelStrip, uint32_t color, uint8_t wait, boolean forward, uint8_t width)
	: Effect(pixelStrip) {
	myColor = color;
	myWaitTime = wait;
  myForward = forward;
  myWidth = width;
}

void ColorShootEffect::init() {
	clear();
}

/*
 * Note, this is a really shitty implementation because we don't release
 * flow of logic between frames.  We should be able to easily improve this
 * by setting a total animation time on the effect and lerping the wipe
 * across the length of the strip over that duration based on the delta.
 */
void ColorShootEffect::update(unsigned long delta) {
  int i = myForward? 0 : (myPixelStrip->getNumPixels() - 1);
  while (myForward? (i < myPixelStrip->getNumPixels()) : (i > 0)) {
    clear();
    for (int j=0; j < myWidth; j++) {
      myPixelStrip->getPixel((i+j) % myPixelStrip->getNumPixels())->setColor(myColor);
    }
    myPixelStrip->show();
    delay(myWaitTime);

    i = myForward? (i+1) : (i-1);
  }
}