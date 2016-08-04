#ifndef MULTI_COLOR_TWINKLE_EFFECT_H
#define MULTI_COLOR_TWINKLE_EFFECT_H

#include "PixelStrip.h"
#include "ColorPallette.h"
#include "Effect.h"
#include "States.h"

class MultiColorTwinkleEffect : public Effect{

 public:

  // Constructor: number of LEDs, pin number, LED type
  MultiColorTwinkleEffect(PixelStrip &pixelStrip, int maxTwinkles = 7, int minTwinkleTime = 1000, int maxTwinkleTime = 3000, int twinkleRate = 100, uint32_t *colors = NULL, int numColors = 0);
  ~MultiColorTwinkleEffect();

  void init(void);
  void update(unsigned long delta);
  void show(void);
  int getMaxTwinkles(void) {return myMaxTwinkles;};
  void setMaxTwinkles(int maxTwinkles) {myMaxTwinkles = maxTwinkles;};
  int getNumTwinkles(void) {return myNumTwinkles;};
  void setNumTwinkles(int numTwinkles) {myNumTwinkles = numTwinkles;};
  int getMinTwinkleTime(void) {return myMinTwinkleTime;};
  void setMinTwinkleTime(int minTwinkleTime) {myMinTwinkleTime = minTwinkleTime;};
  int getMaxTwinkleTime(void) {return myMaxTwinkleTime;};
  void setMaxTwinkleTime(int maxTwinkleTime) {myMaxTwinkleTime = maxTwinkleTime;};
  ColorPallette* getColorPallette(void) const {return myColorPallette;};

 private:

  int myTwinkleRate;
  int myMaxTwinkles;
  int myNumTwinkles;
  int myMinTwinkleTime;
  int myMaxTwinkleTime;
  PixelStrip* myPixelStrip;
  ColorPallette *myColorPallette;
  
};

#endif // MULTI_COLOR_TWINKLE_EFFECT_H