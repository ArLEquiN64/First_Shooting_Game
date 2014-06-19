#ifndef INCLUDED_ENEMY_H
#define INCLUDED_ENEMY_H

class Image;
class E_Shot;

class Enemy{
public:
	Enemy();
	~Enemy();
	void update();
	void draw();

private:
	int mX;
	int mY;
	int mWidth;
	int mHeight;
	int mHitArea;
	int mDirection;	//N:0, L:1, R:2
	int mHp;
	bool mDeath;

	int mInTime;
	int mStopTime;
	int mOutTime;
	int mShotInTime;
	int mShotOutTime;

	Image* mImage;

	E_Shot* mShot;

	void drawScreen(int x, int y, int direction) const;
};

#endif