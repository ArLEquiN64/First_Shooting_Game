#ifndef INCLUDED_SEQUENCE_GAME_PLAY_H
#define INCLUDED_SEQUENCE_GAME_PLAY_H

namespace Sequence{
namespace Game{

class GParent;

class Play{
public:
	Play();
	~Play();
	void update(GParent*);
};

}	//namespace Game
}	//namespace Sequence

#endif