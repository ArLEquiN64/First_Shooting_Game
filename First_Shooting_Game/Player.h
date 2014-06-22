#ifndef INCLUDED_PLAYER_H
#define INCLUDED_PLAYER_H

//グローバル変数
extern char gKey[256];	//キーステート

class Image;
class Shot;

class Player{
public:
	Player();
	~Player();
	void update();
	void draw();
	void getState(bool* live, double* px, double* py) { *px = mX; *py = mY; *live = mLive; };
	void getShotState(int i, bool* psLive, double* psx, double* psy);
	void setDeath() { mLive = false; };
	void setShotDeath(int i);

private:
	double mX;
	double mY;
	int mWidth;
	int mHeight;
	int mHitAreaSize;
	int mDirection;	//N:0, L:1, R:2

	bool mLive;
	int mLife;

	Image* mImage;
	Image* mHitArea;

	Shot* mShot;

	void drawScreen(int x, int y, int direction) const;
};

#endif