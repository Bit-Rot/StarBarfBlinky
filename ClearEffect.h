#ifndef CLEAR_EFFECT_H
#define CLEAR_EFFECT_H

#include "PixelStrip.h"
#include "Effect.h"

/*
 * An effect that turns all the LED's off.  Maybe useful if you want to
 * save batteries for a bit without having to unplug anything.  Not
 * recommended if you want to keep your lights on for a long period of time.
 */
class ClearEffect : public Effect {
public:
	void init(void);
	void update(unsigned long delta);
};

#endif //EFFECT_H