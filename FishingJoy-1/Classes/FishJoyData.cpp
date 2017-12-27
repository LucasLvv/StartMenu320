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
	//���ж��Ƿ��ǵ�һ��ʹ��
    _isBeginner = CCUserDefault::sharedUserDefault()->getBoolForKey(IS_BEGINER,true);
    if(_isBeginner == true){
		//��ǰxml�ļ�Ϊ�գ�������û�����ݵģ����ó�ʼ�����ݲ����浽xml�ļ���
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
    this->setGold(500);
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
	//�����ݳ�Ա��ֵ���浽xml�ļ�����
	CCUserDefault *userDefault = CCUserDefault::sharedUserDefault();
	userDefault->setBoolForKey(IS_BEGINER,_isBeginner);
	userDefault->setIntegerForKey(GOLD,_gold);
	userDefault->getBoolForKey(MUSIC,_isMusic);
	userDefault->getBoolForKey(SOUND,_isSound);
	userDefault->flush();
}
