#include "DxLib.h"
#include "Image.h"
#include "Shot.h"

Shot::Shot() {
	mImage = new Image("S:/images/KMAP’e–‹•—‘fŞ/–²IŒ€ƒhƒbƒgŠG/shot_all.png");
	for (int i = 0; i < BULLET; i++) {
		shot[i].live = false;
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
			if (shot[i].live == false) {
				shot[i].live = true;
				shot[i].x = x;
				shot[i].y = y;
				break;
			}
		}
	}

	//’eˆÚ“®
	for (int i = 0; i < BULLET; i++) {
		if (shot[i].live) {
			shot[i].y -= 16;

			//‰æ–ÊŠO”»’è
			if (shot[i].y < -128) {
				shot[i].live = false;
			}
		}

	}
}

void Shot::draw() {
	for (int i = 0; i < BULLET; i++) {
		if (shot[i].live == true) { mImage->draw(shot[i].x, shot[i].y, 96, 80, 16, 16); }
	}
}