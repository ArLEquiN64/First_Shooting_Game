#ifndef INCLUDED_FILE_H
#define INCLUDED_FILE_H

#include "Enemy.h"

class File {
public:
	~File();
	void loadStageData();
	ENEMY* storeStageData();
	int enemyNum();

private:
	ENEMY* mStageData;
	int row;
	int mEnemyNum;
};

#endif