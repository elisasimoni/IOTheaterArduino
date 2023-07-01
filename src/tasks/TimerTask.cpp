#include "TimerTask.h"
#include "../config.h"


TimerTask::TimerTask(SmartTheater* theater) {
    this->theater = theater;

}

void TimerTask::init(int period) {
    Task::init(period);
    this->startTime = 0;
    this->currentTime = 0;
    //this->delayTime = 0;
    this->state = INACTIVE;

}

void TimerTask::tick() {

    currentTime = millis();

    switch (state) {
        case INACTIVE: {
            if(theater->isShow()){
                setActive();
            }
            break;
        }

        case ACTIVE: {
            if(currentTime-startTime >= theater->getRoutineDuration()){
                //set no show theater ->      
                setInactive();
            }
            
            break;
        }

        default: {
            break;
        }
    }
}

void TimerTask::setActive() {
    this->state = ACTIVE;
    startTime = millis();
}

void TimerTask::setInactive() {
    this->state = INACTIVE;
    startTime = 0;
    currentTime = 0;
}

