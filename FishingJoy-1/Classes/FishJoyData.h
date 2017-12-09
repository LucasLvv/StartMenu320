#ifndef _FISH_JOY_DATA_H_
#define _FISH_JOY_DATA_H_
#include "cocos2d.h"
class FishJoyData:public cocos2d::CCObject
{
public:
    static FishJoyData* sharedFishJoyData();
	static void destoryIntance();
    CC_SYNTHESIZE(int , _gold, Gold);
    CC_SYNTHESIZE(bool, _isBeginner, IsBeginner);
    CC_SYNTHESIZE(bool, _isSound, isSound);
    CC_SYNTHESIZE(bool, _isMusic, isMusic);
  
/*    void purge();*/
	//将内存的数值保存的文档中
    void flush();
    void alterGold(int golds);
    void reset();
protected:
    FishJoyData();
    ~FishJoyData();
    bool init();
};

#endif