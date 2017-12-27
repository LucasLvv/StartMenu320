#ifndef PROGRESSDELEGATE_H
#define PROGRESSDELEGATE_H
class ProgressDelegate
{
public:
    virtual void loadingFinished() = 0;
    virtual void progressPercentageSetter(float percentage){return;};
};


#endif
