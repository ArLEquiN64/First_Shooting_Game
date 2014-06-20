#include "DxLib.h"
#include "Image.h"
#include "File.h"
#include "Enemy.h"
#include "E_Shot.h"

extern int gCount;

Enemy::Enemy() {
	File file;
	file.loadStageData();
	mEnemyNum = file.enemyNum();
	for (int i = 0; i < mEnemyNum; i++) {
		mEnemy[i] = file.storeStageData(i);
		//mEnemy[i].mType = data.mType;						//種類
		//mEnemy[i].mBulletType = data.mBulletType;			//弾種類
		//mEnemy[i].mBulletSpeed = data.mBulletSpeed;			//弾速度
		//mEnemy[i].mMotionType = data.mMotionType;			//移動パターン
		//mEnemy[i].mShotType = data.mShotType;				//攻撃パターン
		//mEnemy[i].mInTime = data.mInTime;					//出現時間
		//mEnemy[i].mMoveTime = data.mMoveTime;				//移動時間
		//mEnemy[i].mStayTime = data.mStayTime;				//滞在時間
		//mEnemy[i].mShotTime = data.mShotTime;				//弾発射開始時間
		//mEnemy[i].mShootingTime = data.mShootingTime;		//弾発射時間

		//mEnemy[i].mHp = data.mHp;							//体力
		//mEnemy[i].mItem = data.mItem;						//アイテム

		mEnemy[i].mHitArea = 0;								//当たり判定
		mEnemy[i].mDirection = 0;							//N:0, L:1, R:2

		mEnemy[i].mImage = new Image("S:/images/KMAP弾幕風素材/その他ボス素材/dot_rumia.png");
		mEnemy[i].mWidth = mEnemy[i].mImage->width();		//画像幅
		mEnemy[i].mHeight = mEnemy[i].mImage->width();		//画像高さ

		mEnemy[i].mX -= mEnemy[i].mWidth / 2;		//x座標
		mEnemy[i].mY -= mEnemy[i].mHeight / 2;		//y座標

		mEnemy[i].mShot = new E_Shot();						//弾

		mEnemy[i].mLive = false;
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

void Enemy::update() {
	for(int i = 0; i < mEnemyNum; i++) {
		if (mEnemy[i].mHp > 0 && mEnemy[i].mInTime == gCount) { mEnemy[i].mLive = true; }
		if (mEnemy[i].mHp <= 0) { mEnemy[i].mLive = false; }
		if (mEnemy[i].mLive) {
			move(i);
			if (mEnemy[i].mInTime + mEnemy[i].mShotTime <= gCount
				&& gCount <= mEnemy[i].mInTime + mEnemy[i].mShotTime + mEnemy[i].mShootingTime
				&& gCount % 16 == 0) {
				mEnemy[i].mShot->fire(mEnemy[i].mX + mEnemy[i].mWidth / 2, mEnemy[i].mY + mEnemy[i].mHeight / 2);
			}
			checkOutOfField(i);
		}
		mEnemy[i].mShot->update();
	}
}


void Enemy::draw() {
	for (int i = 0; i < mEnemyNum; i++) {
		if (mEnemy[i].mLive) {
			drawScreen(mEnemy[i].mX, mEnemy[i].mY, mEnemy[i].mDirection);
		}
		mEnemy[i].mShot->draw();
	}
}

void Enemy::drawScreen(int x, int y, int direction)const {
	for (int i = 0; i < mEnemyNum; i++) {
		mEnemy[i].mImage->draw(x, y);
	}
}

void Enemy::move(int i) {
	int dx = 0;
	int dy = 0;

	switch (mEnemy[i].mMotionType) {
	case 0: break;
	case 1:							//上から出現→戻る
		dy = 2;

		if (mEnemy[i].mInTime <= gCount && gCount <= mEnemy[i].mInTime + mEnemy[i].mMoveTime) {
			mEnemy[i].mY += dy;
		}
		else if (mEnemy[i].mInTime + mEnemy[i].mStayTime <= gCount) {
			mEnemy[i].mY -= dy;
		}

		break;

	case 2:							//上から出現→左へ捌ける
		dx = -1;
		dy = 2;

		if (mEnemy[i].mInTime <= gCount && gCount <= mEnemy[i].mInTime + mEnemy[i].mMoveTime) {
			mEnemy[i].mX += dx;
			mEnemy[i].mY += dy;
		}
		else if (mEnemy[i].mInTime + mEnemy[i].mStayTime <= gCount) {
			mEnemy[i].mX += dx;
			mEnemy[i].mY += dy;
		}

		break;

	case 3:							//上から出現→右へ捌ける
		dx = 1;
		dy = 2;

		if (mEnemy[i].mInTime <= gCount && gCount <= mEnemy[i].mInTime + mEnemy[i].mMoveTime) {
			mEnemy[i].mX += dx;
			mEnemy[i].mY += dy;
		}
		else if (mEnemy[i].mInTime + mEnemy[i].mStayTime <= gCount) {
			mEnemy[i].mX += dx;
			mEnemy[i].mY += dy;
		}

		break;
	}

	if (dx == 0) { mEnemy[i].mDirection = 0; }
	if (dx < 0) { mEnemy[i].mDirection = 1; }
	if (dx > 0) { mEnemy[i].mDirection = 2; }
}

bool Enemy::checkOutOfField(int i) {
	if (mEnemy[i].mX < -mEnemy[i].mWidth || mEnemy[i].mX > 600
		|| mEnemy[i].mY < -mEnemy[i].mHeight || mEnemy[i].mY > 600) {
		return true;
	}
	else { return false; }
}