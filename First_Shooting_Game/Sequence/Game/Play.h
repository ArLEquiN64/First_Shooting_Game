#ifndef INCLUDED_SEQUENCE_GAME_PLAY_H
#define INCLUDED_SEQUENCE_GAME_PLAY_H

//�O���[�o���ϐ�
extern char gKey[256];		//�L�[�X�e�[�g

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