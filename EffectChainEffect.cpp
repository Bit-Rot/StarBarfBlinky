#include "EffectChainEffect.h"

EffectChainEffect::EffectChainEffect(PixelStrip* pixelStrip, Effect** effects, uint8_t numEffects, uint32_t duration)
  : Effect(pixelStrip) {
  myEffects = effects;
  myNumEffects = numEffects;
  myDuration = duration;
  myCurrentTime = 0;
  myCurrentEffect = 0;
}

void EffectChainEffect::init() {
  clear();
  myCurrentTime = 0;
  myCurrentEffect = 0;

  if (myNumEffects > 0) {
    myEffects[0]->init();
  }
}

void EffectChainEffect::update(unsigned long delta) {
  if (myNumEffects < 1) {
    return;
  }

  uint32_t myPreviousTime = myCurrentTime;
  myCurrentTime = (myCurrentTime + delta) % myDuration;
  double percent = (double)myCurrentTime / (double)myDuration;
  uint8_t position = (uint8_t)(percent * (myPixelStrip->getNumPixels() - 1));

  if (myPreviousTime > myCurrentTime) {
    myCurrentEffect = (myCurrentEffect + 1) % myNumEffects;
    myEffects[myCurrentEffect]->init();
  }

  myEffects[myCurrentEffect]->update(delta);
}