#ifndef INCLUDED_DEATHJUDGE_H
#define INCLUDED_DEATHJUDGE_H

class Player;
class Enemy;

class DeathJudge{
public:
	void update(Player* player, Enemy* enemy);

private:
	bool circleCollision(double c1r, double c1x, double c1y, double c2r, double c2x, double c2y);
};

#endif