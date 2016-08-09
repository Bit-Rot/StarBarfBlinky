#include "PatternShootEffect.h"

PatternShootEffect::PatternShootEffect(PixelStrip *pixelStrip, uint32_t *pattern, uint8_t patternLength, boolean forward, uint8_t wait)
	: Effect(pixelStrip) {
  myPattern = pattern;
  myPatternLength = patternLength;
	myWaitTime = wait;
  myForward = forward;
}

void PatternShootEffect::init() {
	clear();
}

/*
 * Note, this is a really shitty implementation because we don't release
 * flow of logic between frames.  We should be able to easily improve this
 * by setting a total animation time on the effect and lerping the wipe
 * across the length of the strip over that duration based on the delta.
 */
void PatternShootEffect::update(unsigned long delta) {
  int i = myForward? 0 : myPixelStrip->getNumPixels();
  while (i< myPixelStrip->getNumPixels()) {
    clear();
    for (int j=0; j < myPatternLength; j++) {
      //TODO: Pattern shows up backwards - fix
      myPixelStrip->getPixel((i+j) % myPixelStrip->getNumPixels())->setColor(myPattern[j]);
    }
    myPixelStrip->show();
    delay(myWaitTime);

    i = myForward? i+1 : i-1;
  }
}