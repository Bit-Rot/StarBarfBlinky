#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <LightShow.h>
#include <SingleColorTwinkleEffect.h>
#include <MultiColorTwinkleEffect.h>
#include <ColorShootEffect.h>
#include <ColorWipeEffect.h>
#include <PatternShootEffect.h>
#include <RainbowEffect.h>
#include <ClearEffect.h>
#include <TheaterChaseEffect.h>
#include <EffectChainEffect.h>

/*
#include <ColorSoupEffect.h>
#include <GradientEffect.h>
*/

#define PIXEL_PIN     13
#define PIXEL_COUNT   60
#define MAX_NUM_EFFECTS 16

PixelStrip *strip = new PixelStrip(PIXEL_COUNT, PIXEL_PIN, NEO_RGB + NEO_KHZ800, CONVERSION_METHOD_NORMAL);

uint32_t testColors[] = {0xff0000, 0x00ff00, 0x0000ff};
uint8_t numTestColors = 3;
uint32_t purpleColors[] = {0x7437FF, 0x987AFF, 0xCBC1FF};
uint8_t numPurpleColors = 3;
uint32_t warmWhiteColors[] = {0xFFEAAA, 0xFFF6DC, 0xFFFEFB};
uint8_t numWarmWhiteColors = 3;
uint32_t americaShoot[] = {0xFF0000, 0xFF0000, 0xFF0000, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0x0000FF, 0x0000FF, 0x0000FF};
uint8_t americaShootLength = 9;

ColorShootEffect colorShoot1 = ColorShootEffect(strip, 0xFF0000);
ColorShootEffect colorShoot2 = ColorShootEffect(strip, 0x00FF00);
ColorShootEffect colorShoot3 = ColorShootEffect(strip, 0x0000FF);
ColorWipeEffect colorWipe1 = ColorWipeEffect(strip, 0xFF0000);
PatternShootEffect patternShoot1 = PatternShootEffect(strip, americaShoot, americaShootLength);
RainbowEffect rainbow1 = RainbowEffect(strip);
RainbowEffect rainbowCycle1 = RainbowEffect(strip, RAINBOW_EFFECT_MODE_CYCLE);
TheaterChaseEffect theaterChase1 = TheaterChaseEffect(strip, 0xffff33);
ClearEffect clearEffect = ClearEffect(strip);


SingleColorTwinkleEffect singleTwinkle1 = SingleColorTwinkleEffect(
  strip, //the strip object
  0xffffff, //color
  15, //max # twinkles
  500, //min twinkle time (ms)
  2000, //max twinkle time (ms)
  60); //twinkle rate
MultiColorTwinkleEffect multiTwinkle1 = MultiColorTwinkleEffect(
  strip, //the strip object
  15, //max # twinkles
  500, //min twinkle time (ms)
  2000, //max twinkle time (ms)
  40,
  purpleColors,
  numPurpleColors); //twinkle rate

/*
  Effect** effectChainEffects = new Effect*[3];
  effectChainEffects[0] = &colorShoot1;
  effectChainEffects[1] = &colorShoot2;
  effectChainEffects[2] = &colorShoot3;
  */
  Effect** effectChainEffects = new Effect*[3] {&colorShoot1, &colorShoot2, &colorShoot3};
  EffectChainEffect effectChainEffect1 = EffectChainEffect(strip, effectChainEffects, 3, 1000);

//NOT READY YET :(
/* 
ColorSoupEffect colorSoup1 = ColorSoupEffect(
  strip, //the strip object
  testColors,
  numTestColors,
  500, //min twinkle time (ms)
  2000); //max twinkle time (ms)
GradientEffect gradient1 = GradientEffect(
  strip,
  testColors,
  numTestColors,
  50);
*/

LightShow* lightShow = NULL;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  

  lightShow = new LightShow(strip, MAX_NUM_EFFECTS);
  lightShow->addEffect(&effectChainEffect1);
  lightShow->addEffect(&singleTwinkle1);
  lightShow->addEffect(&multiTwinkle1);
  lightShow->addEffect(&colorShoot1);
  lightShow->addEffect(&colorWipe1);
  lightShow->addEffect(&patternShoot1);
  lightShow->addEffect(&theaterChase1);
  lightShow->addEffect(&rainbow1);
  lightShow->addEffect(&rainbowCycle1);
  lightShow->addEffect(&clearEffect);
  
  lightShow->setup();
}

void loop() {
  unsigned long newTime = millis();
  lightShow->loop(newTime);
}
