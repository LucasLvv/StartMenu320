#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H
#include "cocos2d.h"
#include "ProgressDelegate.h"
USING_NS_CC;
class ProgressBar : public CCProgressTimer
{
public:
    static ProgressBar* create(ProgressDelegate* target, CCSprite *sprite);
    bool init(ProgressDelegate* target,CCSprite *sprite);
	CC_SYNTHESIZE(float, _speed, Speed);
    CC_SYNTHESIZE(ProgressDelegate*, _target, Target);
	void progressBy(float delta);
	void progressTo(float destination);
	void setBackground(CCNode* bg);
	void setForeground (CCNode* fg);
protected:
	CCNode* _background;
	CCNode* _foreground;
    void updatePercentage();
    void loadingFinished();
};

#endif 
