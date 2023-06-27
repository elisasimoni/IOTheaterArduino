#include "SpotlightTask.h"
#include "config.h"

SpotlightTask::SpotlightTask(SmartTheater* smartTheater){
    this->theater = smartTheater;
    this->spotlight = smartTheater->getSpotlight();
    this->state = OFF;
    

}

void SpotlightTask::tick(){
    int distanceActor = this->theater->getDistanceActor();
    switch (this->state){
        case OFF:{
            if(theater->isShow()){
                if(distanceActor < MIN_DISTANCE_ACTOR){
                    setStateOn();
                }
            }
            break;
        }
        case ON:{
            if(theater->isNoShow() || distanceActor >= MIN_DISTANCE_ACTOR){
                setStateOff();
            }
            break;
        }
        default:{
            break;
        }
    }
}
void SpotlightTask::setStateOn(){
    this->state = ON;
    this->spotlight->turnOn();
}
void SpotlightTask::setStateOff(){
    this->state = OFF;
    this->spotlight->turnOff();
}

void SpotlightTask::init(int period){
    Task::init(period);
}