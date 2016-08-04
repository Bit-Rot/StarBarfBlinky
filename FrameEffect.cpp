#include "FrameEffect.h"

void FrameEffect::update(unsigned long time) {
	unsigned long frame = time / myFrameDuration;
	updateInternal(frame % myNumFrames);
}