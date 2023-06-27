#ifndef __SPOTLIGHTTASK__
#define __SPOTLIGHTTASK__
#include "model/SmartTheater.h"
#include "kernel/Task.h"


class SpotlightTask : public Task{
private:
    SmartTheater* theater;
    Spotlight* spotlight;
    enum {OFF, ON} state;
    void setStateOn();
    void setStateOff();

public:
    SpotlightTask(SmartTheater* theater);
    void init(int period);
    void tick();

};



#endif