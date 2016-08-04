#ifndef GRADIENT_EFFECT_H
#define GRADIENT_EFFECT_H

#include <Arduino.h>
#include "FrameEffect.h"

class GradientEffect : public FrameEffect {
public:
	GradientEffect(PixelStrip &pixelStrip, uint32_t *colors, uint8_t numcolors, unsigned long frameDuration=100);
	virtual void init(void);
	virtual void show(void);

private:
	virtual void updateInternal(uint8_t frame);
	uint32_t wheel(uint8_t pos);
	uint32_t wheel2(uint8_t frame);
	uint32_t *myColors;
	uint8_t myNumColors;
};

#endif //GRADIENT_EFFECT_H