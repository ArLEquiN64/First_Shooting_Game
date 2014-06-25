#include "DxLib.h"
#include "Image.h"

extern int gCount;

Image::Image(const char* filename,double baseExtendRate) : mDivFlag(false), mAnimeFlag(false) {
	mFileName = filename;
	mBaseHandle = LoadGraph(mFileName);
	GetGraphSize(mBaseHandle,&mBaseWidth,&mBaseHeight);
	mBaseExtendRate=baseExtendRate;
}

Image::~Image(){
	DeleteGraph(mBaseHandle);
	DeleteGraph(mBuffHandle);
	for(int i=0;i<mDivNum;i++){
		DeleteGraph(mDivHandle[i]);
	}
	if (mDivFlag) {
		delete mDivHandle;
		mDivHandle = 0;
	}
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

void Image::setAnimetion(int animeNum, int animeDef[], int animeSize, int frameRate) {
	if (mDivFlag) {
		mAnimeSize[animeNum] = animeSize;
		for (int i = 0; i < mAnimeSize[animeNum]; i++) {
			mAnimeDef[animeNum][i] = animeDef[i];
		}
		mFrameRate = frameRate;
		mAnimeFlag = true;
	}
}

void Image::setEffect(int divNum) {
	ext = 0.01;
	ang = 0;
}

void Image::draw(int x,int y,int i) const {
	(mDivFlag == true) ? DrawGraph(x, y, mDivHandle[i], true) : DrawGraph(x, y, mBaseHandle, true);
}

void Image::rotationDraw(int x, int y, int i, double extendRate, double angle) const {
	if (mDivFlag) { DrawRotaGraph(x, y, mBaseExtendRate*extendRate, angle, mDivHandle[i], true); }
	else { DrawRotaGraph(x, y, mBaseExtendRate*extendRate, angle, mBaseHandle, true); }
}

void Image::animationDraw(int x, int y, int animeNum, double extendRate, double angle) const {
	rotationDraw(x, y, mAnimeDef[animeNum][((gCount - gCount % mFrameRate) / mFrameRate) % mAnimeSize[animeNum]], extendRate, angle);
}

void Image::drawEffect(int x, int y) {
	if (mEffectCount <= 20) {
		ext += 0.01;
		ang = GetRand(360) * 3.14 / 180;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		int xrand, yrand;
		xrand = GetRand(10);
		yrand = GetRand(10);
		DrawRotaGraph3(x, y, 32, 32, ext*xrand, ext*yrand, ang, mDivHandle[0], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		mEffectCount++;
	}
}