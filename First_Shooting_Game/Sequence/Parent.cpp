#include "Sequence\Parent.h"
#include "Sequence\Title.h"
#include "Sequence\Menu.h"
#include "Sequence\Game\GParent.h"

namespace Sequence{

Parent::Parent() :
	mTitle(0), mMenu(0), mGame(0), mNext(SEQ_NONE){
	mTitle = new Title();
}

Parent::~Parent(){
	delete mTitle;
	mTitle = 0;
	delete mMenu;
	mMenu = 0;
	delete mGame;
	mGame = 0;
}

void Parent::update(){
	if (mTitle){
		mTitle->update(this);
	}
	else if (mMenu){
		mMenu->update(this);
	}
	else if (mGame){
		mGame->update(this);
	}
	else{
		return;
	}

	//‘JˆÚ”»’è
	switch (mNext){
	case SEQ_MENU:
		delete mTitle;
		mTitle = 0;
		delete mGame;
		mGame = 0;
		mMenu = new Menu();
		break;
	case SEQ_TITLE:
		delete mGame;
		mGame = 0;
		mTitle = new Title();
		break;
	case SEQ_GAME:
		delete mMenu;
		mMenu = 0;
		mGame = new Game::GParent();
		break;
	}
	mNext = SEQ_NONE;
}

void Parent::moveTo(SeqID next){
	mNext = next;
}

}	//namespace Sequence