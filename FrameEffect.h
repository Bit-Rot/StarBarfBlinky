#ifndef FRAME_EFFECT_H
#define FRAME_EFFECT_H

#include "PixelStrip.h"
#include "Effect.h"

class FrameEffect : public Effect {
public:
	FrameEffect() {};
	virtual void init(void);
	virtual void update(unsigned long time);
	virtual void show(void);

private:
	virtual void updateInternal(uint8_t frame);

protected:
	PixelStrip* myPixelStrip;
	unsigned long myFrameDuration;
	uint8_t myNumFrames;
	uint8_t myFrame;
};

#endif //FRAME_EFFECT_H