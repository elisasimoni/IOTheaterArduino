#include "MusicTask.h"
#include "config.h"

MusicTask::MusicTask(SmartTheater* smartTheater){
    this->theater = smartTheater;
    this->music = smartTheater->getMusic();
    this->state = STOP;
    this->startTime = 0;
    this->endTime = 0;
    this->frequency = 0;
    this->duration = 0;


}

void MusicTask::tick(){
    switch (this->state){
        case STOP:{
            if(theater->isShow() && (theater->getRoutineTimer() >= startTime && theater->getRoutineTimer() <= startTime+BUFFER) ){
                music->turnOn(frequency, duration);
                setStateOn();
            }
            break;
        }
        case PLAY:{
            if(theater->isNoShow() || (theater->getRoutineTimer() >= endTime && theater->getRoutineTimer() <= endTime+BUFFER)){
               setStateOff();
            }
            break;
        }
        default:{
            break;
        }
    }
}

void MusicTask::setStateOn(){
    this->state = PLAY;
}
void MusicTask::setStateOff(){
    this->state = STOP;
    this-> music->turnOff();
}


void MusicTask::init(int period){
    Task::init(period);
}