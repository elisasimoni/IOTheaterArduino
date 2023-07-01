#include "StageLightSystem.h"
#include "devices/LedRGB.h"

StageLightSystem::StageLightSystem(int lightPINR, int lightPING, int lightPINB){
    this->light = new LedRGB(lightPINR, lightPING, lightPINB);
}

void StageLightSystem::turnOn(int r, int g, int b){
    this->light->setColor(r,g,b);
}

void StageLightSystem::turnOff(){
    this->light->switchOff();
}

void StageLightSystem::setStartTime(unsigned long startTime){
    this->startTime = startTime;
}

void StageLightSystem::setEndTime(unsigned long endTime){
    this->endTime = endTime;
}

void StageLightSystem::setBrightness(int brightness){
    this->brightness = brightness;
}

double StageLightSystem::getStartTime(){
    return this->startTime;
}

double StageLightSystem::getEndTime(){
    return this->endTime;
}



