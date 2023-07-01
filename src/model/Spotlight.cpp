#include "Spotlight.h"
#include "devices/Led.h"

Spotlight::Spotlight(int lightPIN){
    this->light = new Led(lightPIN);
    this->distance = 0;

}

void Spotlight::turnOn(){
    this->light->switchOn();
}

void Spotlight::turnOff(){
    this->light->switchOff();
}

bool Spotlight::getState(){
    return state;
}
