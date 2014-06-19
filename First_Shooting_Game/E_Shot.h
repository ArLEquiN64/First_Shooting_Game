#ifndef INCLUDED_E_SHOT_H
#define INCLUDED_E_SHOT_H

#define BULLET 128	//‚ ‚Æ‚Å‚È‚ñ‚Æ‚©‚·‚é

class Image;

struct E_SHOT {
	bool live;
	double x;
	double y;
};

class E_Shot {
public:
	E_Shot();
	~E_Shot();
	void fire(int x, int y);
	void update();
	void draw();

private:
	E_SHOT shot[BULLET];

	Image* mImage;
};

#endif