#include "DxLib.h"
#include "Image.h"
#include "File.h"
#include "Enemy.h"
#include "E_Shot.h"

extern int gCount;

Enemy::Enemy() {
	File* file;
	file = new File;
	file->loadStageData();
	mEnemyNum = file->enemyNum();
	mEnemy = new ENEMY*[ENEMY_NUM];
	for (int i = 0; i < mEnemyNum; i++) {
		mEnemy[i] = new ENEMY;
		mEnemy[i] = file->storeStageData(i);
		//mEnemy[i].mType = data.mType;						//���
		//mEnemy[i].mBulletType = data.mBulletType;			//�e���
		//mEnemy[i].mBulletSpeed = data.mBulletSpeed;		//�e���x
		//mEnemy[i].mMotionType = data.mMotionType;			//�ړ��p�^�[��
		//mEnemy[i].mShotType = data.mShotType;				//�U���p�^�[��
		//mEnemy[i].mInTime = data.mInTime;					//�o������
		//mEnemy[i].mMoveTime = data.mMoveTime;				//�ړ�����
		//mEnemy[i].mStayTime = data.mStayTime;				//�؍ݎ���
		//mEnemy[i].mShotTime = data.mShotTime;				//�e���ˊJ�n����
		//mEnemy[i].mShootingTime = data.mShootingTime;		//�e���ˎ���

		//mEnemy[i].mHp = data.mHp;							//�̗�
		//mEnemy[i].mItem = data.mItem;						//�A�C�e��

		mEnemy[i]->mHitArea = 0;								//�����蔻��
		mEnemy[i]->mDirection = 0;							//N:0, L:1, R:2

		mEnemy[i]->mImage = new Image("S:/materials/images/�������f��/�G�֌W/enemy_fairyHD.png", 0.5);
		mEnemy[i]->mImage->setDivGraph(0, 0, 96, 64, 4, 3);
		mEnemy[i]->mWidth = mEnemy[i]->mImage->width();		//�摜��
		mEnemy[i]->mHeight = mEnemy[i]->mImage->width();		//�摜����

		mEnemy[i]->mX -= mEnemy[i]->mWidth / 2;				//x���W
		mEnemy[i]->mY -= mEnemy[i]->mHeight / 2;				//y���W

		mEnemy[i]->mShot = new E_Shot();						//�e

		mEnemy[i]->mLive = false;
	}
}

Enemy::~Enemy() {
	for (int i = 0; i < mEnemyNum; i++) {
		delete mEnemy[i]->mImage;
		mEnemy[i]->mImage = 0;
		delete mEnemy[i]->mShot;
		mEnemy[i]->mShot = 0;
	}
}

void Enemy::getShotState(int eNum, int i, bool*  esLive, double* esx, double* esy) {
	*esLive = mEnemy[eNum]->mShot->getState(i).live;
	*esx = mEnemy[eNum]->mShot->getState(i).x;
	*esy = mEnemy[eNum]->mShot->getState(i).y;
}

void Enemy::update() {
	for(int i = 0; i < mEnemyNum; i++) {
		if (mEnemy[i]->mHp > 0 && mEnemy[i]->mInTime == gCount) { mEnemy[i]->mLive = true; }
		if (mEnemy[i]->mHp <= 0) { mEnemy[i]->mLive = false; }
		if (mEnemy[i]->mLive) {
			move(i);
			if (mEnemy[i]->mInTime + mEnemy[i]->mShotTime <= gCount
				&& gCount <= mEnemy[i]->mInTime + mEnemy[i]->mShotTime + mEnemy[i]->mShootingTime
				&& gCount % 16 == 0) {
				mEnemy[i]->mShot->fire(mEnemy[i]->mX, mEnemy[i]->mY);
			}
			checkOutOfField(i);
		}
		else if (mEnemy[i]->mInTime < gCount && mEnemy[i]->mLive == false) {
			delete mEnemy[i];
			mEnemy[i] = 0;
		}
		mEnemy[i]->mShot->update();
	}
}


void Enemy::draw() {
	for (int i = 0; i < mEnemyNum; i++) {
		if (mEnemy[i]->mLive) {
			drawScreen(mEnemy[i]->mX, mEnemy[i]->mY, mEnemy[i]->mDirection);
		}
		mEnemy[i]->mShot->draw();
	}
}

void Enemy::drawScreen(int x, int y, int direction)const {
	for (int i = 0; i < mEnemyNum; i++) {
		mEnemy[i]->mImage->rotationDraw(x, y);
	}
}

void Enemy::move(int i) {
	int dx = 0;
	int dy = 0;

	switch (mEnemy[i]->mMotionType) {
	case 0: break;
	case 1:							//�ォ��o�����߂�
		dy = 2;

		if (mEnemy[i]->mInTime <= gCount && gCount <= mEnemy[i]->mInTime + mEnemy[i]->mMoveTime) {
			mEnemy[i]->mY += dy;
		}
		else if (mEnemy[i]->mInTime + mEnemy[i]->mStayTime <= gCount) {
			mEnemy[i]->mY -= dy;
		}

		break;

	case 2:							//�ォ��o�������֎J����
		dx = -1;
		dy = 2;

		if (mEnemy[i]->mInTime <= gCount && gCount <= mEnemy[i]->mInTime + mEnemy[i]->mMoveTime) {
			mEnemy[i]->mX += dx;
			mEnemy[i]->mY += dy;
		}
		else if (mEnemy[i]->mInTime + mEnemy[i]->mStayTime <= gCount) {
			mEnemy[i]->mX += dx;
			mEnemy[i]->mY += dy;
		}

		break;

	case 3:							//�ォ��o�����E�֎J����
		dx = 1;
		dy = 2;

		if (mEnemy[i]->mInTime <= gCount && gCount <= mEnemy[i]->mInTime + mEnemy[i]->mMoveTime) {
			mEnemy[i]->mX += dx;
			mEnemy[i]->mY += dy;
		}
		else if (mEnemy[i]->mInTime + mEnemy[i]->mStayTime <= gCount) {
			mEnemy[i]->mX += dx;
			mEnemy[i]->mY += dy;
		}

		break;
	}

	if (dx == 0) { mEnemy[i]->mDirection = 0; }
	if (dx < 0) { mEnemy[i]->mDirection = 1; }
	if (dx > 0) { mEnemy[i]->mDirection = 2; }
}

bool Enemy::checkOutOfField(int i) {
	if (mEnemy[i]->mX < -mEnemy[i]->mWidth || mEnemy[i]->mX > 600
		|| mEnemy[i]->mY < -mEnemy[i]->mHeight || mEnemy[i]->mY > 600) {
		return true;
	}
	else { return false; }
}