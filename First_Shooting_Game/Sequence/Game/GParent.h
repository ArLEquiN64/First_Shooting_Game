#ifndef INCLUDED_SEQUENCE_GAME_PARENT_H
#define INCLUDED_SEQUENCE_GAME_PARENT_H

class State;

namespace Sequence{
class Parent;

namespace Game{

//class Clear;
//class Loading;
//class Menu;
//class Play;

class GParent{
public:
	//typedef Sequence::Parent GrandParent;	//ëcïÉ
	enum SeqID{
		SEQ_MENU,	//è„äKëw
		SEQ_TITLE,	//è„äKëw
		SEQ_CLEAR,
		SEQ_PAUSE,
		SEQ_PLAY,

		SEQ_NONE,
	};

	void update(Parent*);

private:
	State* mState;
	SeqID mNext;
};

}	//namespace Game
}	//namespace Sequence

#endif