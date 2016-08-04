#include "FrameEffect.h"

FrameEffect::FrameEffect(PixelStrip* pixelStrip) : Effect(pixelStrip) {}

void FrameEffect::update(unsigned long time) {
	unsigned long frame = time / myFrameDuration;
	updateInternal(frame % myNumFrames);
}