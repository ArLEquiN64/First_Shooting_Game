#ifndef INCLUDED_INFO_H
#define INCLUDED_INFO_H

class Image;
class StringRenderer;

class Player;

class Info {
public:
	Info();
	~Info();
	void update(Player*);
	void draw();

private:
	bool plive;
	double px, py;
	char* dpx;
	char* dpy;

	Image* mImage;
	StringRenderer* mStr;

};

#endif