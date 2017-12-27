#include "GameScene.h"
#include "FishJoyData.h"
#include "PersonalAudioEngine.h"

GameScene::GameScene()
{
}

bool GameScene::init()
{
	do
	{
		CC_BREAK_IF(!CCScene::init());

		_backgroundLayer = BackgroundLayer::create();
		CC_BREAK_IF(!_backgroundLayer);
		addChild(_backgroundLayer);

		_fishLayer = FishLayer::create();
		CC_BREAK_IF(!_fishLayer);
		addChild(_fishLayer);

		_cannonLayer = CannonLayer::create();
		CC_BREAK_IF(!_cannonLayer);
		addChild(_cannonLayer);

		_panelLayer = PanelLayer::create();
		CC_BREAK_IF(!_panelLayer);
		addChild(_panelLayer);

		_menuLayer = MenuLayer::create(); 
		CC_BREAK_IF(!_menuLayer);
		CC_SAFE_RETAIN(_menuLayer); 

		_touchLayer = TouchLayer::create();
		CC_BREAK_IF(!_touchLayer);
		addChild(_touchLayer);

		int gold = FishJoyData::sharedFishJoyData()->getGold();

		_panelLayer->getGoldCounter()->setNumber(gold);

		this->scheduleUpdate();
		PersonalAudioEngine::sharedEngine()->playBackgroundMusic(1);
		return true;
	} while (0);
	return false;
}

void GameScene::pause()
{
	this->operateAllSchedulerAndActions(this, k_Operate_Pause);
	_touchLayer->setTouchEnabled(false);
	this->addChild(_menuLayer);
}

void GameScene::resume()
{
	this->operateAllSchedulerAndActions(this, k_Operate_Resume);
	this->removeChild(_menuLayer, false);
	_touchLayer->setTouchEnabled(true);
}

void GameScene::sound()
{
// 	bool flag = FishJoyData::sharedFishJoyData()->getSoundVolume()>0;
// 	PersonalAudioEngine::sharedEngine()->setEffectsVolume(!flag);
}
void GameScene::music()
{
// 	bool flag = FishJoyData::sharedFishJoyData()->getMusicVolume()>0;
// 	PersonalAudioEngine::sharedEngine()->setBackgroundMusicVolume(!flag);
}
void GameScene::reset()
{
}
void GameScene::transToMainMenu()
{
}

void GameScene::operateAllSchedulerAndActions(CCNode* node, OperateFlag flag)
{
	if(node->isRunning()){
		switch (flag) {
		case k_Operate_Pause:
			node->pauseSchedulerAndActions();
			break;
		case k_Operate_Resume:
			node->resumeSchedulerAndActions();
			break;
		default:
			break;
		}
		CCArray* array = node->getChildren();
		if(array != NULL && array->count()>0){
			CCObject* iterator;
			CCARRAY_FOREACH(array, iterator){
				CCNode* child = (CCNode*)iterator;
				this->operateAllSchedulerAndActions(child, flag);
			}
		}
	}
}

GameScene::~GameScene()
{
	CC_SAFE_RELEASE(_menuLayer);
}

void GameScene::cannonAimAt(CCPoint target)
{
	_cannonLayer->aimAt(target);
}

void GameScene::cannonShootTo(CCPoint target)
{
	/*_cannonLayer->shootTo(target);*/

	int type = _cannonLayer->getWeapon()->getCannon()->getType();
	int cost = (type+1) * 1;
	if(FishJoyData::sharedFishJoyData()->getGold() >= cost && _cannonLayer->shootTo(target)){
		PersonalAudioEngine::sharedEngine()->playEffect(kEffectShoot);
		alterGold(-cost);
	}
}

bool GameScene::checkOutCollisionBetweenFishesAndBullet(Bullet *bullet)
{
	CCPoint bulletPos =bullet->getCollosionPoint();
	CCArray *fishArray = _fishLayer->getFishArray();
	CCObject *obj = NULL;
	CCARRAY_FOREACH(fishArray, obj)
	{
		Fish *fish =(Fish *)obj;
		if(fish->isRunning() && fish->getCollisionArea().containsPoint(bulletPos))
		{
			bullet->end();
			return true;
		}
	}
	return false;
}

void GameScene::checkOutCollision()
{
	CCArray *bullets = _cannonLayer->getWeapon()->getBullets();
	CCObject *obj = NULL;
	CCARRAY_FOREACH(bullets, obj)
	{
		Bullet *bullet = (Bullet *)obj;
		if(bullet->isVisible())
		{
			if(checkOutCollisionBetweenFishesAndBullet(bullet))
			{
				checkOutCollisionBetweenFishesAndFishingNet(bullet);
			}
		}
	}	
}

void GameScene::update(float delta)
{
	checkOutCollision();
}

void GameScene::fishWillBeCaught(Fish* fish)
{
	
	double weaponPercents[k_Cannon_Count] = {0.3,0.6,0.7,0.8,0.9,1.0,1.1};
	double fishPercents[k_Fish_Type_Count] = {1,0.9,0.8,0.7,0.6,0.5,0.4};
	int cannonType = _cannonLayer->getWeapon()->getCannonType();
	int fishType = fish->getType();
	if(CCRANDOM_0_1() < weaponPercents[cannonType] * fishPercents[fishType])
	/*if(CCRANDOM_0_1() <1.1)*/
	{
		fish->beCaught();
		PersonalAudioEngine::sharedEngine()->playEffect(kEffectFishNet);
		int reward = (fishType+1) * 5;
		alterGold(reward);
		

	}

	
}

void GameScene::checkOutCollisionBetweenFishesAndFishingNet(Bullet *bullet)
{
	Weapon *weapon = _cannonLayer->getWeapon();
	CCRect rect = weapon->getCollisionArea(bullet);
	CCArray *fishArray = _fishLayer->getFishArray();
	CCObject *obj = NULL;
	CCARRAY_FOREACH(fishArray, obj)
	{
		Fish *fish = (Fish *)obj;

		if(fish->isRunning() && rect.intersectsRect(fish->getCollisionArea()))
		{
			fishWillBeCaught(fish);
		}
	}
}


void GameScene::alterGold(int golds)
{
	FishJoyData::sharedFishJoyData()->alterGold(golds);
	_panelLayer->getGoldCounter()->setNumber(FishJoyData::sharedFishJoyData()->getGold());
}

//void GameScene::onEnter()
//{
//	CCScene::onEnter();
//	PersonalAudioEngine::sharedEngine()->playBackgroundMusic(1);
//}

void GameScene::scheduleTimeUp()
{
	this->alterGold(200);
}
