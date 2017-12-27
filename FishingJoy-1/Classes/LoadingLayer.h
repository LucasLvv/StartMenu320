#ifndef LOADINGLAYER_H
#define LOADINGLAYER_H
#include "cocos2d.h"
#include "ProgressDelegate.h"
#include "ProgressBar.h"
USING_NS_CC;

class LoadingLayer : public CCLayer, public ProgressDelegate
{
public:
    
    bool init();
	LoadingLayer();
	static CCScene* scene();
    CREATE_FUNC(LoadingLayer);

protected:
    ProgressBar* _progressBar;
    CCLabelTTF* _progressFg;
	int _numSp;
	int _loadedSp;

    void cacheInit(float delta);
	void loadingFinished();
	void progressPercentageSetter(float percentage);
	void initProgressBar();
};

#endif
