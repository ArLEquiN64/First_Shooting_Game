#ifndef INCLUDED_SEQUENCE_GAME_PARENT_H
#define INCLUDED_SEQUENCE_GAME_PARENT_H

class Control;
class Scenery;
class Player;
class Enemy;

namespace Sequence{
class Parent;

namespace Game{

class Clear;
class Loading;
class Pause;
class Play;

class GParent{
public:
	//typedef Sequence::Parent GrandParent;	//ëcïÉ
	enum SeqID{
		SEQ_MENU,	//è„äKëw
		SEQ_TITLE,	//è„äKëw
		SEQ_CLEAR,
		SEQ_PAUSE,
		SEQ_PLAY,
		SEQ_GAMEOVER,

		SEQ_NONE,
	};
	GParent();
	~GParent();
	void moveTo(SeqID);
	void update(Parent*);
	void startLoading();
	Control* control();

private:
	Control* mControl;
	Scenery* mScenery;
	Player* mPlayer;
	Enemy* mEnemy;
	SeqID mNext;

	Play* mPlay;
	Loading* mLoading;
	Pause* mPause;
	Clear* mClear;
};

}	//namespace Game
}	//namespace Sequence

#endif