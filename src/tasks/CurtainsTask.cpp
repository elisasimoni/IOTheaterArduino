#include "Arduino.h"
#include "CurtainsTask.h"
#include "model/SmartTheater.h"
#include "../config.h"


CurtainsTask::CurtainsTask(SmartTheater* theater) {
    this->theater = theater;
    this->curtains = theater->getCurtains();
    setCurtainsClose();
}

void CurtainsTask::tick() {
    switch (state) {
        case CLOSE: {
            curtains->open();
            curtains->plainOpen();
            setCurtainsOpen();
            break;
        }

        case OPEN: {
            if(theater->isNoShow() && curtains->getPercentage() == MAX_OPEN_PERCENTAGE){
                curtains->plainClose();
                setCurtainsMoving();
              
            }
            
            break;
        }

        case MOVING: {
            if (curtains->getPercentage() <= MAX_OPEN_PERCENTAGE) {
                setCurtainsStop();
            }
            break;
        }

        case STOP: {
            curtains->close();
            break;
        }

        default: {
            break;
        }
    }
}

void CurtainsTask::setCurtainsOpen() {
    this->state = OPEN;
}

void CurtainsTask::setCurtainsClose() {
    this->state = CLOSE;
}

void CurtainsTask::setCurtainsStop() {
    this->state = STOP;
}

void CurtainsTask::setCurtainsMoving() {
    this->state = MOVING;
}
    

void CurtainsTask::init(int period){
    Task::init(period);
}
