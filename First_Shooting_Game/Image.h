#ifndef INCLUDED_IMAGE_H
#define INCLUDED_IMAGE_H

class Image{
public:
	Image();
	~Image();
	int width() const;
	int height() const;
	void draw() const;
private:
	int mWidth;
	int mHeight;
	unsigned* mData;
};

#endif