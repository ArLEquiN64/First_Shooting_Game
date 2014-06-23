#ifndef INCLUDED_SEQUENCE_MENU_H
#define INCLUDED_SEQUENCE_MENU_H

//�O���[�o���ϐ�
extern char gKey[256];		//�L�[�X�e�[�g

class Image;
class StringRenderer;

namespace Sequence{
class Parent;

class Menu{
public:
	Menu();
	~Menu();
	void update(Parent* parent);
private:
	Image* mImage;
	StringRenderer* str;
};

} //namespace Sequence

#endif