#include "DxLib.h"
#include "Image.h"
#include "Player.h"
#include "Shot.h"

Player::Player() :mImage(0){
	mImage = new Image("S:/images/KMAP弾幕風素材/自機素材/Reisen.png");
	mHitArea = new Image("S:/images/KMAP弾幕風素材/自機素材/atarihantei.png");
	mShot = new Shot();
	mX = 400 - 21;
	mY = 350;
}

Player::~Player(){
	delete mImage;
	mImage = 0;
	delete mHitArea;
	mHitArea = 0;
}

void Player::update() {
	//移動量
	int dx = 0;
	int dy = 0;
	if (gKey[KEY_INPUT_A] == 0 && gKey[KEY_INPUT_D] == 1) { dx = 2; }
	if (gKey[KEY_INPUT_A] == 1 && gKey[KEY_INPUT_D] == 0) { dx = -2; }
	if (gKey[KEY_INPUT_W] == 0 && gKey[KEY_INPUT_S] == 1) { dy = 2; }
	if (gKey[KEY_INPUT_W] == 1 && gKey[KEY_INPUT_S] == 0) { dy = -2; }
	if (gKey[KEY_INPUT_SPACE] == 0) { dx *= 2; dy *= 2; }	//Spaceキーで速度半減
	//移動後座標
	int tx = mX + dx;
	int ty = mY + dy;
	//座標の最大最小チェック。外れていれば不許可
	if (tx < -21 || tx >= 800 - 27) { tx = mX; }
	if (ty < -21 || ty >= 600 - 27) { ty = mY; }
	mX = tx;
	mY = ty;

	if (dx == 0) { mDirection = 0; }
	if (dx < 0) { mDirection = 1; }
	if (dx > 0) { mDirection = 2; }

	mShot->update(mX+16,mY+16);
}

void Player::draw(){
	mShot->draw();
	drawScreen(mX, mY, mDirection);
}

void Player::drawScreen(int x, int y, int direction) const {
	switch (direction) {
	case 0:	mImage->draw(x, y, 0, 0, 48, 48); break;
	case 1:	mImage->draw(x, y, 48, 0, 48, 48); break;
	case 2:	mImage->draw(x, y, 96, 0, 48, 48); break;
	}
	mHitArea->draw(x + 12, y + 12);
}