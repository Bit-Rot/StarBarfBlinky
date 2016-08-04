#ifndef RAINBOW_EFFECT_H
#define RAINBOW_EFFECT_H

#include <Arduino.h>
#include "FrameEffect.h"

class RainbowEffect : public FrameEffect {
public:
	RainbowEffect(PixelStrip *pixelStrip, unsigned long);
	virtual void init(void);
	void update(unsigned long time);
	virtual void show(void);

private:
	virtual void updateInternal(uint8_t frame);
};

#endif //RAINBOW_EFFECT_H