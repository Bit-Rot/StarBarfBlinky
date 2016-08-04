#include "RainbowEffect.h"
#include "Effects.h"

RainbowEffect::RainbowEffect(PixelStrip *pixelStrip, unsigned long frameDuration=100)
	: FrameEffect(pixelStrip) {
	myNumFrames = 256;
	myFrameDuration = frameDuration;
}

void RainbowEffect::init(void) {
	Effects::clear(*myPixelStrip);
}

void RainbowEffect::updateInternal(uint8_t frame) {
    for(int i=0; i<myPixelStrip->getNumPixels(); i++) {
      myPixelStrip->getPixel(i)->setColor(Effects::Wheel((i+frame) & 255));
      myPixelStrip->getPixel(i)->setBrightness(255);
    }
}