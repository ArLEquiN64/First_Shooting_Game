#ifndef INCLUDED_STATE_H
#define INCLUDED_STATE_H
#include "DxLib.h"

class State{
public:
	State(char status, int x=0, int y=0);
	~State(){
		delete[] index;
		index = 0; //ポインタに0を入れるのはクセにしよう。
	}
	void update();
	void draw();

private:
	enum Status{
		STATUS_PLAYER,
		STATUS_ENEMY,
		STATES_BULLET,

		STATUS_UNKNOWN
	};
	Status s;
	int x;
	int y;
	int sizex;
	int sizey;
	int imgname;

	int* index = new int[x*y];
	
	void drawScreen(int x, int y);
};

#endif