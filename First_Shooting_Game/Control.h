#ifndef INCLUDED_CONTROL_H
#define INCLUDED_CONTROL_H

class Scenery;
class Player;
class Enemy;

class Image;

class Control {
public:
	Control();
	~Control();
	void update();
	void draw();
	void reset();

private:
	Scenery* mScenery;
	Player* mPlayer;
	Enemy* mEnemy;
};

#endif