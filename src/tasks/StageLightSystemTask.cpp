#include "StageLightSystemTask.h"
#include "config.h"

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
            if(theater->isShow() /*|| lightIntensityAudience >= MIN_LIGHT_INTENSITY*/){
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
    this->state = ON;
    this->stageLightSystem->turnOn(120,120,120);
}

void StageLightSystemTask::setStateOff(){
    this->state = OFF;
    this->stageLightSystem->turnOff();
}

void StageLightSystemTask::init(int period){
     Task::init(period);
}
