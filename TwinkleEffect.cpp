#include "TwinkleEffect.h"
#include <util/delay.h>

TwinkleEffect::TwinkleEffect(PixelStrip &pixelStrip, int twinkleMode, int maxTwinkles, int minTwinkleTime, int maxTwinkleTime) :
  myNumTwinkles(0) {

  myPixelStrip = &pixelStrip;
  myMaxTwinkles = maxTwinkles;
  myMinTwinkleTime = minTwinkleTime;
  myMaxTwinkleTime = maxTwinkleTime;
}

TwinkleEffect::~TwinkleEffect() {}

void TwinkleEffect::init(void) {
  for (int i=0; i < myPixelStrip->getNumPixels(); ++i) {
    Pixel *pixel = myPixelStrip->getPixel(i);
    pixel->setBrightness(0);
    pixel->setDestinationBrightness(0);
    pixel->setColor(0xffffff);
    pixel->setDestinationColor(0xffffff);
    pixel->changeState(TWINKLE_OFF);
    pixel->setTransitionDuration(0);
  }
}

void TwinkleEffect::update(unsigned long delta) {

/*
*/
    int twinklePos = rand() % (myPixelStrip->getNumPixels() - 1);
    myPixelStrip->getPixel(twinklePos)->setColor(0xffffff);
    myPixelStrip->getPixel(twinklePos)->setBrightness(255);
    myPixelStrip->show();
    _delay_ms(1000);
    myPixelStrip->getPixel(twinklePos)->setColor(0x000000);
    myPixelStrip->getPixel(twinklePos)->setBrightness(0);
    myPixelStrip->show();
    _delay_ms(1000);

//  this->brightnessOnlyTwinkle(delta);

  switch(myTwinkleMode) {
//    case TWINKLE_MODE_SIN:
//      this->updateSin(delta);
//      break;
    default:
      this->updateLinear(delta);
      break;
  }
}

void TwinkleEffect::updateLinear(unsigned long delta) {

/*
	int twinklePos = rand() % (myPixelStrip->getNumPixels() - 1);
	Pixel *pixel = myPixelStrip->getPixel(twinklePos);
	if (pixel->getState() == TWINKLE_OFF) {
	    pixel->setColor(0xffffff);
	    myPixelStrip->show();
	    _delay_ms(1000);
	    pixel->changeState(TWINKLE_ON);
	} else if (pixel->getState() == TWINKLE_ON) {
		pixel->setColor(0x0000ff);
	    myPixelStrip->show();
	    _delay_ms(1000);
	    pixel->changeState(TWINKLE_OUT);
	} else {
	    pixel->setColor(0);
	    myPixelStrip->show();
	    _delay_ms(1000);
	    pixel->changeState(TWINKLE_OFF);
	}
*/

  /* THIS CODE WORKS
  int twinklePos = -1;
	if (rand() % 100 == 0 && myNumTwinkles < myMaxTwinkles) {
		twinklePos = rand() % (myPixelStrip->getNumPixels() - 1);
		Pixel *pixel = myPixelStrip->getPixel(twinklePos);
		if (pixel->getState() == TWINKLE_OFF) {
	    pixel->setColor(0xff);
		  pixel->setBrightness(255);
      pixel->changeState(TWINKLE_ON);
      ++myNumTwinkles;
		}
	}

	for (int i=0; i < myPixelStrip->getNumPixels(); ++i) {
		Pixel *pixel = myPixelStrip->getPixel(i);
		if (pixel->getState() == TWINKLE_ON && pixel->getBrightness() > 0) {
			pixel->setBrightness(pixel->getBrightness() - 1);
			if (pixel->getBrightness() == 0) {
				pixel->changeState(TWINKLE_OFF);
        --myNumTwinkles;
			}
		}
	}
  */
}

/**
 * Twinkles random white pixels
 */
void TwinkleEffect::brightnessOnlyTwinkle(unsigned long delta) {
  //Rate at which new twinkles appear.  Lower is faster.
  int twinkleRate = 100;

  //Determine new twinkle, if any
  int twinklePos = -1;
  if (rand() % twinkleRate == 0 && myNumTwinkles < myMaxTwinkles) {
    twinklePos = rand() % (myPixelStrip->getNumPixels() - 1);
    Pixel *pixel = myPixelStrip->getPixel(twinklePos);
    if (pixel->getState() == TWINKLE_OFF) {
      pixel->changeState(TWINKLE_IN);
      ++myNumTwinkles;
    }
  }

  //Re-calculate pixel values
  for (int i=0; i < myPixelStrip->getNumPixels(); ++i) {
    Pixel *pixel = myPixelStrip->getPixel(i);

    //Set pixel on if twinklePos matches and not already on
    switch(pixel->getState()) {
    case TWINKLE_OFF:
      //Nothing to do here
      break;
    case TWINKLE_IN:
    case TWINKLE_OUT:
        boolean stateComplete = true;
        int brightnessDelta = pixel->getDestinationBrightness() - pixel->getBrightness();
        if (brightnessDelta != 0) {
          stateComplete = false;
          if (brightnessDelta < 0) {
            pixel->setBrightness(pixel->getBrightness() - 1);
          } else {
            pixel->setBrightness(pixel->getBrightness() + 1);
          }
        }

        if (stateComplete) {
          if (pixel->getState() == TWINKLE_IN) {
            pixel->changeState(TWINKLE_OUT);
          } else {
            pixel->changeState(TWINKLE_OFF);
            --myNumTwinkles;
          }
        }
      break;
    }
  }
}

