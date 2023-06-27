#ifndef __MUSICTASK__
#define __MUSICTASK__
#include "model/SmartTheater.h"
#include "kernel/Task.h"


class MusicTask : public Task{
private:
    SmartTheater* theater;
    Music* music;
    enum {PLAY, STOP} state;
    double startTime, endTime;
    double frequency, duration;
    // void setSong();
    // void getSong();
    void setStateOn();
    void setStateOff();

public:
    MusicTask(SmartTheater* theater);
    void init(int period);
    void tick();

};



#endif