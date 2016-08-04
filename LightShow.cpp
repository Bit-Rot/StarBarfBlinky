#include "LightShow.h"

// hack
#define BUTTON_PIN    10

LightShow::LightShow(PixelStrip *strip, uint8_t maxNumEffects) {

	myMaxNumEffects = maxNumEffects;
	myEffects = new Effect*[myMaxNumEffects];
	myNumEffects = 0;
	myLastTime = 0;
	myCurrentShow = 0;
	myShowType = 0;
	myStrip = strip;
}

void LightShow::setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  myStrip->begin();
  myStrip->show();
  myEffects[0]->init();
}

void LightShow::loop(unsigned long newTime) {
  // Get current button state.
  bool state = digitalRead(BUTTON_PIN);

  // Check if state changed from high to low (button press).
  if (state == LOW) {
    // Short delay to debounce button.
    delay(500);
    // Check if button is still low after debounce.
    state = digitalRead(BUTTON_PIN);
    if (state == LOW) {
      myCurrentShow++;
      if (myCurrentShow > myNumEffects) {
        myCurrentShow = 0;
      }
      myEffects[myCurrentShow]->init();
    }
  }

  //Make any state updates necessary
  unsigned long delta = newTime - myLastTime;
  myEffects[myCurrentShow]->update(delta);
  myEffects[myCurrentShow]->show();
 
  // Update timestamp
  myLastTime = newTime;
}

void LightShow::startShow(int i) {
	myEffects[i]->init();
}

void LightShow::addEffect(Effect *effect) {
	if (myNumEffects < myMaxNumEffects) {
		myEffects[myNumEffects] = effect;
		myNumEffects++;
	}
}