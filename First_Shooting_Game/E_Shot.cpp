#define _USE_MATH_DEFINES
#include <math.h>
#include "DxLib.h"
#include "Image.h"
#include "E_Shot.h"

E_Shot::E_Shot() {
	mImage = new Image("S:/materials/images/niconi-commons/niconicommons_only/nc89509.png",0.6);
	mImage->setDivGraph(0,0,32,32,16,12);
	for (int i = 0; i < BULLET; i++) {
		shot[i].live = false;
	}
}

E_Shot::~E_Shot() {
	delete mImage;
	mImage = 0;
}

void E_Shot::fire(int x, int y) {
	//’e”­ŽË
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
	//’eˆÚ“®
	for (int i = 0; i < BULLET; i++) {
		if (shot[i].live) {
			shot[i].y += 4;

			//‰æ–ÊŠO”»’è
			if (shot[i].y > 800) {
				shot[i].live = false;
			}
		}

	}
}

void E_Shot::draw() {
	for (int i = 0; i < BULLET; i++) {
		if (shot[i].live == true) { mImage->rotationDraw(shot[i].x, shot[i].y, 18, M_PI); }
	}
}