#ifndef EFFECT_H
#define EFFECT_H

#include "PixelStrip.h"

class Effect {
public:
	Effect(PixelStrip *pixelStrip);
	virtual void init(void) = 0;
	virtual void update(unsigned long delta) = 0;
  void setConversionMethod(uint8_t conversionMethod);

protected:
	void clear();
	PixelStrip *myPixelStrip;
  uint8_t myConversionMethod;
};

#endif //EFFECT_H