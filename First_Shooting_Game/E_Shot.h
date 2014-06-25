#ifndef INCLUDED_E_SHOT_H
#define INCLUDED_E_SHOT_H

#define BULLET 128	//‚ ‚Æ‚Å‚È‚ñ‚Æ‚©‚·‚é

class Image;
class Enemy;
class Player;

struct E_SHOT {
	bool live;
	double x;
	double y;
	double rad;
};

class E_Shot {
public:
	E_Shot();
	~E_Shot();
	void fire(double x, double y, int shotType, Player*);
	void update(int shotType, Player*);
	void draw();
	E_SHOT getState(int i) { return mShot[i]; };
	void setDeath(int sNum) { mShot[sNum].live = false; };

private:
	double rad;
	int msCount;
	int num;
	E_SHOT* mShot;

	Image* mImage;
};

#endif