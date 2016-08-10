#ifndef PATTERN_SHOOT_EFFECT_H
#define PATTERN_SHOOT_EFFECT_H

#include "PixelStrip.h"
#include "Effect.h"

/*
 * This effect sends an array of pixels of color along the strip.  
 * It does this over and over again.  Forever.
 */
class PatternShootEffect : public Effect {
public:
	/*
	 * color - the color to wipe with
	 * wait - the delay between activating one pixel and the next
	 * forward - whether to shoot the pixels forward or backward
	 */
	PatternShootEffect(PixelStrip *pixelStrip, uint32_t *pattern, uint8_t patternLength, uint32_t duration = 1000, boolean forward = true);
	void init(void);
	void update(unsigned long delta);

private:
	uint32_t *myPattern;
	uint8_t myPatternLength;
	uint32_t myDuration;
	uint32_t myCurrentTime;
	boolean myForward;
};

#endif //PATTERN_SHOOT_EFFECT_H