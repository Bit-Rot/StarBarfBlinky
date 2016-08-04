#ifndef COLOR_WIPE_EFFECT_H
#define COLOR_WIPE_EFFECT_H

#include "PixelStrip.h"
#include "Effect.h"

/*
 * This effect sends a single color along the strip until the entire
 * strip is that color, and then clears, and repeats.  Forever.
 */
class ColorWipeEffect : public Effect {
public:
	/*
	 * color - the color to wipe with
	 * wait - the delay between activating one pixel and the next
	 */
	ColorWipeEffect(PixelStrip *pixelStrip, uint32_t color, uint8_t wait);
	void init(void);
	void update(unsigned long delta);

private:
	uint32_t myColor;
	uint8_t myWaitTime;
};

#endif //COLOR_WIPE_EFFECT_H