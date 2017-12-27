#pragma once
#include "cocos2d.h"
#include "GoldCounterLayer.h"
#include "ScheduleCounterDelegate.h"

USING_NS_CC;

class PanelLayer
	:public CCLayer, public ScheduleCounterDelegate
{
public:
	virtual bool init();
	PanelLayer(void);
	~PanelLayer(void);

    CREATE_FUNC(PanelLayer)
    CC_SYNTHESIZE_READONLY(GoldCounterLayer *, _goldCounter, GoldCounter)

	//虚函数实现
	void scheduleTimeUp();
	void setScheduleNumber(int number);

protected:
	void pause(CCObject *sender);

	//CCLabelTTF用来显示当前的倒计时时间
	CCLabelTTF* _scheduleLabel;
};

