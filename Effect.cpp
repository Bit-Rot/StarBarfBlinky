#include "Effect.h"

Effect::Effect(PixelStrip *pixelStrip) {
	//myPixelStrip = pixelStrip;
}

void Effect::clear() {
  for (int i=0; i < myPixelStrip->getNumPixels(); i++) {
    myPixelStrip->getPixel(i)->setColor(0);
    myPixelStrip->getPixel(i)->setBrightness(255);
  }
}