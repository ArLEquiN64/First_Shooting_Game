#ifndef INCLUDED_SEQUENCE_GAME_CLEAR_H
#define INCLUDED_SEQUENCE_GAME_CLEAR_H

class Image;

namespace Sequence{
namespace Game{
class GParent;

class Clear{
public:
	Clear();
	~Clear();
	void update(GParent*);
private:
	Image* mImage;
	int mCount;
};

} //namespace Game
} //namespace Sequence

#endif