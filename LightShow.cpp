#include "LightShow.h"

#define LONG_PRESS_DURATION 750
#define SHORT_PRESS_DURATION 50

LightShow::LightShow(PixelStrip *pixelStrip, uint8_t maxNumEffects) {

	myMaxNumEffects = maxNumEffects;
	myEffects = new Effect*[myMaxNumEffects];
	myNumEffects = 0;
	myLastTime = 0;
	myCurrentShow = 0;
	myShowType = 0;
	myStrip = pixelStrip;
  myButtonDownDuration = 0;
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
      myButtonDownDuration = 0;
    }
  } else {
    myButtonDownDuration = 0;
  }

  //Make any state updates necessary
  myEffects[myCurrentShow]->update(delta);
  myStrip->show(); 

  // Update timestamp
  myLastTime = newTime;
}

void LightShow::addEffect(Effect *effect) {
	if (myNumEffects < myMaxNumEffects) {
		myEffects[myNumEffects] = effect;
		myNumEffects++;
	}
}