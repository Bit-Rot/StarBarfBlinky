#include "PatternShootEffect.h"

PatternShootEffect::PatternShootEffect(PixelStrip *pixelStrip, uint32_t *pattern, uint8_t patternLength, uint32_t duration, boolean forward)
	: Effect(pixelStrip) {
  myPattern = pattern;
  myPatternLength = patternLength;
	myDuration = duration;
  myCurrentTime = 0;
  myForward = forward;
}

void PatternShootEffect::init() {
	clear();
  myCurrentTime = 0;
}

void PatternShootEffect::update(unsigned long delta) {
  myCurrentTime = (myCurrentTime + delta) % myDuration;
  double percent = (double)myCurrentTime / (double)myDuration;
  uint8_t position = (uint8_t)(percent * (myPixelStrip->getNumPixels() - 1));
  if (!myForward) {
    position = myPixelStrip->getNumPixels() - position - 1;
  }

  clear();
  for (int j=0; j < myPatternLength; j++) {
    //TODO: Pattern shows up backwards - fix
    myPixelStrip->getPixel((position+j) % myPixelStrip->getNumPixels())->setColor(myPattern[j]);
  }
}