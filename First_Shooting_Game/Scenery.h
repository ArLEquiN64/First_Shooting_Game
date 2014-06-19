#ifndef INCLUDED_SCENERY_H
#define INCLUDED_SCENERY_H

class Image;

class Scenery {
public:
	Scenery();
	~Scenery();
	void update();
	void draw();

private:
	int x;
	int y;
	int mHeight;
	Image* mImage;
};

#endif