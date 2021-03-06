#pragma once
#include "cocos2d.h"
#include "StaticData.h"
#include "Fish.h"
USING_NS_CC;

class FishLayer :
public CCLayer
{
public:
	FishLayer(void);
	CREATE_FUNC(FishLayer)
	virtual bool init();
	virtual ~FishLayer(void);
	CCArray *getFishArray()
	{
		return _fishes;
	}
protected:
	CCArray* _fishes;
	void addFish(float delta);
	void resetFish(Fish* fish);
};
