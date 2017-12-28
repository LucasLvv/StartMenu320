#ifndef _SCHEDULECOUNTDOWN_H
#define _SCHEDULECOUNTDOWN_H
#include "cocos2d.h"
#include "ScheduleCounterDelegate.h"
USING_NS_CC;
class ScheduleCountDown : public CCNode
{
public:
    static ScheduleCountDown* create(ScheduleCounterDelegate* target, int perimeter = 30, bool loop = true);
	// 	CC_SYNTHESIZE(int, _currentTime, CurrentTime);
	// 	CC_SYNTHESIZE(int, _maxTime, MaxTime);
	CC_SYNTHESIZE(bool, _loop, Loop);
	// CC_SYNTHESIZE(ScheduleCounterDelegate*, _target, Target);
	bool init(ScheduleCounterDelegate* target, int perimeter = 30, bool loop = true);
protected:
	ScheduleCounterDelegate* _target;
	int _currentTime;
	int _maxTime;
    void schedulePerSecond(float delta);
private:
};

#endif 
