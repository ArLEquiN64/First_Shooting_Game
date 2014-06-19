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

private:
	int mX;
	int mY;
	int mWidth;
	int mHeight;
	int mHitAreaSize;
	int mDirection;	//N:0, L:1, R:2

	bool mDeath;
	int mLife;

	Image* mImage;
	Image* mHitArea;

	Shot* mShot;

	void drawScreen(int x, int y, int direction) const;
};

#endif