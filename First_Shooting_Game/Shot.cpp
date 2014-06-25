#include "DxLib.h"
#include "Image.h"
#include "Shot.h"

extern int gCount;

Shot::Shot() {
	mImage = new Image("S:/materials/images/“Œ•û•—‘fÞ/Ž©‹@/pl_shot.png");
	mImage->setDivGraph(32, 128, 16, 64, 2, 1);
	mShot = new SHOT[BULLET];
	for (int i = 0; i < BULLET; i++) {
		mShot[i].live = false;
	}
}

Shot::~Shot() {
	delete mImage;
	mImage = 0;
}

void Shot::update(int x, int y, Enemy* enemy) {
	//’e”­ŽË
	if (gKey[KEY_INPUT_J] && gCount % 1 == 0) {
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
			mShot[i].y -= 32;
		}
		//‰æ–ÊŠO”»’è
		if (mShot[i].y < -mImage->height()/2) {
			mShot[i].live = false;
		}
	}
}

void Shot::draw() {
	for (int i = 0; i < BULLET; i++) {
		if (mShot[i].live == true) { mImage->rotationDraw(mShot[i].x, mShot[i].y, 0, 1, 0); }
	}
}