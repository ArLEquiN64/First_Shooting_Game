#include "DxLib.h"
#include "Image.h"
#include "Player.h"
#include "Shot.h"
#define _USE_MATH_DEFINES
#include <math.h>

extern int gCount;

Player::Player() :mLive(true), mImage(0) {
	mImage = new Image("S:/materials/images/東方風素材/自機/pl00_th14.png");
	mImage->setDivGraph(0, 0, 32, 48, 8, 3);
	mHitArea = new Image("S:/materials/images/東方風素材/自機/Effectelse.png", 0.25);
	mShot = new Shot();
	mX = 300;
	mY = 350;
}

Player::~Player(){
	delete mImage;
	mImage = 0;
	delete mHitArea;
	mHitArea = 0;
}

void Player::getShotState(int sNum, bool* psLive, double* psx, double* psy) {
	*psLive = mShot->state(sNum).live; *psx = mShot->state(sNum).x; *psy = mShot->state(sNum).y;
}

void Player::setShotDeath(int sNum) {
	mShot->setDeath(sNum);
}

void Player::update() {
	if (mLive == true) {
		//移動量
		int dx = 0;
		int dy = 0;
		if (gKey[KEY_INPUT_A] == 0 && gKey[KEY_INPUT_D] == 1) { dx = 2; }
		if (gKey[KEY_INPUT_A] == 1 && gKey[KEY_INPUT_D] == 0) { dx = -2; }
		if (gKey[KEY_INPUT_W] == 0 && gKey[KEY_INPUT_S] == 1) { dy = 2; }
		if (gKey[KEY_INPUT_W] == 1 && gKey[KEY_INPUT_S] == 0) { dy = -2; }
		if (gKey[KEY_INPUT_SPACE] == 0) { dx *= 3; dy *= 3; }	//Spaceキーで速度半減
		//移動後座標
		int tx = mX + dx;
		int ty = mY + dy;
		//座標の最大最小チェック。外れていれば不許可
		if (tx < 3 || tx >= 600 - 3) { tx = mX; }
		if (ty < 3 || ty >= 600 - 3) { ty = mY; }
		mX = tx;
		mY = ty;

		if (dx == 0) { mDirection = 0; }
		if (dx < 0) { mDirection = 1; }
		if (dx > 0) { mDirection = 2; }
	}
	else if (mLive == false && mLife > 0) {
		mLife -= 1;
	}

	mShot->update(mX,mY);
}

void Player::draw(){
	mShot->draw();
	drawScreen(mX, mY, mDirection);
}

void Player::drawScreen(int x, int y, int direction) const {
	switch (direction) {
	case 0:	mImage->rotationDraw(x, y, 0); break;
	case 1:	mImage->rotationDraw(x, y, 8); break;
	case 2:	mImage->rotationDraw(x, y, 16); break;
	}
	mHitArea->rotationDraw(x, y, 0, (M_PI / 60)*(gCount % 120));
	mHitArea->rotationDraw(x, y, 0, -(M_PI / 60)*(gCount % 120));
}