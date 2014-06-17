#ifndef INCLUDED_SEQUENCE_GAME_PAUSE_H
#define INCLUDED_SEQUENCE_GAME_PAUSE_H

class Image;

namespace Sequence{
namespace Game{
class GParent;

class Pause{
public:
	Pause();
	~Pause();
	void update(GParent*);
private:
	Image* mImage;
};

} //namespace Game
} //namespace Sequence

#endif