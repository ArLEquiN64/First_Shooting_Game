#include "Sequence\Game\GParent.h"
#include "Sequence\Game\Play.h"
#include "Sequence\Game\Loading.h"
#include "Sequence\Game\Pause.h"
#include "Sequence\Game\Clear.h"
#include "Sequence\Parent.h"
#include "State.h"

namespace Sequence{
namespace Game{

GParent::GParent() :
	mState(0),
	mNext(SEQ_NONE),
	mClear(0),
	mLoading(0),
	mPause(0),
	mPlay(0){
	//Å‰‚Éƒ[ƒh
	mLoading = new Loading();
}

GParent::~GParent(){
	delete mState;
	mState = 0;
	delete mClear;
	mClear = 0;
	delete mLoading;
	mLoading = 0;
	delete mPause;
	mPause = 0;
	delete mPlay;
	mPlay = 0;
}

void GParent::update(Parent* parent){
	if (mClear){
		mClear->update(this);
	}
	else if (mLoading){
		mLoading->update(this);
	}
	else if (mPause){
		mPause->update(this);
	}
	else if (mPlay){
		mPlay->update(this);
	}
	else{
		
	}
	//‘JˆÚ”»’è
	switch (mNext){
	case SEQ_MENU:
		parent->moveTo(Parent::SEQ_MENU); //ŠÛ“Š‚°
		break;
	case SEQ_TITLE:
		parent->moveTo(Parent::SEQ_TITLE); //ŠÛ“Š‚°
		break;
	case SEQ_PLAY:
		delete mLoading;
		mLoading = 0;
		delete mPause;
		mPause = 0;
		mPlay = new Game::Play();
		break;
	case SEQ_CLEAR:
		delete mPlay;
		mPlay = 0;
		mClear = new Game::Clear();
		break;
	case SEQ_PAUSE:
		delete mPlay;
		mPlay = 0;
		mPause = new Game::Pause();
		break;
	}
	mNext = SEQ_NONE;
}

void GParent::startLoading(){
}

void GParent::moveTo(SeqID next){
	mNext = next;
}

State* GParent::state(){
	return mState;
}

}	//namespace game
}	//namespace Sequence