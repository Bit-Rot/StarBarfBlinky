#include "ColorSoupEffect.h"
#include "Effects.h"
#include <util/delay.h>

ColorSoupEffect::ColorSoupEffect(PixelStrip *pixelStrip, uint32_t *colors, uint8_t numColors, int minTwinkleTime, int maxTwinkleTime)
  : Effect(pixelStrip) {
  myColorPallette = new ColorPallette();
  myColorPallette->setColors(colors);
  myColorPallette->setNumColors(numColors);
  myNumTwinkles = 0;
  myMinTwinkleTime = minTwinkleTime;
  myMaxTwinkleTime = maxTwinkleTime;
}

void ColorSoupEffect::init(void) {
  myNumTwinkles = 0;
  for (int i=0; i < myPixelStrip->getNumPixels(); ++i) {
    Pixel *pixel = myPixelStrip->getPixel(i);
    /*
    pixel->setBrightness(255);
    pixel->setColor(0xffffff);
    pixel->transition(255, 
      myColorPallette->getRandomColor(), 
      (rand() % (myMaxTwinkleTime - myMinTwinkleTime)) + myMinTwinkleTime);
    pixel->changeState(TWINKLE_IN);
    /**/

    /**/
    pixel->setInitialColor(0);
    pixel->setColor(0);
    pixel->setDestinationColor(0x0000ff);
    pixel->setInitialBrightness(255);
    pixel->setBrightness(255);
    pixel->setDestinationBrightness(255);
    pixel->changeState(TWINKLE_IN);
    /**/
  }
}

void ColorSoupEffect::update(unsigned long delta) {
  if (myColorPallette->getNumColors() < 1) {
    return;
  }

  //Re-calculate pixel values
  for (int i=0; i < myPixelStrip->getNumPixels(); ++i) {
    Pixel *pixel = myPixelStrip->getPixel(i);
    pixel->setTimeInState(pixel->getTimeInState() + delta);

    //Set pixel on if twinklePos matches and not already on
    boolean stateComplete = pixel->getTimeInState() >= pixel->getTransitionDuration();

    if (!stateComplete) {

      /*
      uint32_t startRed = myPixelStrip->getRed(pixel->getInitialColor());
      uint32_t endRed = myPixelStrip->getRed(pixel->getDestinationColor());
      uint32_t newRed = startRed + ((endRed - startRed) * pixel->getTimeInState() / pixel->getTransitionDuration());

      uint32_t startGreen = myPixelStrip->getGreen(pixel->getInitialColor());
      uint32_t endGreen = myPixelStrip->getGreen(pixel->getDestinationColor());
      uint32_t newGreen = startGreen + ((endGreen - startGreen) * pixel->getTimeInState() / pixel->getTransitionDuration());

      uint32_t startBlue = myPixelStrip->getBlue(pixel->getInitialColor());
      uint32_t endBlue = myPixelStrip->getBlue(pixel->getDestinationColor());
      uint32_t newBlue = startBlue + ((endBlue - startBlue) * pixel->getTimeInState() / pixel->getTransitionDuration());
      /**/

      /*
      uint8_t *init = (uint8_t*)&(pixel->getInitialColor());
      uint8_t *dest = (uint8_t*)&(pixel->getDestinationColor());
      /**/

      /*
      uint32_t startRed = *init[0];
      uint32_t endRed = myPixelStrip->getRed(pixel->getDestinationColor());
      uint32_t newRed = startRed + ((endRed - startRed) * pixel->getTimeInState() / pixel->getTransitionDuration());

      uint32_t startGreen = myPixelStrip->getGreen(pixel->getInitialColor());
      uint32_t endGreen = myPixelStrip->getGreen(pixel->getDestinationColor());
      uint32_t newGreen = startGreen + ((endGreen - startGreen) * pixel->getTimeInState() / pixel->getTransitionDuration());

      uint32_t startBlue = myPixelStrip->getBlue(pixel->getInitialColor());
      uint32_t endBlue = myPixelStrip->getBlue(pixel->getDestinationColor());
      uint32_t newBlue = startBlue + ((endBlue - startBlue) * pixel->getTimeInState() / pixel->getTransitionDuration());
      /**/

      /**/
//      uint32_t startRed = (pixel->getInitialColor() & 0xff0000);
//      startRed = startRed >> 16;
//      uint32_t endRed = (pixel->getDestinationColor() & 0xff0000);
//      uint8_t newRed = startRed + ((endRed - startRed) * pixel->getTimeInState() / pixel->getTransitionDuration());
//      uint8_t newBlue = 0;
//      uint8_t newGreen = 0;
      /**/

      /*
      uint32_t startBlue = (pixel->getInitialColor() & 0x00ff00);
      uint32_t endBlue = (pixel->getDestinationColor() & 0x00ff00);
      startBlue = startBlue >> 8;
      uint32_t newBlue = startBlue + ((endBlue - startBlue) * pixel->getTimeInState() / pixel->getTransitionDuration());

      uint32_t startGreen = (pixel->getInitialColor() & 0x0000ff);
      uint32_t endGreen = (pixel->getDestinationColor() & 0x0000ff);
      uint32_t newGreen = startGreen + ((endGreen - startGreen) * pixel->getTimeInState() / pixel->getTransitionDuration());
      /**/

      /*
      uint32_t newColor = Adafruit_NeoPixel::Color(newRed, newGreen, newBlue);
      pixel->setColor(newColor);
      /**/

      /**/
      Effects::colorBlend(pixel->getInitialColor(), pixel->getDestinationColor(), pixel->getTimeInState() / pixel->getTransitionDuration());
      /**/

    } else {
      /*
      pixel->setInitialColor(0);
      pixel->setColor(0);
      pixel->setDestinationColor(Adafruit_NeoPixel::Color(255, 0, 0));
      pixel->setTransitionDuration(2000);
      pixel->changeState(TWINKLE_IN);
      /**/

      /**/
      pixel->changeState(TWINKLE_IN);
      pixel->transition(255, 
        myColorPallette->getRandomColor(), 
        20000);
//        (rand() % (myMaxTwinkleTime - myMinTwinkleTime)) + myMinTwinkleTime);
      /**/
    }
  }
}
