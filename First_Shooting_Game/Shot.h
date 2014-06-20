#ifndef INCLUDED_SHOT_H
#define INCLUDED_SHOT_H

#define BULLET 128	//あとでなんとかする

//グローバル変数
extern char gKey[256];	//キーステート

class Image;

struct SHOT{
	bool live;
	double x;
	double y;
};

class Shot{
public:
	Shot();
	~Shot();
	void update(int x,int y);
	void draw();

private:
	SHOT mShot[BULLET];

	Image* mImage;
};

#endif