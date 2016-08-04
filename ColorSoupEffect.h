#ifndef COLOR_SOUP_H
#define COLOR_SOUP_H

#include "PixelStrip.h"
#include "ColorPallette.h"
#include "Effect.h"
#include "States.h"

class ColorSoupEffect : public Effect{

 public:

  // Constructor: number of LEDs, pin number, LED type
  ColorSoupEffect(PixelStrip *pixelStrip, uint32_t *colors, uint8_t numColors, int minTwinkleTime=1000, int maxTwinkleTime=3000);

  void init(void);
  void update(unsigned long delta);
  void show(void);
  int getMinTwinkleTime(void) {return myMinTwinkleTime;};
  void setMinTwinkleTime(int minTwinkleTime) {myMinTwinkleTime = minTwinkleTime;};
  int getMaxTwinkleTime(void) {return myMaxTwinkleTime;};
  void setMaxTwinkleTime(int maxTwinkleTime) {myMaxTwinkleTime = maxTwinkleTime;};
  ColorPallette* getColorPallette(void) const {return myColorPallette;};

 private:

  int myMaxTwinkles;
  int myNumTwinkles;
  int myMinTwinkleTime;
  int myMaxTwinkleTime;
  ColorPallette *myColorPallette;
  
};

#endif // COLOR_SOUP_H