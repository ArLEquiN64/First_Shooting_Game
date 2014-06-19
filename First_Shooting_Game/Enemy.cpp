#include "DxLib.h"
#include "Image.h"
#include "Enemy.h"
#include "E_Shot.h"

extern int gCount;

Enemy::Enemy() :mImage(0),mHp(0){
	mImage = new Image("S:/images/KMAP’e–‹•—‘fÞ/‚»‚Ì‘¼ƒ{ƒX‘fÞ/dot_rumia.png");
	mWidth = mImage->width();
	mHeight = mImage->height();

	mX = 400 - mWidth / 2;
	mY = -mHeight;
	
	mInTime = 3 * 60;
	mStopTime = 3 * 60;
	mOutTime = mInTime + mStopTime + 4 * 60;
	mShotInTime = mInTime + mStopTime + 1 * 60;
	mShotOutTime = mShotInTime + 2 * 60;

	mShot = new E_Shot();
}

Enemy::~Enemy() {
	delete mImage;
	mImage = 0;
}

void Enemy::update() {
	int dx = 0;
	int dy = 2;

	if (mInTime == gCount) { mHp = 16; }
	if (mInTime <= gCount && gCount <= mInTime + mStopTime) {
		mY += dy;
	}
	else if (mOutTime <= gCount) {
		mY -= dy;
	}

	if (mStopTime < gCount && mY <= -mHeight) { mHp = 0; }

	if (dx == 0) { mDirection = 0; }
	if (dx < 0) { mDirection = 1; }
	if (dx > 0) { mDirection = 2; }

	if (mHp > 0 && mShotInTime <= gCount && gCount <= mShotOutTime && gCount % 16 == 0) {
		mShot->fire(mX+17, mY+17);
	}

	mShot->update();
}


void Enemy::draw() {
	if (mHp > 0) {
		drawScreen(mX, mY, mDirection);
		mShot->draw();
	}
}

void Enemy::drawScreen(int x, int y, int direction)const {
	mImage->draw(x, y);
}