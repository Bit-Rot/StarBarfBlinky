#ifndef EFFECT_CHAIN_EFFECT_H
#define EFFECT_CHAIN_EFFECT_H

#include "PixelStrip.h"
#include "Effect.h"

/*
 * This effect sends a single color along the strip until the entire
 * strip is that color, and then clears, and repeats.  Forever.
 */
class EffectChainEffect : public Effect {
public:
  /*
   * color - the color to wipe with
   * wait - the delay between activating one pixel and the next
   */
  EffectChainEffect(PixelStrip *pixelStrip, Effect **effects, uint8_t numEffects, uint32_t duration = 5000);
  void init(void);
  void update(unsigned long delta);

private:
  Effect **myEffects;
  uint32_t myDuration;
  uint32_t myCurrentTime;
  uint8_t myNumEffects;
  uint8_t myCurrentEffect;
};

#endif //EFFECT_CHAIN_EFFECT_H