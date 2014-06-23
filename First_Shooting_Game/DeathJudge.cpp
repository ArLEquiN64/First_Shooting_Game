#include "Player.h"
#include "Enemy.h"
#include "DeathJudge.h"
#define _USE_MATH_DEFINES
#include <math.h>

#define P_R		3
#define P_S_R	5
#define E_R		10
#define E_S_R	5

void DeathJudge::update(Player* player, Enemy* enemy) {
	bool plive, pslive, elive, eslive;
	double px, py, psx, psy, ex, ey, esx, esy;

	for (int psi = 0; psi < 128; psi++) {
		player->getShotState(psi, &pslive, &psx, &psy);
		if (pslive == true) {
			for (int ei = 0; ei < enemy->enemyNum(); ei++) {
				enemy->getState(ei, &elive, &ex, &ey);
				if (elive == true && circleCollision(P_S_R, psx, psy, E_R, ex, ey)) {
					enemy->setDamage(ei, 1);
					player->setShotDeath(psi);
				}
			}
		}
	}

	for (int eNum = 0; eNum < enemy->enemyNum(); eNum++) {
		for (int esi = 0; esi < 128; esi++) {
			enemy->getShotState(eNum, esi, &eslive, &esx, &esy);
			if (eslive == true) {
				player->getState(&plive, &px, &py);
				if (plive == true && circleCollision(E_S_R, esx, esy, P_R, px, py)) {
					player->setDeath();
					enemy->setShotDeath(eNum, esi);
				}
			}
		}
	}
}

bool DeathJudge::circleCollision(double c1r, double c1x, double c1y, double c2r, double c2x, double c2y) {
	double hlength = c1r + c2r;
	double xlength = c1x - c2x;
	double ylength = c1y - c2y;

	if (hlength*hlength >= xlength*xlength + ylength*ylength) {
		return true;
	}
	else {
		return false;
	}
}