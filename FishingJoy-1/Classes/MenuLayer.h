#pragma once
#include "cocos2d.h"
USING_NS_CC;

class MenuLayer : public CCLayer
{
public:
	CREATE_FUNC(MenuLayer)
	bool init();
/*	void setSoundAndMusicVolume(float soundVolume, float musicVolume);*/

protected:
	void resume(cocos2d::CCObject* pSender);
	void mainMenu(cocos2d::CCObject* pSender);
/*	void sound(cocos2d::CCObject* pSender);*/
	void music(cocos2d::CCObject* pSender);
	void reset(cocos2d::CCObject* pSender);

	void createMenu();
	void createBackground();

/*	cocos2d::CCMenuItemToggle* _sound;*/
	cocos2d::CCMenuItemToggle* _music;
};