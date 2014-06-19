#include "Sequence\Game\Clear.h"
#include "Sequence\Game\GParent.h"
#include "Image.h"
#include "Control.h"

namespace Sequence{
namespace Game{

Clear::Clear() : mImage(0), mCount(0){
	mImage = new Image("S:/images/Clear.png");
}

Clear::~Clear(){
	delete mImage;
	mImage = 0;
}

void Clear::update(GParent* parent){
	if (mCount == 60){ //60�t���[���ňړ�
		parent->moveTo(GParent::SEQ_MENU);
	}

	//�`��
	//�܂��Q�[����ʂ�`��
	parent->control()->draw();
	//��ɏj���̃��b�Z�[�W��`��
	mImage->draw();

	++mCount;
}

} //namespace Game
} //namespace Sequence
