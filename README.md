# StarBarfBlinky

## Getting Started

### Step 1. Install Arduino

https://www.arduino.cc/en/Main/OldSoftwareReleases

### Step 2. Download StarBarfBlinky Project

You can download the project as a zip

### Step 3. Unzip StarBarfBlinky Project

You should unzip the project into your Arduino libraries directory.

On mac, this should be under `/Users/<username>/Documents/libraries/`

So, you should unzip in the following directory: `/Users/<username>/Documents/libraries/StarBarfBlinky`

### Step 4. Create your ino file

Included in the zip file is an example ino file, you should start with this!  This should be located at `/Users/<username>/Documents/libraries/StarBarfBlinky`

### Step 5. Configure your blinky

#### PIXEL_PIN

See the line that says `#define PIXEL_PIN 13`?

Change this if your output pin isn't 13?  This should stay as 13 if you're using any BlinkinLabs product.  Not using blinkin labs and don't know what this means?  Google is your friend!  Still lost?  Ask the author!

#### PIXEL_COUNT

See the line that says `#define PIXEL_COUNT 60`?

This refers to the number of pixels/LED's you have on your strip.  Change this if you're working with a strip that isn't 60 pixels/LED's long!

#### MAX_NUM_EFFECTS

See the line that says `#define MAX_NUM_EFFECTS 16`?

This is the maximum number of effects your program can hold.  If you try to add more than this, it won't work!  Make sure you increase this if you need more effects, but try to keep it at a reasonable number.

#### NEO_GRB vs. NEO_RGB

See the line that says `PixelStrip *strip = new PixelStrip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800, CONVERSION_METHOD_NORMAL);`?

See the `NEO_GRB` in that line?

This refers to whether your strip is a GRB (green-red-blue) or (red-green-blue) strip.  Check with whoever you bought your blinky from to find out!  Need help?  Ask the author!

#### CONVERSION_METHOD_NORMAL

See the line that says `PixelStrip *strip = new PixelStrip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800, CONVERSION_METHOD_NORMAL);`?

See the `CONVERSION_METHOD_NORMAL`?

Sorry!  This isn't something you can meaningfully change yet - just a tease!  The idea is if you have a special strip (maybe it folds in half, or bends around to make a square), you might want special logic for you how map your 'pixels' to the actual LED's they refer to.

### Step 6. Understand the classes

I've tried to abstract the core logic of StarBarfBlinky into two main concepts:

#### LightShow

A light show is a collection of effects that you can cycle through!  Maybe you want some twinkles, some red blinky stuff, and a rainbow effect.  Add these effects to the light show, and enjoy!

#### Effects

Everything that shows up on your blinky is an effect!  Want some rainbow stuff?  There's a rainbow effect for that!  Want some twinkly stuff?  There's a twinkle effect for that!  Want more effects?  Make a pull request :)

#### Step 7. Add Effects

To add effects to your lightshow, you need to do two things:

#### A) Create the effect

See the line that says `ColorShootEffect colorShoot1 = ColorShootEffect(strip, 0xFF0000);`?

This is how an effect is created!  Try creating your own effects!

#### B) Add the effect to the lightshow

See the line that says `lightShow->addEffect(&colorShoot1);`?

This is how an effect is added!  Try adding your own effects!