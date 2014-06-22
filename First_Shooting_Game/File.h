#ifndef INCLUDED_FILE_H
#define INCLUDED_FILE_H

#include "Enemy.h"

class File {
public:
	void loadStageData();
	ENEMY* storeStageData(int i);
	int enemyNum();

private:
	ENEMY** mStageData;
	int row;
};

#endif