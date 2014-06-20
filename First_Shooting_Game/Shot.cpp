#include "DxLib.h"
#include "Image.h"
#include "Shot.h"

Shot::Shot() {
	mImage = new Image("S:/images/KMAP’e–‹•—‘fŞ/–²IŒ€ƒhƒbƒgŠG/shot_all.png");
	for (int i = 0; i < BULLET; i++) {
		mShot[i].live = false;
	}
}

Shot::~Shot() {
	delete mImage;
	mImage = 0;
}

void Shot::update(int x, int y) {
	//’e”­Ë
	if (gKey[KEY_INPUT_J]) {
		for (int i = 0; i < BULLET; i++) {
			if (mShot[i].live == false) {
				mShot[i].live = true;
				mShot[i].x = x;
				mShot[i].y = y;
				break;
			}
		}
	}

	//’eˆÚ“®
	for (int i = 0; i < BULLET; i++) {
		if (mShot[i].live) {
			mShot[i].y -= 16;

			//‰æ–ÊŠO”»’è
			if (mShot[i].y < -128) {
				mShot[i].live = false;
			}
		}

	}
}

void Shot::draw() {
	for (int i = 0; i < BULLET; i++) {
		if (mShot[i].live == true) { mImage->draw(mShot[i].x, mShot[i].y, 96, 80, 16, 16); }
	}
}