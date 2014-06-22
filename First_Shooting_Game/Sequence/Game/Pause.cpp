#include "DxLib.h"
#include "Image.h"
#include "Control.h"
#include "Sequence\Game\Pause.h"
#include "Sequence\Game\GParent.h"

namespace Sequence{
namespace Game{

Pause::Pause() : mImage(0){
	mImage = new Image("S:/materials/Images/Pause.png");
}

Pause::~Pause(){
	delete mImage;
	mImage = 0;
}

void Pause::update(GParent* parent){
	//1:���Ȃ���
	//2:���j���[��
	//3:�^�C�g����ʂ�
	//4:�߂�
	//�Y�����������Ɩʓ|�Ȃ̂�0������Ă���
	if (gKey[KEY_INPUT_1]) {	//���Ȃ���
		parent->control()->reset();
		parent->moveTo(GParent::SEQ_PLAY);
	}
	if (gKey[KEY_INPUT_2]){	//���j���[��
		parent->moveTo(GParent::SEQ_MENU);
	}
	if (gKey[KEY_INPUT_3]){	//�^�C�g����
		parent->moveTo(GParent::SEQ_TITLE);
	}
	if (gKey[KEY_INPUT_4]){	//���̂܂ܖ߂�
		parent->moveTo(GParent::SEQ_PLAY);
	}	//���̑��͖���

	//�`��
	//�܂��Q�[�����
	parent->control()->draw();
	//��ɏd�˂�
	mImage->draw();
}


} //namespace Game
} //namespace Sequence