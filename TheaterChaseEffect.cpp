#include "TheaterChaseEffect.h"
#include "EffectUtils.h"

TheaterChaseEffect::TheaterChaseEffect(PixelStrip *pixelStrip, uint32_t color, uint8_t wait)
	: Effect(pixelStrip) {
	myWaitTime = wait;
  myColor = color;
}

void TheaterChaseEffect::init(void) {
	clear();
}

void TheaterChaseEffect::update(unsigned long delta) {

  for (int j = 0; j < 10; j++) {  //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < myPixelStrip->getNumPixels(); i = i + 3) {
        myPixelStrip->getPixel(i+q)->setColor(myColor);    //turn every third pixel on
        myPixelStrip->getPixel(i+q)->setBrightness(255);
      }
      myPixelStrip->show();

      delay(myWaitTime);

      for (int i=0; i < myPixelStrip->getNumPixels(); i = i + 3) {
        myPixelStrip->getPixel(i+q)->setColor(0);        //turn every third pixel off
        myPixelStrip->getPixel(i+q)->setBrightness(255);
      }
    }
  }
}