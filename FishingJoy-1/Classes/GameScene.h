#pragma once
#include "cocos2d.h"
#include "BackgroundLayer.h"
#include "FishLayer.h"
#include "MenuLayer.h"
#include "CannonLayer.h"
#include "TouchLayer.h"
#include "Bullet.h"
#include "Fish.h"
#include "PanelLayer.h"
USING_NS_CC;

typedef enum{
	k_Operate_Pause = 0,
	k_Operate_Resume
}OperateFlag;

class GameScene : public CCScene
{
public:
	GameScene(void);
	//static GameScene * create();
	CREATE_FUNC(GameScene)
	virtual bool init();
	virtual ~GameScene(void);
	void alterGold(int golds);
	void cannonAimAt(CCPoint target);
	void cannonShootTo(CCPoint target);

	void pause();
	void resume();
	void sound();
	void music();
	void reset();
	void transToMainMenu();
	void scheduleTimeUp();

protected:
	BackgroundLayer* _backgroundLayer;
	FishLayer* _fishLayer;
	MenuLayer* _menuLayer;
	CannonLayer* _cannonLayer;
	TouchLayer* _touchLayer;
	PanelLayer* _panelLayer;

	virtual void update(float delta);
	void fishWillBeCaught(Fish* fish);

	//碰撞检测
	void checkOutCollision();
	bool checkOutCollisionBetweenFishesAndBullet(Bullet *bullet);
	void checkOutCollisionBetweenFishesAndFishingNet(Bullet *bulet);

	//暂停或恢复场景内运行的所有节点
	void operateAllSchedulerAndActions(CCNode* node, OperateFlag flag);
	/*void onEnter();*/
};

