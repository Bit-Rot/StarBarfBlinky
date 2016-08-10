#include "ColorWipeEffect.h"

ColorWipeEffect::ColorWipeEffect(PixelStrip* pixelStrip, uint32_t color, uint32_t duration)
	: Effect(pixelStrip) {
	myColor = color;
  myDuration = duration;
  myCurrentTime = 0;
}

void ColorWipeEffect::init() {
	clear();
  myCurrentTime = 0;
}

void ColorWipeEffect::update(unsigned long delta) {
  uint32_t myPreviousTime = myCurrentTime;
  myCurrentTime = (myCurrentTime + delta) % myDuration;
  double percent = (double)myCurrentTime / (double)myDuration;
  uint8_t position = (uint8_t)(percent * (myPixelStrip->getNumPixels() - 1));

  if (myPreviousTime > myCurrentTime) {
    clear();
  }

  myPixelStrip->getPixel(position)->setColor(myColor);
  myPixelStrip->getPixel(position)->setBrightness(255);
  myPixelStrip->show();
}