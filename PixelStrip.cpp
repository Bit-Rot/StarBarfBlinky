#include "PixelStrip.h"

PixelStrip::PixelStrip(uint16_t ledCount, uint8_t pinNumber, neoPixelType type, uint8_t conversionMethod, uint8_t buttonPin) {
  myStrip = new Adafruit_NeoPixel(ledCount, pinNumber, type);
  myPixels = new Pixel[ledCount];
  myConversionMethod = conversionMethod;
  myButtonPin = buttonPin;
}

PixelStrip::~PixelStrip() {
  delete [] myPixels;
}

void PixelStrip::begin() {
  myStrip->begin();
}

void PixelStrip::show() {
  switch (myConversionMethod) {
    case CONVERSION_METHOD_DINO_PACK:
      for (int i=0; i<getNumPixels(); ++i) {
        if (i < 8) {
          myStrip->setPixelColorWithBrightness(((i/2)*8)+2*(i%2), myPixels[i].getColor(), myPixels[i].getBrightness());
          myStrip->setPixelColorWithBrightness(((i/2)*8)+2*(i%2)+1, myPixels[i].getColor(), myPixels[i].getBrightness());
          myStrip->setPixelColorWithBrightness(((i/2)*8)+2*(i%2)+4, myPixels[i].getColor(), myPixels[i].getBrightness());
          myStrip->setPixelColorWithBrightness(((i/2)*8)+2*(i%2)+5, myPixels[i].getColor(), myPixels[i].getBrightness());
        } else {
          myStrip->setPixelColorWithBrightness(2*(i-8)+32, myPixels[i].getColor(), myPixels[i].getBrightness());
          myStrip->setPixelColorWithBrightness(2*(i-8)+33, myPixels[i].getColor(), myPixels[i].getBrightness());
        }
      }
      break;
    case CONVERSION_METHOD_VEST:
      for (int i=0; i<getNumPixels(); ++i) {
        myStrip->setPixelColorWithBrightness(i, myPixels[i].getColor(), myPixels[i].getBrightness());
        myStrip->setPixelColorWithBrightness(59-i-1, myPixels[i].getColor(), myPixels[i].getBrightness());
      }
      break;
    default:
      for (int i=0; i<myStrip->numPixels(); ++i) {
        myStrip->setPixelColorWithBrightness(i, myPixels[i].getColor(), myPixels[i].getBrightness());
      }
      break;
  }

  myStrip->show();
}

Pixel *PixelStrip::getPixel(uint16_t pos) const{
  if (pos < myStrip->numPixels()) {
    return &myPixels[pos];
  }

  return NULL;
}

uint8_t PixelStrip::getRed(uint32_t color) {
  return myStrip->getRed(color);
}

uint8_t PixelStrip::getGreen(uint32_t color) {
  return myStrip->getGreen(color);
}

uint8_t PixelStrip::getBlue(uint32_t color) {
  return myStrip->getBlue(color);
}

void PixelStrip::clear() {
  myStrip->clear();
}

uint16_t PixelStrip::getNumPixels(void) const {
  switch (myConversionMethod) {
    case CONVERSION_METHOD_DINO_PACK:
      return 14;
      break;
    case CONVERSION_METHOD_VEST:
      return 29;
      break;
  }
  return myStrip->numPixels();
}

void PixelStrip::setMasterBrightness(uint8_t masterBrightness) {
  for (int i = 0; i < getNumPixels(); ++i) {
    myPixels[i].setMasterBrightness(masterBrightness);
  }
}

uint8_t PixelStrip::getButtonPin() {
  return myButtonPin;
}