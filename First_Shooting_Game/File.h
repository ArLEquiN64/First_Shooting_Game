#ifndef INCLUDED_FILE_H
#define INCLUDED_FILE_H

#include "Enemy.h"

class File {
public:
	~File() {
		delete[] mStageData;
		mStageData = 0;
	};
	void loadStageData();
	ENEMY* storeStageData();
	int enemyNum();

private:
	ENEMY* mStageData;
	int row;
};

#endif