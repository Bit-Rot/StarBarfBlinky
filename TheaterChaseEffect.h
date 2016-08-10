#ifndef THEATER_CHASE_EFFECT_H
#define THEATER_CHASE_EFFECT_H

#include "Effect.h"
#include <Arduino.h>

/*
 * This effect makes a theater-marquee-esque effect where it looks like the lights
 * are running laps around a big sign or something.
 */
class TheaterChaseEffect : public Effect {
public:
	TheaterChaseEffect(PixelStrip *pixelStrip, uint32_t color, uint32_t uint32_t = 100);
	void init();
	void update(unsigned long time);

private:
	uint32_t myDuration;
	uint32_t myCurrentTime;
	uint32_t myColor;
};

#endif //THEATER_CHASE_EFFECT_H