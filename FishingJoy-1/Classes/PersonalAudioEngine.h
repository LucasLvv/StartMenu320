#ifndef PERSONALAUDIOENGINE_H
#define PERSONALAUDIOENGINE_H
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
USING_NS_CC;
using namespace CocosDenshion;

typedef enum{
	kEffectSwichCannon = 0,
	kEffectShoot,
	kEffectFishNet,
	kEffectCoins
} EffectType;

class PersonalAudioEngine : public SimpleAudioEngine
{
public:
	/*static void destoryIntance();*/
    static PersonalAudioEngine* sharedEngine();
    void playBackgroundMusic(int type);
    void playEffect(EffectType type);
	void setEffectsVolume(float volume);
	void setBackgroundMusicVolume(bool flag);
	bool init();
	PersonalAudioEngine(void);
	~PersonalAudioEngine(void);
	//void purge();
protected:
private:
};

#endif 
