#include "LightShow.h"

#define LONG_PRESS_DURATION 750
#define SHORT_PRESS_DURATION 50
#define BRIGHTNESS_1 255
#define BRIGHTNESS_2 150
#define BRIGHTNESS_3 50
#define BRIGHTNESS_4 20

LightShow::LightShow(PixelStrip *pixelStrip, uint8_t maxNumEffects) {

	myMaxNumEffects = maxNumEffects;
	myEffects = new Effect*[myMaxNumEffects];
	myNumEffects = 0;
	myLastTime = 0;
	myCurrentShow = 0;
	myShowType = 0;
	myStrip = pixelStrip;
  myButtonDownDuration = 0;
  myMasterBrightness = BRIGHTNESS_1;
  myJustChangedEffects = false;
}

void LightShow::setup() {
  pinMode(myStrip->getButtonPin(), INPUT_PULLUP);
  myStrip->begin();
  myStrip->show();

  if (myNumEffects > 0) {
    myEffects[0]->init();
  }
}

void LightShow::loop(unsigned long newTime) {
  if (myNumEffects < 1) {
    return;
  }

  unsigned long delta = newTime - myLastTime;

  // Get current button state.
  bool state = digitalRead(myStrip->getButtonPin());

  // Check if state changed from high to low (button press).
  if (state == LOW) {

    myButtonDownDuration += delta;

    // cycle through effects
    if (myButtonDownDuration > LONG_PRESS_DURATION) {
      myCurrentShow = ++myCurrentShow % myNumEffects;
      myEffects[myCurrentShow]->init();
      myJustChangedEffects = true;
      myButtonDownDuration = 0;
    }
  } else {
    if (!myJustChangedEffects) {
      cycleBrightness();
    }
    myJustChangedEffects = false;
    myButtonDownDuration = 0;
  }

  //Make any state updates necessary
  myEffects[myCurrentShow]->update(delta);
  myStrip->show(); 

  // Update timestamp
  myLastTime = newTime;
}

void LightShow::cycleBrightness() {
  if (myButtonDownDuration > SHORT_PRESS_DURATION) {
    switch (myMasterBrightness) {
      case BRIGHTNESS_1:
        myMasterBrightness = BRIGHTNESS_2;
        break;
      case BRIGHTNESS_2:
        myMasterBrightness = BRIGHTNESS_3;
        break;
      case BRIGHTNESS_3:
        myMasterBrightness = BRIGHTNESS_4;
        break;
      default:
        myMasterBrightness = BRIGHTNESS_1;
    }
    myStrip->setMasterBrightness(myMasterBrightness);
  }
}

void LightShow::addEffect(Effect *effect) {
	if (myNumEffects < myMaxNumEffects) {
		myEffects[myNumEffects] = effect;
		myNumEffects++;
	}
}