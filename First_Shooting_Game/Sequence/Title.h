#ifndef INCLUDED_TITLE_H
#define INCLUDED_TITLE_H

//グローバル変数
extern char gKey[256];		//キーステート
extern bool endRequest;	//ゲーム終了フラグ

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