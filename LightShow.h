#ifndef LIGHTSHOW_H
#define LIGHTSHOW_H

#include "PixelStrip.h"
#include "Effect.h"

class LightShow {
public:

  LightShow(PixelStrip *pixelStrip, uint8_t maxNumEffects);
  ~LightShow() {};

  void setup();
  void loop(unsigned long);

  Effect** getEffects();
  uint8_t getNumEffects();
  void addEffect(Effect *);

private:

	Effect** myEffects;
	uint8_t myNumEffects;
	unsigned long myLastTime;
	uint8_t myCurrentShow;
	uint8_t myShowType;
	uint8_t myMaxNumEffects;
	uint32_t myButtonDownDuration;
	PixelStrip* myStrip;
	uint8_t myMasterBrightness;
	boolean myJustChangedEffects;
	void startShow(int i);
	void cycleBrightness();

};

#endif //LIGHTSHOW_H