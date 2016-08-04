#include "GradientEffect.h"
#include "EffectUtils.h"

GradientEffect::GradientEffect(PixelStrip *pixelStrip, uint32_t *colors, uint8_t numColors, unsigned long frameDuration)
	: FrameEffect(pixelStrip) {
	myColors = colors;
	myNumColors = numColors;
	myFrameDuration = frameDuration;
	myNumFrames = 255;
}

void GradientEffect::init(void) {
	clear();
}

void GradientEffect::updateInternal(uint8_t frame) {
    for(int i=0; i<myPixelStrip->getNumPixels(); i++) {
//      myPixelStrip->getPixel(i)->setColor(wheel(i+frame));
      myPixelStrip->getPixel(i)->setColor(wheel2(i+frame));
//      myPixelStrip->getPixel(i)->setColor(wheel2(i * (myNumFrames) / myPixelStrip->getNumPixels()) + frame);
    }
}

uint32_t GradientEffect::wheel(uint8_t pos) {
	//find num pixels per strand
	//TODO: can we do this without rounding issues?
	uint8_t segmentSize = myPixelStrip->getNumPixels() / myNumColors;
	uint8_t segmentPos = pos % segmentSize;
	uint8_t currentSegment = pos / segmentSize;

	uint32_t color1 = myColors[currentSegment];
	uint32_t color2 = myColors[(currentSegment + 1) % myNumColors];

	return EffectUtils::colorBlend(color1, color2, 100 * segmentPos / segmentSize);
}

uint32_t GradientEffect::wheel2(uint8_t frame) {
	//find num pixels per strand
	//TODO: can we do this without rounding issues?
	uint8_t segmentSize = myNumFrames / myNumColors;
	uint8_t segmentPos = frame % segmentSize;
	uint8_t currentSegment = frame / segmentSize;

	uint32_t color1 = myColors[currentSegment];
	uint32_t color2 = myColors[(currentSegment + 1) % myNumColors];

	return EffectUtils::colorBlend(color1, color2, 100 * segmentPos / segmentSize);
}