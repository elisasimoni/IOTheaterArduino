#include "AudienceLightSystemTask.h"
#include "config.h"

AudienceLightSystemTask::AudienceLightSystemTask(SmartTheater* smartTheater){
    this->theater = smartTheater;
    this->audienceLightSystem = smartTheater->getAudienceLightSystem();
    this->state = OFF;
    

}

void AudienceLightSystemTask::tick(){
    double lightIntensityAudience = this->theater->getLightIntensityAudience();
    switch(state){
        case OFF:{
            if(theater->isNoShow()){
                if(lightIntensityAudience < MIN_LIGHT_INTENSITY){
                    setStateOn(); 
                }
            }
           break;
            
        }
        case ON:{
            if(theater->isShow() || lightIntensityAudience >= MIN_LIGHT_INTENSITY){
                setStateOff();
            }
            break;
            
        }
        default:{
            break;
        }
    }
}

void AudienceLightSystemTask::setStateOn(){
    this->state = ON;
    this->audienceLightSystem->turnOn();
}

void AudienceLightSystemTask::setStateOff(){
    this->state = OFF;
    this->audienceLightSystem->turnOff();
}

void AudienceLightSystemTask::init(int period){
     Task::init(period);
}
