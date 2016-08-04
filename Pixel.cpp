#include "Pixel.h"

Pixel::Pixel() : myBrightness(255), myInitialBrightness(255), 
	myDestinationBrightness(255), myColor(0), myInitialColor(0), 
	myDestinationColor(0), myTimeInState(0), myTransitionDuration(0), myState(0) {

}

void Pixel::transition(uint8_t destinationBrightness, uint32_t destinationColor, uint32_t transitionDuration) {
	this->setInitialBrightness(myBrightness);
	this->setDestinationBrightness(destinationBrightness);
	this->setInitialColor(myColor);
	this->setDestinationColor(destinationColor);
	this->setTransitionDuration(transitionDuration);
}