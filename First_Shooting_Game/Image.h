#ifndef INCLUDED_IMAGE_H
#define INCLUDED_IMAGE_H

class Image{
public:
	Image(const char* filename);
	~Image();
	int width() const;
	int height() const;
	void draw(int x=0,int y=0) const;
private:
	int mHandle;
	int mWidth;
	int mHeight;
};

#endif