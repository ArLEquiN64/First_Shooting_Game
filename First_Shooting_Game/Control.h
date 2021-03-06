#ifndef INCLUDED_CONTROL_H
#define INCLUDED_CONTROL_H

class Scenery;
class Info;
class Player;
class Enemy;
class DeathJudge;

namespace Sequence { namespace Game { class GParent; } }

class Image;

class Control {
public:
	Control();
	~Control();
	void update(Sequence::Game::GParent*);
	void draw();
	void reset();

private:
	Scenery* mScenery;
	Info* mInfo;
	Player* mPlayer;
	Enemy* mEnemy;
	DeathJudge* mJudge;

	bool E_shotFlag;
	bool P_shotFlag;
	int E_shotSound;
	int P_shotSound;
};

#endif