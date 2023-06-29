#include "StageLightSystemTask.h"
#include "config.h"
#include <Arduino.h>

StageLightSystemTask::StageLightSystemTask(SmartTheater* smartTheater){
    this->theater = smartTheater;
    this->stageLightSystem = smartTheater->getStageLightSystem();
    this->state = ON;
    

}

void StageLightSystemTask::tick(){
    
    double lightIntensityAudience = this->theater->getLightIntensityAudience();
    switch(state){
        case OFF:{
            
            if(theater->isNoShow()){
                if(lightIntensityAudience < MIN_LIGHT_INTENSITY){
                    setStateOff();
                    
                }
            }
           break;
            
        }
        case ON:{
                     
                     
            if(theater->isShow() || lightIntensityAudience >= MIN_LIGHT_INTENSITY){
                setStateOn(); 
            }
            
            break;
            
        }
        default:{
            break;
        }
    }
}

void StageLightSystemTask::setStateOn(){
    this->stageLightSystem->turnOn(1,0,0);
    this->state = ON;
    
}

void StageLightSystemTask::setStateOff(){
    this->state = OFF;
    this->stageLightSystem->turnOff();
}

void StageLightSystemTask::init(int period){
     Task::init(period);
}
