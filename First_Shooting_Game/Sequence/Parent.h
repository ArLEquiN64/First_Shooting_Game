#ifndef INCLUDED_PARENT_H
#define INCLUDED_PARENT_H

namespace Sequence{
class Title;
class Menu;
namespace Game{
	class GParent;
}

class Parent{
public:
	enum SeqID{
		SEQ_TITLE,
		SEQ_GAME,
		SEQ_MENU,

		SEQ_NONE
	};
	Parent();
	~Parent();

	void update();
	void moveTo(SeqID);
private:
	Title* mTitle;
	Menu* mMenu;
	Game::GParent* mGame;
	SeqID mNext;
};
}	//namespace Sequence

#endif