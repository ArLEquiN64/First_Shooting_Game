#include "DxLib.h"
#include "Image.h"

Image::Image(const char* filename) :
mWidth(0),
mHeight(0){
	mHandle = LoadGraph(filename);
	GetGraphSize(mHandle, &mWidth, &mHeight);
}

Image::~Image(){
	DeleteGraph(mHandle);
}

int Image::width() const {
	return mWidth;
}

int Image::height() const {
	return mHeight;
}

void Image::draw(int x,int y) const {
	DrawGraph(x, y, mHandle, true);
}