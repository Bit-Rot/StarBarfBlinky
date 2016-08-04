#ifndef TWINKLE_EFFECT_H
#define TWINKLE_EFFECT_H

#include "PixelStrip.h"
#include "Effect.h"
#include "States.h"

#define TWINKLE_MODE_LINEAR 0
#define TWINKLE_MODE_SIN 1

class TwinkleEffect : public Effect {

 public:

  // Constructor: number of LEDs, pin number, LED type
  TwinkleEffect(PixelStrip *pixelStrip, int twinkleMode=TWINKLE_MODE_LINEAR, int maxTwinkles=7, int minTwinkleTime=1000, int maxTwinkleTime=3000);
  ~TwinkleEffect();

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
  int getTwinkleMode(void) {return myTwinkleMode;};
  void setTwinkleMode(int twinkleMode) {myTwinkleMode = twinkleMode;};
  int* getColorPallette(void) const {return myColorPallette;};
  void setColorPallette(int* colorPallette) {myColorPallette = colorPallette;};
  int getColorPalletteLength(void) const {return myColorPalletteLength;};
  void setColorPalletteLength(int colorPalletteLength) {myColorPalletteLength = colorPalletteLength;};

 private:

  int myTwinkleMode;
  int myMaxTwinkles;
  int myNumTwinkles;
  int myMinTwinkleTime;
  int myMaxTwinkleTime;
  void updateLinear(unsigned long delta);
  void updateSin(unsigned long delta);
  int *myColorPallette;
  int myColorPalletteLength;

  void brightnessOnlyTwinkle(unsigned long delta);
  void multiColorTwinkle(unsigned long delta);
  void randomColorTwinkle(unsigned long delta);
  
};

#endif // TWINKLE_EFFECT_H