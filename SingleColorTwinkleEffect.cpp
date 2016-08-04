#include "SingleColorTwinkleEffect.h"
#include <util/delay.h>

SingleColorTwinkleEffect::SingleColorTwinkleEffect(PixelStrip &pixelStrip, uint32_t color, int maxTwinkles, int minTwinkleTime, int maxTwinkleTime, int twinkleRate) :
  myNumTwinkles(0) {

  myTwinkleRate = twinkleRate;
  myColor = color;
  myPixelStrip = &pixelStrip;
  myMaxTwinkles = maxTwinkles;
  myMinTwinkleTime = minTwinkleTime;
  myMaxTwinkleTime = maxTwinkleTime;
}

SingleColorTwinkleEffect::~SingleColorTwinkleEffect() {}

void SingleColorTwinkleEffect::init(void) {
  myNumTwinkles = 0;
  for (int i=0; i < myPixelStrip->getNumPixels(); ++i) {
    Pixel *pixel = myPixelStrip->getPixel(i);
    pixel->setBrightness(0);
    pixel->setInitialBrightness(0);
    pixel->setDestinationBrightness(0);
    pixel->setColor(myColor);
    pixel->setInitialColor(myColor);
    pixel->setDestinationColor(myColor);
    pixel->changeState(TWINKLE_OFF);
    pixel->setTransitionDuration(0);
  }
}

void SingleColorTwinkleEffect::update(unsigned long delta) {

  //Determine new twinkle, if any
  int twinklePos = -1;
  if (rand() % myTwinkleRate == 0 && myNumTwinkles < myMaxTwinkles) {
    twinklePos = rand() % myPixelStrip->getNumPixels();
    Pixel *pixel = myPixelStrip->getPixel(twinklePos);
    if (pixel->getState() == TWINKLE_OFF) {
      pixel->changeState(TWINKLE_IN);
      pixel->setDestinationBrightness(255);
      pixel->setTransitionDuration((rand() % (myMaxTwinkleTime - myMinTwinkleTime)) + myMinTwinkleTime);
      ++myNumTwinkles;
    }
  }

  //Re-calculate pixel values
  for (int i=0; i < myPixelStrip->getNumPixels(); ++i) {
    Pixel *pixel = myPixelStrip->getPixel(i);
    pixel->setTimeInState(pixel->getTimeInState() + delta);

    //Set pixel on if twinklePos matches and not already on
    boolean stateComplete = pixel->getTimeInState() >= pixel->getTransitionDuration();
    switch(pixel->getState()) {
    case TWINKLE_IN:
      if (!stateComplete) {
        int newBrightness = pixel->getDestinationBrightness() * pixel->getTimeInState() / pixel->getTransitionDuration();
        pixel->setBrightness(newBrightness);
      } else {
        pixel->changeState(TWINKLE_OUT);
      }
      break;
    case TWINKLE_OUT:

      if (!stateComplete) {
        int newBrightness = pixel->getDestinationBrightness() - (pixel->getDestinationBrightness() * pixel->getTimeInState() / pixel->getTransitionDuration());
        pixel->setBrightness(newBrightness);
      } else {
        pixel->setBrightness(0);
        pixel->setDestinationBrightness(0);
        pixel->setTransitionDuration(0);
        pixel->changeState(TWINKLE_OFF);
        --myNumTwinkles;
      }
      break;
    }
  }
}

void SingleColorTwinkleEffect::show(void) {
  myPixelStrip->show();
}