/**
 * Twinkles random pixels, choosing a color from the color pallette
 */
void TwinkleEffect::randomColorTwinkle(unsigned long delta) {
  if (myColorPalletteLength < 1) {
    return;
  }

  //Determine new twinkle, if any
  int twinklePos = -1;
  if (rand() % 100 == 0 && myNumTwinkles < myMaxTwinkles) {
    //get pixel to twinkle
    twinklePos = rand() % (myPixelStrip->getNumPixels() - 1);
    Pixel *pixel = myPixelStrip->getPixel(twinklePos);

    //get color to twinkle
    int twinkleColor = myColorPallette[rand() % myColorPalletteLength];

    //start twinkle
    if (pixel->getState() == TWINKLE_OFF) {
      pixel->changeState(TWINKLE_IN);
      pixel->setColor(twinkleColor);
      ++myNumTwinkles;
    }
  }

  //Re-calculate pixel values
  for (int i=0; i < myPixelStrip->getNumPixels(); ++i) {
    Pixel *pixel = myPixelStrip->getPixel(i);

    //Set pixel on if twinklePos matches and not already on
    switch(pixel->getState()) {
    case TWINKLE_OFF:
      //Nothing to do here
      break;
    case TWINKLE_IN:
    case TWINKLE_OUT:
        boolean stateComplete = true;
        int brightnessDelta = pixel->getDestinationBrightness() - pixel->getBrightness();
        if (brightnessDelta != 0) {
          stateComplete = false;
          if (brightnessDelta < 0) {
            pixel->setBrightness(pixel->getBrightness() - 1);
          } else {
            pixel->setBrightness(pixel->getBrightness() + 1);
          }
        }

        if (stateComplete) {
          if (pixel->getState() == TWINKLE_IN) {
            pixel->changeState(TWINKLE_OUT);
          } else {
            pixel->changeState(TWINKLE_OFF);
            --myNumTwinkles;
          }
        }
      break;
    }
  }
}

/**
 * Twinkles random pixels, choosing a color from the color pallette.  Pixels are always on, and 
 * simply transition from one color to another.
 */
void TwinkleEffect::multiColorTwinkle(unsigned long delta) {
  if (myColorPalletteLength < 1) {
    return;
  }

  //Re-calculate pixel values
  for (int i=0; i < myPixelStrip->getNumPixels(); ++i) {
    Pixel *pixel = myPixelStrip->getPixel(i);
    int twinkleColor = 0;
    
    //Set pixel on if twinklePos matches and not already on
    switch(pixel->getState()) {
    case TWINKLE_OFF:
      //Start new twinkle
      twinkleColor = myColorPallette[rand() % myColorPalletteLength];
      pixel->setDestinationColor(twinkleColor);
      pixel->changeState(TWINKLE_IN);
      break;
    case TWINKLE_IN:
        boolean stateComplete = true;
        int brightnessDelta = pixel->getDestinationBrightness() - pixel->getBrightness();
        if (brightnessDelta != 0) {
          stateComplete = false;
          if (brightnessDelta < 0) {
            pixel->setBrightness(pixel->getBrightness() - 1);
          } else {
            pixel->setBrightness(pixel->getBrightness() + 1);
          }
        }

        if (stateComplete) {
          if (pixel->getState() == TWINKLE_IN) {
            pixel->changeState(TWINKLE_OUT);
          } else {
            pixel->changeState(TWINKLE_OFF);
            --myNumTwinkles;
          }
        }
      break;
    }
  }
}

/*
void Twinkle::updateSin(unsigned long delta) {

  //Determine new twinkle, if any
  int twinklePos = -1;
  if (myNumTwinkles < myMaxTwinkles) {
    twinklePos = Math.floor(Math.rand(0, myPixelStrip->getNumPixels() - 1));
  }

  //Re-calculate pixel values
  for (int i=0; i < myPixelStrip->getNumPixels(); ++i) {
    Pixel *pixel = myPixelStrip->getPixel(i);

    //Set pixel on if twinklePos matches and not already on
    switch(pixel->getState()) {
    case TWINKLE_OFF:
      if (twinklePos == i) {
        pixel->changeState(TWINKLE_IN);
        //pixel->setDestinationBrightness(255);
        pixel->setDestinationColor(0xffffff);
        //pixel->setTransitionDuration(Math.floor(Math.rand(myMinTwinkleTime, myMaxTwinkleTime)));
        pixel->setTransitionDuration(2000);
      }
      break;
    case TWINKLE_ON:
        boolean stateComplete = true;
        int brightness = pixel->getColor() | 0xff;
        int destinationBrightness = pixel->getDestinationColor() | 0xff;
        int brightnessDelta = destinationBrightness - brightness;
        //int brightnessDelta = pixel->getDestinationBrightness() - pixel->getBrightness();
        if (brightnessDelta != 0) {
          stateComplete = false;
          if (brightnessDelta < 0) {
            brightness -= 1;
          } else {
            brightness += 1;
          }
          pixel->setBrightness(Adafruit_NeoPixel.Color(brightness, brightness, Brightness));
        }

        if (stateComplete) {
          if (pixel->getState() == TWINKLE_IN) {
            pixel->changeState(TWINKLE_OUT);
          } else {
            pixel->changeState(TWINKLE_OFF);
          }
        }
      break;
    }
  }
}
*/

void TwinkleEffect::show(void) {
  myPixelStrip->show();
}
