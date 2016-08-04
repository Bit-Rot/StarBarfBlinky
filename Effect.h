#ifndef EFFECT_H
#define EFFECT_H

#include "PixelStrip.h"

class Effect {
public:
	Effect(PixelStrip*);
	virtual void init(void) = 0;
	virtual void update(unsigned long delta) = 0;

protected:
	void clear();
	PixelStrip *myPixelStrip;
};

#endif //EFFECT_H