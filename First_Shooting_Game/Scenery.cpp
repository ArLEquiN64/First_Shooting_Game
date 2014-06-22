#include "Scenery.h"
#include "Image.h"

Scenery::Scenery() : x(0),y(0) {
	mImage = new Image("S:/materials/images/”wŒi.png");
	mHeight = mImage->height();
}

Scenery::~Scenery() {
	delete mImage;
	mImage = 0;
}

void Scenery::update() {
	y+=8;
	if (y == mHeight) { y = 0; }
}

void Scenery::draw() {
	mImage->draw(x,y);
	mImage->draw(x, y - mHeight);
}