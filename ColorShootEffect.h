#ifndef COLOR_SHOOT_EFFECT_H
#define COLOR_SHOOT_EFFECT_H

#include "PixelStrip.h"
#include "Effect.h"

/*
 * This effect sends a number of pixels of color along the strip.  
 * It does this over and over again.  Forever.
 */
class ColorShootEffect : public Effect {
public:
	/*
	 * color - the color to wipe with
	 * wait - the delay between activating one pixel and the next
	 * forward - whether to shoot the color forward or backward
	 * width - the # of pixels to shoot
	 */
	ColorShootEffect(PixelStrip *pixelStrip, uint32_t color, uint8_t wait = 50, boolean forward = true, uint8_t width = 1);
	void init(void);
	void update(unsigned long delta);

private:
	uint32_t myColor;
	uint8_t myWaitTime;
	boolean myForward;
	uint8_t myWidth;
};

#endif //COLOR_SHOOT_EFFECT_H