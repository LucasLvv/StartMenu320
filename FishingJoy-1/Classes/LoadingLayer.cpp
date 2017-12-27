#include "LoadingLayer.h"
#include "GameScene.h"
#include "PersonalAudioEngine.h"
#include "FishJoyData.h"

CCScene* LoadingLayer::scene()
{
    CCScene* scene = CCScene::create();
    LoadingLayer* loadingLayer = LoadingLayer::create();
    scene->addChild(loadingLayer);
    return scene;
}
bool LoadingLayer::init()
{
    if(CCLayer::init()){
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		CCSprite* background = CCSprite::create("loading_1-ipadhd.png");

		background->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.6));
		addChild(background);
		initProgressBar();
		scheduleOnce(schedule_selector(LoadingLayer::cacheInit), 0.5f);
        return true;
    }
    return false;
}

void LoadingLayer::cacheInit(float delta)
{
	int progressStart = 1;
	float ratio = 3.3f;
    CCSpriteFrameCache* spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    
	char fishPlists[][50] = { "FishActor-Large-ipadhd.plist", "FishActor-Marlin-ipadhd.plist", 
		"FishActor-Shark-ipadhd.plist", "FishActor-Small-ipadhd.plist", "FishActor-Mid-ipadhd.plist", 
		"cannon-ipadhd.plist", "Item-chaojiwuqi-ipadhd.plist"};

	for (int i = 0; i < 7; i++)
	{
		spriteFrameCache->addSpriteFramesWithFile(fishPlists[i]);
		_progressBar->progressTo(ratio*(progressStart++));
	}

	CCTextureCache* textureCache = CCTextureCache::sharedTextureCache();

	char buttonTextures[][50] = { "ui_button_63-ipadhd.png", "ui_button_65-ipadhd.png",
		"ui_button_music_1-ipadhd.png", "ui_button_music_2-ipadhd.png", "button_other_001-ipadhd.png",
		"button_other_002-ipadhd.png", "button_other_003-ipadhd.png", "button_other_004-ipadhd.png"
	};

	for (int i = 0; i < 8; i++)
	{
		textureCache->addImage(buttonTextures[i]);
		_progressBar->progressTo(ratio*(progressStart++));
	}

	char str[][50] = { "SmallFish", "Croaker", "AngelFish", "Amphiprion", "PufferS", 
		"Bream", "Porgy", "Chelonian", "Lantern", "Ray", "Shark", "GoldenTrout", "GShark", 
		"GMarlinsFish", "GrouperFish", "JadePerch", "MarlinsFish", "PufferB" };
	for (int i = 0; i < 18; i++)
	{
		CCArray* array = CCArray::createWithCapacity(10);
		for (int j = 0; j < 10; j++)
		{
			CCString* spriteFrameName = CCString::createWithFormat("%s_actor_%03d.png", str[i], j + 1);
			CCSpriteFrame* spriteFrame = spriteFrameCache->spriteFrameByName(spriteFrameName->getCString());
			CC_BREAK_IF(!spriteFrame);
			array->addObject(spriteFrame);
		}
		if (array->count() == 0)
		{
			continue;
		}
		CCAnimation* animation = CCAnimation::createWithSpriteFrames(array, 0.15f);
		CCString* animationName = CCString::createWithFormat("fish_animation_%02d", i + 1);
		CCAnimationCache::sharedAnimationCache()->addAnimation(animation, animationName->getCString());
		_progressBar->progressTo(ratio*(progressStart++));
	}

	PersonalAudioEngine::sharedEngine();
	FishJoyData::sharedFishJoyData();

	_progressBar->progressTo(100.0f);
}

void LoadingLayer::loadingFinished()
{

	CCScene* gameScene = GameScene::create();
	CCDirector::sharedDirector()->replaceScene(gameScene);
}
void LoadingLayer::progressPercentageSetter(float percentage)
{
    CCString* str = CCString::createWithFormat("%d/100",(int)percentage);
    _progressFg->setString(str->getCString());
}

LoadingLayer::LoadingLayer()
{
	_loadedSp = 0;
	_numSp = 3;
	_progressBar = NULL;
	_progressFg = NULL;
}

void LoadingLayer::initProgressBar()
{
	CCSprite* progressBg = CCSprite::create("loading_4-ipadhd.png");
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	_progressFg = CCLabelTTF::create("0/100", "Thonburi", 60);
	_progressFg->setColor(ccc3(197, 118, 20));

	_progressBar = ProgressBar::create(this, CCSprite::create("loading_5-ipadhd.png"));
	_progressBar->setBackground(progressBg);
	_progressBar->setForeground(_progressFg);
	_progressBar->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.25));
	_progressBar->setSpeed(20.0f);

	addChild(_progressBar);
}