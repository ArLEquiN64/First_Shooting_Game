#include "DxLib.h"
#include "Image.h"
#include "E_Shot.h"

E_Shot::E_Shot() {
	mImage = new Image("S:/images/KMAP�e�����f��/���I���h�b�g�G/shot_all.png");
	for (int i = 0; i < BULLET; i++) {
		shot[i].live = false;
	}
}

E_Shot::~E_Shot() {
	delete mImage;
	mImage = 0;
}

void E_Shot::fire(int x, int y) {
	//�e����
	for (int i = 0; i < BULLET; i++) {
		if (shot[i].live == false) {
			shot[i].live = true;
			shot[i].x = x;
			shot[i].y = y;
			break;
		}
	}
}

void E_Shot::update() {
	//�e�ړ�
	for (int i = 0; i < BULLET; i++) {
		if (shot[i].live) {
			shot[i].y += 4;

			//��ʊO����
			if (shot[i].y > 800) {
				shot[i].live = false;
			}
		}

	}
}

void E_Shot::draw() {
	for (int i = 0; i < BULLET; i++) {
		if (shot[i].live == true) { mImage->draw(shot[i].x, shot[i].y, 96, 80, 16, 16); }
	}
}