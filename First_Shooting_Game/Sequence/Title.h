#ifndef INCLUDED_TITLE_H
#define INCLUDED_TITLE_H

//�O���[�o���ϐ�
extern char gKey[256];		//�L�[�X�e�[�g
extern bool endRequest;	//�Q�[���I���t���O

class Image;

namespace Sequence{

class Parent;

class Title{
public:
	Title();
	~Title();
	void update(Parent*);
private:
	Image* mImage;
};
}	//namespace Sequence
#endif