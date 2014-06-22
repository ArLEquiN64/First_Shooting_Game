#ifndef INCLUDED_CONTROL_H
#define INCLUDED_CONTROL_H

class Scenery;
class Player;
class Enemy;
class DeathJudge;

class Image;

class Control {
public:
	Control();
	~Control();
	void update();
	void draw();
	void reset();

	Player* player();
	Enemy* enemy();

private:
	Scenery* mScenery;
	Player* mPlayer;
	Enemy* mEnemy;
	DeathJudge* mJudge;

	bool E_shotFlag;
	bool P_shotFlag;
	int E_shotSound;
	int P_shotSound;
};

#endif