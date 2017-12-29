#include "PanelLayer.h"
#include "GameScene.h"
#include "ScheduleCountDown.h"

PanelLayer::PanelLayer(void)
{

}

PanelLayer::~PanelLayer(void)
{

}
bool PanelLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	_goldCounter = GoldCounterLayer::create(0);
	this->addChild(_goldCounter);
	_goldCounter->setPosition(ccp(500, 40));

	ScheduleCountDown* countDown = ScheduleCountDown::create(this);

	_scheduleLabel = CCLabelTTF::create("30", "Thonburi", 70);
	_scheduleLabel->addChild(countDown);
	_scheduleLabel->setColor(ccc3(102, 255, 255));
	this->addChild(_scheduleLabel);
	_scheduleLabel->setPosition(ccp(70, 300));

    return true;
}

// void PanelLayer::pause(CCObject *sender)
// {
// 	GameScene* gameScene = (GameScene*)this->getParent();
// 	gameScene->pause();
// }

void PanelLayer::setScheduleNumber(int number)
{
	_scheduleLabel->setString(CCString::createWithFormat("%d",number)->getCString());
}

void PanelLayer::scheduleTimeUp()
{
	/*_scheduleLabel->setVisible(false);*/

	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->scheduleTimeUp();
}
