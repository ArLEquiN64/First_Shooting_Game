#ifndef INCLUDED_SEQUENCE_GAME_LOADING_H
#define INCLUDED_SEQUENCE_GAME_LOADING_H

class Image;
class StringRenderer;

namespace Sequence{
namespace Game{

class GParent;

class Loading{
public:
	Loading();
	~Loading();
	void update(GParent*);
private:
	Image* mImage;
	StringRenderer* mStr;
	int mCount;
	bool mStarted; //ロード開始要請を出したか
};

} //namespace Game
} //namespace Sequence

#endif