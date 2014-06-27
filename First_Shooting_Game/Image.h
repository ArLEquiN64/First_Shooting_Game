#ifndef INCLUDED_IMAGE_H
#define INCLUDED_IMAGE_H

class Image{
public:
	Image(const char* filename, double baseExtendRate = 1.0);
	~Image();
	int width() const;
	int height() const;
	void setDivGraph(int rectX, int rectY, int sizeX, int sizeY, int xNum, int yNum);
	void setAnimetion(int animeNum, int animeDef[], int animeSize, int frameRate);
	void setEffect(int divNum);
	void setTurn(bool flag) { mTurnFlag = flag ? true : false; };
	void draw(int x = 0, int y = 0, int i = 0) const;
	void rotationDraw(int x = 0, int y = 0, int i = 0, double extendRate = 1.0, double angle = 0) const;
	void animationDraw(int x = 0, int y = 0, int animeNum = 0, double extendRate = 1.0, double angle = 0);
	void drawEffect(int x, int y);

private:
	const char* mFileName;
	int mBaseHandle;
	int mBaseWidth;
	int mBaseHeight;
	int mBuffHandle;
	bool mTurnFlag;
	bool mDivFlag;
	int* mDivHandle;
	int mDivNum;
	int mDivWidth;
	int mDivHeight;
	double mBaseExtendRate;
	bool mAnimeFlag;
	int mAnimeDef[8][64];
	int mAnimeSize[8];
	int mAnimeCount[8];
	int mFrameRate;
	int mEffectCount;
	double ext;
	double ang;
};

#endif