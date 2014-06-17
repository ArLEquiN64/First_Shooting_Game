#ifndef INCLUDED_SEQUENCE_GAME_PARENT_H
#define INCLUDED_SEQUENCE_GAME_PARENT_H

class State;

namespace Sequence{
class Parent;

namespace Game{

class Clear;
class Loading;
class Pause;
class Play;

class GParent{
public:
	//typedef Sequence::Parent GrandParent;	//�c��
	enum SeqID{
		SEQ_MENU,	//��K�w
		SEQ_TITLE,	//��K�w
		SEQ_CLEAR,
		SEQ_PAUSE,
		SEQ_PLAY,

		SEQ_NONE,
	};
	GParent();
	~GParent();
	void moveTo(SeqID);
	void update(Parent*);
	void startLoading();
	State* state();

private:
	State* mState;
	SeqID mNext;

	Play* mPlay;
	Loading* mLoading;
	Pause* mPause;
	Clear* mClear;
};

}	//namespace Game
}	//namespace Sequence

#endif