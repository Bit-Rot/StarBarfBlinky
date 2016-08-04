#ifndef EFFECTS_H
#define EFFECTS_H

#include "PixelStrip.h"

class Effects {

 public:

  Effects(void);
  ~Effects() {};
  static void rainbow(PixelStrip &pixelStrip, uint8_t wait);
  static void rainbowCycle(PixelStrip &pixelStrip, uint8_t wait);
  static void theaterChase(PixelStrip &pixelStrip, uint32_t c, uint8_t wait);
  static void theaterChaseRainbow(PixelStrip &pixelStrip, uint8_t wait);
  static uint32_t Wheel(byte WheelPos);
  static uint32_t colorBlend(uint32_t color1, uint32_t color2, uint8_t percent);
};

#endif // EFFECTS_H