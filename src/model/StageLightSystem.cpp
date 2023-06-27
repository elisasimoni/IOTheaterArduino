#include "StageLightSystem.h"
#include "devices/LedRGB.h"

StageLightSystem::StageLightSystem(int lightPINR, int lightPING, int lightPINB){
    this->light = new LedRGB(lightPINR, lightPING, lightPINB);
    this->startTime = 0;
    this->endTime = 0;
    this->brightness = 0;
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

void StageLightSystem::turnOn(int r, int g, int b){
    this->light->setColor(r,g,b);
}

void StageLightSystem::turnOff(){
    this->light->switchOff();
}

void StageLightSystem::setRGB(int r, int g, int b){
    this->light->setColor(r,g,b);
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




