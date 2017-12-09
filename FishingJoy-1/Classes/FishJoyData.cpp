#include "FishJoyData.h"
#include "StaticData.h"
USING_NS_CC;
#define IS_BEGINER "isBeginer"
#define MUSIC		"music"
#define SOUND		"sound"
#define GOLD		"gold"

static FishJoyData* _sharedFishJoyData = NULL;

FishJoyData* FishJoyData::sharedFishJoyData()
{
    if(_sharedFishJoyData == NULL){
        _sharedFishJoyData = new FishJoyData();
        _sharedFishJoyData->init();
    }
    return _sharedFishJoyData;
}

void FishJoyData::destoryIntance(){
	CC_SAFE_DELETE(_sharedFishJoyData);
}


/*
void FishJoyData::purge()
{
    CC_SAFE_RELEASE_NULL(_sharedFishJoyData);
}*/
FishJoyData::FishJoyData()
{
    
}
FishJoyData::~FishJoyData()
{
    this->flush();
}
bool FishJoyData::init()
{
	//先判断是否是第一次使用
    _isBeginner = CCUserDefault::sharedUserDefault()->getBoolForKey(IS_BEGINER,true);
    if(_isBeginner == true){
		//当前xml文件为空，里面是没有数据的，设置初始的数据并保存到xml文件中
        this->reset();
        this->flush();
    }else{
      CCUserDefault *userDefault = CCUserDefault::sharedUserDefault();
	  this->setGold(userDefault->getIntegerForKey(GOLD));
	  this->setisMusic(userDefault->getBoolForKey(MUSIC));
	  this->setisSound(userDefault->getBoolForKey(SOUND));

    }
    return true;
}
void FishJoyData::reset()
{
    //int gold = STATIC_DATA_INT("default_gold");
    this->setGold(700);
    this->setIsBeginner(true);
    this->setisMusic(true);
    this->setisSound(true);
    this->flush();
}
void FishJoyData::alterGold(int golds)
{
    //this->setGold(this->getGold()+delta);
	int num = getGold();
	num+=golds;
	setGold(num);
	flush();
}
void FishJoyData::flush()
{
    //CCUserDefault::sharedUserDefault()->setBoolForKey(IS_BEGINER,getIsBeginner());
    //CCUserDefault::sharedUserDefault()->setIntegerForKey(GOLD,getGold());
    //CCUserDefault::sharedUserDefault()->setBoolForKey(MUSIC,getisMusic());
    //CCUserDefault::sharedUserDefault()->setBoolForKey(SOUND,getisSound());
    //CCUserDefault::sharedUserDefault()->flush();
    //CCUserDefault::sharedUserDefault()->purgeSharedUserDefault();

	//将数据成员的值保存到xml文件里面
	CCUserDefault *userDefault = CCUserDefault::sharedUserDefault();
	userDefault->setBoolForKey(IS_BEGINER,_isBeginner);
	userDefault->setIntegerForKey(GOLD,_gold);
	userDefault->setBoolForKey(MUSIC,_isMusic);
	userDefault->setBoolForKey(SOUND,_isSound);
	userDefault->flush();
}
