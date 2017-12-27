#pragma once
class ScheduleCounterDelegate
{
public:
    virtual void scheduleTimeUp() = 0;
	//virtual void setScheduleNumber(int number) = 0;
    virtual void setScheduleNumber(int number)
	{return;};
protected:
private:
};

