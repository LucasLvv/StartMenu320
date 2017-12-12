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

class GameScene :
	public CCScene
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

protected:
	BackgroundLayer* _backgroundLayer;
	FishLayer* _fishLayer;
	MenuLayer* _menuLayer;
	CannonLayer* _cannonLayer;
	TouchLayer* _touchLayer;
	PanelLayer* _paneLayer;
	void preloadResources(void);
	virtual void update(float delta);
	void fishWillBeCaught(Fish* fish);

	//Åö×²¼ì²â
	void checkOutCollision();
	bool checkOutCollisionBetweenFishesAndBullet(Bullet *bullet);
	void checkOutCollisionBetweenFishesAndFishingNet(Bullet *bulet);
};

