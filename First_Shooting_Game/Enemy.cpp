#include "DxLib.h"
#include "Image.h"
#include "File.h"
#include "Enemy.h"
#include "E_Shot.h"
#include "Player.h"

#define _USE_MATH_DEFINES
#include <math.h>

extern int gCount;

Enemy::Enemy() {
	File* file;
	file = new File;
	file->loadStageData();
	mEnemyNum = file->enemyNum();
	mEnemy = new ENEMY[mEnemyNum];
	mEnemy = file->storeStageData();
	for (int i = 0; i < mEnemyNum; i++) {
		mEnemy[i].mHitArea = 0;								//“–‚½‚è”»’è
		mEnemy[i].mDirection = 0;
		int buf0[] = { 0, 1, 2, 3 };
		nomal=buf0;
		int buf1[] = { 4, 5, 6, 7 };
		left=buf1;
		int buf2[] = { 8, 9, 10, 11 };	
		right=buf2;//N:0, L:1, R:2
		switch (mEnemy[i].mType) {
		case 1:
			mEnemy[i].mImage = new Image("S:/materials/images/“Œ•û•—‘fŞ/“GŠÖŒW/enemy_fairyHD.png", 0.5);
			mEnemy[i].mImage->setDivGraph(0, 0, 96, 64, 4, 3);
			mEnemy[i].mImage->setAnimetion(0, nomal, 4, 4);
			mEnemy[i].mImage->setAnimetion(1, left, 4, 4);
			mEnemy[i].mImage->setAnimetion(2, right, 4, 4);
			break;
		case 2:
			mEnemy[i].mImage = new Image("S:/materials/images/“Œ•û•—‘fŞ/“GŠÖŒW/enemy_fairyHD.png", 0.5);
			mEnemy[i].mImage->setDivGraph(0, 64, 96, 128, 4, 3);
			mEnemy[i].mImage->setAnimetion(0, nomal, 4, 4);
			mEnemy[i].mImage->setAnimetion(1, left, 4, 4);
			mEnemy[i].mImage->setAnimetion(2, right, 4, 4);
			break;
		}
		mEnemy[i].mWidth = mEnemy[i].mImage->width();		//‰æ‘œ•
		mEnemy[i].mHeight = mEnemy[i].mImage->width();		//‰æ‘œ‚‚³

		mEnemy[i].mEffect = new Image("S:/materials/images/–{‰Æ•—‘fŞ/–{‰Æ•—‘fŞ‹l‚ß‡‚í‚¹/img/MagicCircle_alpha.png",0.01);
		mEnemy[i].mEffect->setDivGraph(0, 0, 256, 256, 4, 2);
		mEnemy[i].mEffect->setEffect(0);

		mEnemy[i].mX -= mEnemy[i].mWidth / 2;				//xÀ•W
		mEnemy[i].mY -= mEnemy[i].mHeight / 2;				//yÀ•W

		mEnemy[i].mShot = new E_Shot();						//’e

		mEnemy[i].mLive = false;
		mEnemy[i].mDying = false;
	}
}

Enemy::~Enemy() {
	for (int i = 0; i < mEnemyNum; i++) {
		delete mEnemy[i].mImage;
		mEnemy[i].mImage = 0;
		delete mEnemy[i].mShot;
		mEnemy[i].mShot = 0;
	}
}

void Enemy::getShotState(int eNum, int i, bool*  esLive, double* esx, double* esy) {
	*esLive = mEnemy[eNum].mShot->getState(i).live;
	*esx = mEnemy[eNum].mShot->getState(i).x;
	*esy = mEnemy[eNum].mShot->getState(i).y;
}

void Enemy::setShotDeath(int eNum, int sNum) {
	mEnemy[eNum].mShot->setDeath(sNum);
}

void Enemy::update(Player* player) {
	for(int i = 0; i < mEnemyNum; i++) {
		if (mEnemy[i].mHp > 0 && mEnemy[i].mInTime == gCount) { mEnemy[i].mLive = true; }		//oŒ»ŠÔ‚É‚È‚Á‚½‚çƒtƒ‰ƒOŒš‚Ä‚é
		if (mEnemy[i].mHp <= 0 || checkOutOfField(i)) { mEnemy[i].mLive = false; mEnemy[i].mDying = true; }										//HP0‚É‚È‚Á‚½‚çƒtƒ‰ƒO—‚Æ‚·
		if (mEnemy[i].mLive) {																		//ƒtƒ‰ƒO—§‚Á‚Ä‚½‚ç
			move(i);
			if (mEnemy[i].mInTime + mEnemy[i].mShotTime <= gCount
				&& gCount <= mEnemy[i].mInTime + mEnemy[i].mShotTime + mEnemy[i].mShootingTime) {
				mEnemy[i].mShot->fire(mEnemy[i].mX, mEnemy[i].mY, mEnemy[i].mShotType, player);
			}
		}

		mEnemy[i].mShot->update(mEnemy[i].mShotType, player);
	}
}


void Enemy::draw() {
	for (int i = 0; i < mEnemyNum; i++) {
		if (mEnemy[i].mLive) {
			drawScreen(mEnemy[i].mX, mEnemy[i].mY, mEnemy[i].mDirection);
		}
		if (mEnemy[i].mDying) {
			mEnemy[i].mEffect->drawEffect(mEnemy[i].mX, mEnemy[i].mY);
		}

		mEnemy[i].mShot->draw();
	}
}

