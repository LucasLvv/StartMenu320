#include "PanelLayer.h"
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

	_goldCounter = GoldCounterLayer::create(0);
	addChild(_goldCounter);
	_goldCounter->setPosition(ccp(500,60));
    return true;
}
