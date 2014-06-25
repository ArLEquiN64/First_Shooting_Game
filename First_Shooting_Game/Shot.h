#ifndef INCLUDED_SHOT_H
#define INCLUDED_SHOT_H

#define BULLET 128	//あとでなんとかする

//グローバル変数
extern char gKey[256];	//キーステート

class Image;
class Enemy;

struct SHOT{
	bool live;
	double x;
	double y;
};

class Shot{
public:
	Shot();
	~Shot();
	void update(int x, int y, Enemy*);
	void draw();
	SHOT state(int i){return mShot[i];};
	void setDeath(int i) { mShot[i].live = false; };

private:
	SHOT* mShot;
	
	Image* mImage;
};

#endif