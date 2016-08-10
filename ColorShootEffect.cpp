#include "ColorShootEffect.h"

ColorShootEffect::ColorShootEffect(PixelStrip* pixelStrip, uint32_t color, uint32_t duration, boolean forward, uint8_t width)
	: Effect(pixelStrip) {
	myColor = color;
  myDuration = duration;
  myCurrentTime = 0;
  myForward = forward;
  myWidth = width;
}

void ColorShootEffect::init() {
	clear();
}

void ColorShootEffect::update(unsigned long delta) {
  myCurrentTime = (myCurrentTime + delta) % myDuration;
  double percent = (double)myCurrentTime / (double)myDuration;
  uint8_t position = (uint8_t)(percent * (myPixelStrip->getNumPixels() - 1));
  if (!myForward) {
    position = myPixelStrip->getNumPixels() - position - 1;
  }

  clear();
  for (int j=0; j < myWidth; j++) {
    myPixelStrip->getPixel((position+j) % myPixelStrip->getNumPixels())->setColor(myColor);
  }
}