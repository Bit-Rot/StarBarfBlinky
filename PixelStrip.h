#ifndef PIXEL_STRIP_H
#define PIXEL_STRIP_H

#define CONVERSION_METHOD_NORMAL 0
#define CONVERSION_METHOD_DINO_PACK 1
#define CONVERSION_METHOD_VEST 2

#include "Adafruit_NeoPixel.h"
#include "Pixel.h"

class PixelStrip {

 public:

  // Constructor: number of LEDs, pin number, LED type
  PixelStrip(uint16_t ledCount, uint8_t pinNumber=6, neoPixelType type=NEO_GRB + NEO_KHZ800, uint8_t conversionMethod = CONVERSION_METHOD_NORMAL, uint8_t buttonPin = 10);
  ~PixelStrip();

  void begin(void);
  void show(void);
  void clear();
  Pixel* getPixel(uint16_t pos) const;
  uint16_t getNumPixels(void) const ;
  Adafruit_NeoPixel *getStrip() const {return myStrip;};
  uint8_t getRed(uint32_t color);
  uint8_t getGreen(uint32_t color);
  uint8_t getBlue(uint32_t color);
  void setConversionMethod(uint8_t conversionMethod) {myConversionMethod = conversionMethod;};
  uint8_t getButtonPin();

 private:

  Adafruit_NeoPixel *myStrip;
  Pixel *myPixels;
  uint8_t myConversionMethod;
  uint8_t myButtonPin;
  
};

#endif // PIXEL_STRIP_H