#ifndef INCLUDED_PLAYER_H
#define INCLUDED_PLAYER_H

//グローバル変数
extern char gKey[256];	//キーステート

class Image;
class Enemy;
class Shot;

class Player{
public:
	Player();
	~Player();
	void update(Enemy*);
	void draw();
	void getState(bool* live, double* px, double* py) { *px = mX; *py = mY; *live = mLive; };
	void getShotState(int sNum, bool* psLive, double* psx, double* psy);
	void setDeath();
	void setShotDeath(int sNum);
	bool life() { return mLife == 0 ? true : false; };
	double shotDamgage();

private:
	double mX;
	double mY;
	int mWidth;
	int mHeight;
	int mHitAreaSize;
	int mDirection;	//N:0, L:1, R:2

	bool mLive;
	int mLife = 5;
	bool mReborn;
	int mRebornCount;
	bool mDying;
	int mDyingCount;

	Image* mImage;
	int* nomal;
	Image* mHitArea;

	Shot* mShot;

	void drawScreen(int x, int y, int direction) const;
};

#endif