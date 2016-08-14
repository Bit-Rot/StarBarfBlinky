#include "Effect.h"	

Effect::Effect(PixelStrip *pixelStrip) {
	myPixelStrip = pixelStrip;
  myConversionMethod = CONVERSION_METHOD_NONE;
}

void Effect::setConversionMethod(uint8_t conversionMethod) {
  myConversionMethod = conversionMethod;
}

void Effect::init() {
	if (myConversionMethod != CONVERSION_METHOD_NONE) {
	  myPixelStrip->setConversionMethod(myConversionMethod);
	}
}

void Effect::clear() {
  for (int i=0; i < myPixelStrip->getNumPixels(); i++) {
    myPixelStrip->getPixel(i)->setColor(0);
    myPixelStrip->getPixel(i)->setBrightness(255);
  }
}