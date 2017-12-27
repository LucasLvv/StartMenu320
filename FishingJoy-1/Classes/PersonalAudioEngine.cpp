#include "PersonalAudioEngine.h"
#include "FishJoyData.h"
//static PersonalAudioEngine* s_sharedEngine;
static PersonalAudioEngine* _sharedEngine = NULL;

PersonalAudioEngine* PersonalAudioEngine::sharedEngine()
{
    if(_sharedEngine==NULL){
        _sharedEngine = new PersonalAudioEngine();
        _sharedEngine->init();
    }
    return _sharedEngine;
}

// void PersonalAudioEngine::destoryIntance()
// {
// 	delete _sharedEngine;
// 	_sharedEngine = NULL;
// 	CC_SAFE_DELETE(_sharedEngine);
// }

PersonalAudioEngine::PersonalAudioEngine(void)
{

}

PersonalAudioEngine::~PersonalAudioEngine(void)
{

}
bool PersonalAudioEngine::init()
{
    this->preloadBackgroundMusic("music_1.mp3");
	this->preloadBackgroundMusic("music_3.mp3");
	this->preloadBackgroundMusic("music_6.mp3");
    this->preloadEffect("bgm_button.aif");
	this->preloadEffect("bgm_fire.aif");
	this->preloadEffect("bgm_net.mp3");
	bool isMusic = FishJoyData::sharedFishJoyData()->getisMusic();
	bool isSound = FishJoyData::sharedFishJoyData()->getisSound();
	this->setBackgroundMusicVolume((float)isMusic);
	this->setEffectsVolume((float)isSound);
    return true;
}

void PersonalAudioEngine::playBackgroundMusic(int type){
	switch (type)
	{
	case 1:
		SimpleAudioEngine::playBackgroundMusic("music_1.mp3");
		break;
	case 2:
		SimpleAudioEngine::playBackgroundMusic("music_3.mp3");
		break;
	case 3:
		SimpleAudioEngine::playBackgroundMusic("music_6.mp3");
		break;
	}
	
}

void PersonalAudioEngine::playEffect(EffectType type){
	switch(type)
	{
	case kEffectFishNet:
		SimpleAudioEngine::playEffect("bgm_net.mp3");
		break;
	case kEffectShoot:
		SimpleAudioEngine::playEffect("bgm_fire.aif");
		break;
	case kEffectSwichCannon:
		SimpleAudioEngine::playEffect("bgm_button.aif");
		break;

	}
}

void PersonalAudioEngine::setBackgroundMusicVolume(float volume)
{
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(volume);
	FishJoyData::sharedFishJoyData()->setisMusic(volume);
}
void PersonalAudioEngine::setEffectsVolume(float volume)
{
	SimpleAudioEngine::sharedEngine()->setEffectsVolume(volume);
	FishJoyData::sharedFishJoyData()->setisSound(volume);
}
// void PersonalAudioEngine::purge()
// {
// 
// }
