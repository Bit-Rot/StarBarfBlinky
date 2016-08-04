#ifndef EFFECT_UTILS_H
#define EFFECT_UTILS_H

#include "Adafruit_NeoPixel.h"

class EffectUtils {
public:
	static uint32_t wheel(byte wheelPos);
	static uint32_t colorBlend(uint32_t color1, uint32_t color2, uint8_t percent);
};

#endif