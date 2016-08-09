#include "LightShow.h"

LightShow::LightShow(PixelStrip *pixelStrip, uint8_t maxNumEffects) {

	myMaxNumEffects = maxNumEffects;
	myEffects = new Effect*[myMaxNumEffects];
	myNumEffects = 0;
	myLastTime = 0;
	myCurrentShow = 0;
	myShowType = 0;
	myStrip = pixelStrip;
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

  // Get current button state.
  bool state = digitalRead(myStrip->getButtonPin());

  // Check if state changed from high to low (button press).
  if (state == LOW) {
    // Short delay to debounce button.
    delay(500);
    // Check if button is still low after debounce.
    state = digitalRead(myStrip->getButtonPin());
    if (state == LOW) {
      myCurrentShow++;
      if (myCurrentShow >= myNumEffects) {
        myCurrentShow = 0;
      }
      myEffects[myCurrentShow]->init();
    }
  }

  //Make any state updates necessary
  unsigned long delta = newTime - myLastTime;
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