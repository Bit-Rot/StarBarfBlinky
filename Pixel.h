#ifndef PIXEL_H
#define PIXEL_H

#include <Arduino.h>

class Pixel {

 public:

  // Constructor: number of LEDs, pin number, LED type
  Pixel(void);
  ~Pixel() {};

  uint8_t getBrightness(void);
  void setBrightness(uint8_t brightness) {myBrightness = brightness;};
  uint8_t getInitialBrightness(void) {return myInitialBrightness;};
  void setInitialBrightness(uint8_t initialBrightness) {myInitialBrightness = initialBrightness;};
  uint8_t getDestinationBrightness(void) {return myDestinationBrightness;};
  void setDestinationBrightness(uint8_t destinationBrightness) {myDestinationBrightness = destinationBrightness;};
  uint8_t getMasterBrightness(void) {return myMasterBrightness;};
  void setMasterBrightness(uint8_t masterBrightness) {myMasterBrightness = masterBrightness;};
  uint32_t getColor(void) {return myColor;};
  void setColor(uint32_t color) {myColor = color;};
  uint32_t getInitialColor(void) {return myInitialColor;};
  void setInitialColor(uint32_t initialColor) {myInitialColor = initialColor;};
  uint32_t getDestinationColor(void) {return myDestinationColor;};
  void setDestinationColor(uint32_t destinationColor) {myDestinationColor = destinationColor;};
  uint32_t getTimeInState(void) {return myTimeInState;};
  void setTimeInState(uint32_t timeInState) {myTimeInState = timeInState;};
  uint32_t getTransitionDuration(void) {return myTransitionDuration;};
  void setTransitionDuration(uint32_t transitionDuration) {myTransitionDuration = transitionDuration;};
  uint8_t getState(void) {return myState;};
  void changeState(uint8_t state) {myState = state; myTimeInState = 0;};
  void transition(uint8_t destinationBrightness, uint32_t destinationColor, uint32_t transitionDuration);

 private:

  uint8_t myBrightness;
  uint8_t myInitialBrightness;
  uint8_t myDestinationBrightness;
  uint8_t myMasterBrightness;
  uint32_t myColor;
  uint32_t myInitialColor;
  uint32_t myDestinationColor;
  uint32_t myTimeInState;
  uint32_t myTransitionDuration;
  uint8_t myState;

};

#endif // PIXEL_H