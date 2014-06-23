#ifndef INCLUDED_STRINGRENDERER_H
#define INCLUDED_STRINGRENDERER_H

class Image;

class StringRenderer {
public:
	StringRenderer();
	~StringRenderer();
	void drawBig(int x, int y, const char* str);
	void draw(int x, int y, const char* str);

private:
	Image* mBigString;
	Image* mString;

};

#endif