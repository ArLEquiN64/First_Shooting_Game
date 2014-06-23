#include "StringRenderer.h"
#include "Image.h"

StringRenderer::StringRenderer() {
	mBigString = new Image("S:/materials/images/“Œ•û•—‘fÞ/ƒVƒXƒeƒ€Œn/ascii_1280.png");
	mBigString->setDivGraph(0, 0, 28, 28, 18, 6);
	mString = new Image("S:/materials/images/“Œ•û•—‘fÞ/ƒVƒXƒeƒ€Œn/ascii_1280.png");
	mString->setDivGraph(0, 175, 16, 16, 32, 3);
}

StringRenderer::~StringRenderer() {
	delete mBigString;
	mBigString = 0;
	delete mString;
	mString = 0;
}

void StringRenderer::drawBig(int x, int y, const char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		int t = str[i];
		if (t < 32 || t >= 130) { t = 129; }
		t -= 32;
		mBigString->draw(x + i*mBigString->width(), y, t);
	}
}

void StringRenderer::draw(int x, int y, const char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		int t = str[i];
		if (t < 32 || t >= 128) { t = 127; }
		t -= 32;
		mString->draw(x+i*mString->width(), y, t);
	}
}