void Enemy::drawScreen(int x, int y, int direction)const {
	for (int i = 0; i < mEnemyNum; i++) {
		switch (direction) {
		case 0:
			mEnemy[i].mImage->animationDraw(x, y, 0);
			break;
		case 1:
			mEnemy[i].mImage->setTurn(true);
			mEnemy[i].mImage->animationDraw(x, y, 1);
			mEnemy[i].mImage->setTurn(false);
			break;
		case 2:
			mEnemy[i].mImage->animationDraw(x, y, 1);
			break;
		}
	}
}

void Enemy::move(int i) {
	switch (mEnemy[i].mMotionType) {
	case 0: break;
	case 1:							//ã‚©‚çoŒ»¨–ß‚é
		if (mEnemy[i].mInTime <= gCount && gCount <= mEnemy[i].mInTime + mEnemy[i].mMoveTime) {
			mEnemy[i].dx = 0;
			mEnemy[i].dy = 2;
		}
		if (mEnemy[i].mInTime + mEnemy[i].mMoveTime == gCount) {
			mEnemy[i].dx = 0;
			mEnemy[i].dy = 0;
		}
		else if (mEnemy[i].mInTime + mEnemy[i].mStayTime <= gCount) {
			mEnemy[i].dx = 0;
			mEnemy[i].dy = -2;
		}
		break;

	case 2:							//ã‚©‚çoŒ»¨¶‚ÖJ‚¯‚é
		if (mEnemy[i].mInTime <= gCount && gCount <= mEnemy[i].mInTime + mEnemy[i].mMoveTime) {
			mEnemy[i].dx = 0;
			mEnemy[i].dy = 2;
		}
		if (mEnemy[i].mInTime + mEnemy[i].mMoveTime == gCount) {
			mEnemy[i].dx = 0;
			mEnemy[i].dy = 0;
		}
		else if (mEnemy[i].mInTime + mEnemy[i].mStayTime <= gCount) {
			mEnemy[i].dx = -1;
			mEnemy[i].dy = 2;
		}
		break;

	case 3:							//ã‚©‚çoŒ»¨‰E‚ÖJ‚¯‚é
		if (mEnemy[i].mInTime <= gCount && gCount <= mEnemy[i].mInTime + mEnemy[i].mMoveTime) {
			mEnemy[i].dx = 0;
			mEnemy[i].dy = 2;
		}
		if (mEnemy[i].mInTime + mEnemy[i].mMoveTime == gCount) {
			mEnemy[i].dx = 0;
			mEnemy[i].dy = 0;
		}
		else if (mEnemy[i].mInTime + mEnemy[i].mStayTime <= gCount) {
			mEnemy[i].dx = 1;
			mEnemy[i].dy = 2;
		}
		break;

	case 4:							//‰º‚ª‚Á‚Ä‚­‚é
		if (mEnemy[i].mInTime <= gCount && gCount <= mEnemy[i].mInTime + mEnemy[i].mMoveTime) {
			mEnemy[i].dx = 0;
			mEnemy[i].dy = 3;
		}
		if (mEnemy[i].mInTime + mEnemy[i].mStayTime == gCount) {
			mEnemy[i].dx = 0;
			mEnemy[i].dy = 3;
		}
		if (mEnemy[i].mInTime + mEnemy[i].mStayTime <= gCount) {
			mEnemy[i].dx -= 5 / 100.0;		//¶Œü‚«‰Á‘¬
			mEnemy[i].dy -= 5 / 100.0;		//Œ¸‘¬
		}
		break;

	case 5:							//‰º‚ª‚Á‚Ä‚­‚é
		if (mEnemy[i].mInTime <= gCount && gCount <= mEnemy[i].mInTime + mEnemy[i].mMoveTime) {
			mEnemy[i].dx = 0;
			mEnemy[i].dy = 3;
		}
		if (mEnemy[i].mInTime + mEnemy[i].mStayTime == gCount) {
			mEnemy[i].dx = 0;
			mEnemy[i].dy = 3;
		}
		if (mEnemy[i].mInTime + mEnemy[i].mStayTime <= gCount) {
			mEnemy[i].dx += 5 / 100.0;		//‰EŒü‚«‰Á‘¬
			mEnemy[i].dy -= 5 / 100.0;		//Œ¸‘¬
		}
		break;

	case 6:							//‰º‚ª‚Á‚Ä‚­‚é
		if (mEnemy[i].mInTime <= gCount && gCount <= mEnemy[i].mInTime + mEnemy[i].mMoveTime) {
			mEnemy[i].dx = 0;
			mEnemy[i].dy = 4 * sin(1.5*gCount);
		}
		if (mEnemy[i].mInTime + mEnemy[i].mStayTime == gCount) {
			mEnemy[i].dx = 0;
			mEnemy[i].dy = 0;
		}
		if (mEnemy[i].mInTime + mEnemy[i].mStayTime <= gCount) {
			mEnemy[i].dx = 4*cos(M_PI/90*gCount);
			mEnemy[i].dy = 2;
		}
		break;
	}

	mEnemy[i].mX += mEnemy[i].dx;
	mEnemy[i].mY += mEnemy[i].dy;

	if (mEnemy[i].dx == 0) { mEnemy[i].mDirection = 0; }
	if (mEnemy[i].dx < 0) { mEnemy[i].mDirection = 1; }
	if (mEnemy[i].dx > 0) { mEnemy[i].mDirection = 2; }
}

bool Enemy::checkOutOfField(int i) {
	if (mEnemy[i].mX < -100-mEnemy[i].mWidth || mEnemy[i].mX > 700
		|| mEnemy[i].mY < -100-mEnemy[i].mHeight || mEnemy[i].mY > 700) {
		return true;
	}
	else { return false; }
}