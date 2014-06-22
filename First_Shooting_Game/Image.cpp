#include "DxLib.h"
#include "Image.h"

Image::Image(const char* filename,double extendRate) : mDivFlag(false){
	mFileName = filename;
	mBaseHandle = LoadGraph(mFileName);
	GetGraphSize(mBaseHandle,&mBaseWidth,&mBaseHeight);
	mExtendRate=extendRate;
}

Image::~Image(){
	DeleteGraph(mBaseHandle);
	DeleteGraph(mBuffHandle);
	for(int i=0;i<mDivNum;i++){
		DeleteGraph(mDivHandle[i]);
	}
	delete mDivHandle;
	mDivHandle = 0;
}

int Image::width() const {
	return mDivFlag==true ? mDivWidth : mBaseWidth;
}

int Image::height() const {
	return mDivFlag==true ? mDivHeight : mBaseHeight;
}

void Image::setDivGraph(int rectX, int rectY, int sizeX, int sizeY, int xNum, int yNum){
	mDivHandle = new int[xNum*yNum];
	mDivWidth = sizeX;
	mDivHeight = sizeY;
	mBuffHandle = DerivationGraph(rectX,rectY,sizeX*xNum,sizeY*yNum,mBaseHandle);
	for(int y=0;y<yNum;y++){
		for(int x=0;x<xNum;x++){
			mDivHandle[xNum*y+x] = DerivationGraph(x*sizeX,y*sizeY,sizeX,sizeY,mBuffHandle);
		}
	}
	mDivFlag = true;
}

void Image::setAnimetion() {

}

void Image::draw(int x,int y,int i) const {
	mDivFlag==true ? DrawGraph(x, y, mDivHandle[i], true) : DrawGraph(x,y,mBaseHandle,true);
}

void Image::rotationDraw(int x,int y,int i,double angle)const{
	mDivFlag==true?
		DrawRotaGraph(x,y,mExtendRate,angle,mDivHandle[i],true) :
		DrawRotaGraph(x,y,mExtendRate,angle,mBaseHandle,true);
}