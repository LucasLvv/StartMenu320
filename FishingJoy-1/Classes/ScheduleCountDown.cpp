#include "ScheduleCountDown.h"

ScheduleCountDown* ScheduleCountDown::create(ScheduleCounterDelegate* target, int perimeter, bool loop)
{
    ScheduleCountDown* CountDown = new ScheduleCountDown;
	CountDown->init(target, perimeter, loop);
	CountDown->autorelease();
    return CountDown;
}
bool ScheduleCountDown::init(ScheduleCounterDelegate* target, int perimeter, bool loop)
{
	_target = target;
	_maxTime = _currentTime = perimeter;
	_loop = loop;

	schedule(schedule_selector(ScheduleCountDown::schedulePerSecond),1.0f);
	return true;
}
void ScheduleCountDown::schedulePerSecond(float delta)
{
    _currentTime--;
    if(_currentTime < 0){
		bool Loop = this->getLoop();
        if(Loop){
            _currentTime = _maxTime;
        }else{
            this->unschedule(schedule_selector(ScheduleCountDown::schedulePerSecond));
        }
        _target->scheduleTimeUp();
    }
    _target->setScheduleNumber(_currentTime);
}