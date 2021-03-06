#ifndef INCLUDED_ENEMY_H
#define INCLUDED_ENEMY_H

#define ENEMY_NUM 60	//あとでなんとかする

class Image;
class Player;
class E_Shot;

struct ENEMY {
	int mType;				//種類
	int mBulletType;		//弾種類
	int mBulletSpeed;		//弾速度
	int mBulletColor;		//弾色
	int mMotionType;		//移動パターン
	int mShotType;			//攻撃パターン
	int mInTime;			//出現時間
	int mMoveTime;			//移動時間
	int mStayTime;			//滞在時間
	int mShotTime;			//弾発射開始時間
	int mShootingTime;		//弾発射時間
	double mX;				//x座標
	double mY;				//y座標
	double mHp;				//体力
	int mItem;				//アイテム

	int mWidth;				//幅
	int mHeight;			//高さ
	int mHitArea;			//当たり判定
	int mDirection;			//N:0, L:1, R:2

	bool mLive;				//出現フラグ
	bool mDying;			//消滅フラグ
	int mDyingCount;

	double dx;
	double dy;

	Image* mImage;
	Image* mEffect;
	E_Shot* mShot;
};

class Enemy{
public:
	Enemy();
	~Enemy();
	void update(Player*);
	void draw();
	int enemyNum(){return mEnemyNum;};
	void getState(int i, bool* eLive, double* eX, double* eY) {
		*eLive = mEnemy[i].mLive; *eX = mEnemy[i].mX; *eY = mEnemy[i].mY;
	};
	void getShotState(int eNum, int i, bool*  esLive, double* esx, double* esy);
	void setDamage(int i, double damage) { mEnemy[i].mHp -= damage; };
	void setShotDeath(int eNum, int sNum);

private:
	int mEnemyNum;
	ENEMY* mEnemy;
	int* nomal;
	int* left;
	int* right;

	void move(int i);
	bool checkOutOfField(int i);
	void drawScreen(int x, int y, int direction) const;
};

#endif