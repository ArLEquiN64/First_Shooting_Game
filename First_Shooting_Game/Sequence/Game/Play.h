#ifndef INCLUDED_SEQUENCE_GAME_PLAY_H
#define INCLUDED_SEQUENCE_GAME_PLAY_H

//グローバル変数
extern char gKey[256];		//キーステート

namespace Sequence{
namespace Game{

class GParent;

class Play{
public:
	Play();
	~Play();
	void update(GParent*);

private:
};

}	//namespace Game
}	//namespace Sequence

#endif