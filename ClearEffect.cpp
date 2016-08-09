#include "ClearEffect.h"

ClearEffect::ClearEffect(PixelStrip *pixelStrip)
	: Effect(pixelStrip) {
}

void ClearEffect::init() {
	clear();
}