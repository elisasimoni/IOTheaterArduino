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
            
            if(theater->isShow()){
                Serial.print("Curtains open\n");
                curtains->open();
                curtains->plainOpen();
                setCurtainsOpen();      
            }
            break;
        }

        case OPEN: {
           
            curtains->close();

            if(theater->isNoShow() && curtains->getPercentage() == MAX_OPEN_PERCENTAGE){
                curtains->open();
                curtains->plainClose();
                setCurtainsStop();
                Serial.print("Curtains close\n");   
            }
            break;
        }

        case STOP: {       
            Serial.print("Curtains finish\n");     
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

void CurtainsTask::init(int period){
    Task::init(period);
}
