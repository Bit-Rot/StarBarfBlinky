#include "MultiColorTwinkleEffect.h"
#include <util/delay.h>

MultiColorTwinkleEffect::MultiColorTwinkleEffect(PixelStrip &pixelStrip, int maxTwinkles, int minTwinkleTime, int maxTwinkleTime, int twinkleRate, uint32_t *colors, int numColors) :
  myNumTwinkles(0) {

  myTwinkleRate = twinkleRate;
  myPixelStrip = &pixelStrip;
  myMaxTwinkles = maxTwinkles;
  myMinTwinkleTime = minTwinkleTime;
  myMaxTwinkleTime = maxTwinkleTime;
  myColorPallette = new ColorPallette();
  myColorPallette->setColors(colors);
  myColorPallette->setNumColors(numColors);
}

MultiColorTwinkleEffect::~MultiColorTwinkleEffect() {
  delete myColorPallette;
}

void MultiColorTwinkleEffect::init(void) {
  myNumTwinkles = 0;
  for (int i=0; i < myPixelStrip->getNumPixels(); ++i) {
    Pixel *pixel = myPixelStrip->getPixel(i);
    pixel->setBrightness(0);
    pixel->setInitialBrightness(0);
    pixel->setDestinationBrightness(0);
    pixel->setColor(0);
    pixel->setInitialColor(0);
    pixel->setDestinationColor(0);
    pixel->changeState(TWINKLE_OFF);
    pixel->setTransitionDuration(0);
  }
}

void MultiColorTwinkleEffect::update(unsigned long delta) {
  if (myColorPallette->getNumColors() < 1) {
    return;
  }

  //Determine new twinkle, if any
  int twinklePos = -1;
  if (rand() % myTwinkleRate == 0 && myNumTwinkles < myMaxTwinkles) {
    twinklePos = rand() % myPixelStrip->getNumPixels();
    Pixel *pixel = myPixelStrip->getPixel(twinklePos);
    if (pixel->getState() == TWINKLE_OFF) {
      pixel->changeState(TWINKLE_IN);
      pixel->setDestinationBrightness(255);
      pixel->setTransitionDuration((rand() % (myMaxTwinkleTime - myMinTwinkleTime)) + myMinTwinkleTime);
      pixel->setColor(myColorPallette->getRandomColor());
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

void MultiColorTwinkleEffect::show(void) {
  myPixelStrip->show();
}
