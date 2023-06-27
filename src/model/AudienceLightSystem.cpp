#include "AudienceLightSystem.h"
#include "devices/Led.h"

AudienceLightSystem::AudienceLightSystem(int lightPIN){
    this->light = new Led(lightPIN);
}

void AudienceLightSystem::turnOn(){
    this->light->switchOn();
}

void AudienceLightSystem::turnOff(){
    this->light->switchOff();
}