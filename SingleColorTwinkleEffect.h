#ifndef SINGLE_COLOR_TWINKLE_EFFECT_H
#define SINGLE_COLOR_TWINKLE_EFFECT_H

#include "PixelStrip.h"
#include "Effect.h"
#include "States.h"

class SingleColorTwinkleEffect : public Effect {

 public:

  // Constructor: number of LEDs, pin number, LED type
  SingleColorTwinkleEffect(PixelStrip *pixelStrip, uint32_t color, int maxTwinkles=7, int minTwinkleTime=1000, int maxTwinkleTime=3000, int twinkleRate=100);
  ~SingleColorTwinkleEffect();

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
  uint32_t getColor(void) const {return myColor;};
  void setColor(uint32_t color) {myColor = color;};

 private:

  int myTwinkleRate;
  int myMaxTwinkles;
  int myNumTwinkles;
  int myMinTwinkleTime;
  int myMaxTwinkleTime;
  uint32_t myColor;
  
};

#endif // SINGLE_COLOR_TWINKLE_EFFECT_H