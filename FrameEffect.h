#ifndef FRAME_EFFECT_H
#define FRAME_EFFECT_H

#include "PixelStrip.h"
#include "Effect.h"

class FrameEffect : public Effect {
public:
	FrameEffect(PixelStrip*);
	virtual void init(void) = 0;
	virtual void update(unsigned long time);

private:
	virtual void updateInternal(uint8_t frame) = 0;

protected:
	unsigned long myFrameDuration;
	uint8_t myNumFrames;
	uint8_t myFrame;
};

#endif //FRAME_EFFECT_H