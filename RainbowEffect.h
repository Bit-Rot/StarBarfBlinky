#ifndef RAINBOW_EFFECT_H
#define RAINBOW_EFFECT_H

//I actually have absolutely no idea how these are different.  Good luck.
#define RAINBOW_EFFECT_MODE_NORMAL 0
#define RAINBOW_EFFECT_MODE_CYCLE 1

#include "Effect.h"
#include <Arduino.h>

/*
 * This effect makes a rainbow glowy pattern.
 */
class RainbowEffect : public Effect {
public:
	RainbowEffect(PixelStrip *pixelStrip, uint8_t mode = RAINBOW_EFFECT_MODE_NORMAL, uint32_t duration = 10000);
	void init(void);
	void update(unsigned long time);

private:
	uint32_t myDuration;
	uint32_t myCurrentTime;
	uint8_t myMode;
};

#endif //RAINBOW_EFFECT_H