#include "SmartTheater.h"
#include <TimerOne.h>

SmartTheater::SmartTheater(int spotlightPIN, int lightPIN_r,int lightPIN_g, int lightPIN_b, int curtainsPIN, int musicPIN){
    this->spotlight = new Spotlight(spotlightPIN);
    this->curtains = new Curtains(curtainsPIN);
    this->music = new Music(musicPIN);
    this->stageLightSystem = new StageLightSystem(lightPIN_r, lightPIN_g,lightPIN_b);
    this->distanceActor = 0;
    this->lightIntensityAudience = 0;
    this->state = NO_SHOW;
    this->mode = BLUETOOTH_MODE;
    this->timer = 0;
    
}

StageLightSystem* SmartTheater::getStageLightSystem(){
    return this->stageLightSystem;
}

AudienceLightSystem* SmartTheater::getAudienceLightSystem(){
    return this->audienceLightSystem;
}

Spotlight* SmartTheater::getSpotlight(){
    return this->spotlight;
}

Curtains* SmartTheater::getCurtains(){
    return this->curtains;
}

Music* SmartTheater::getMusic(){
    return this->music;
}

double SmartTheater::getLightIntensityAudience(){
    return this->lightIntensityAudience;
}

int SmartTheater::getDistanceActor(){
    return this->distanceActor;
}

bool SmartTheater::isShow(){
    return this->state = SHOW;
}

bool SmartTheater::isNoShow(){
    return this->state = NO_SHOW;
}

bool SmartTheater::isSerialMode() {
    return this->mode == SERIAL_MODE;
}

bool SmartTheater::isBluetoothMode() {
    return this->mode == BLUETOOTH_MODE;
}

void SmartTheater::setSerialMode() {
    this->mode = SERIAL_MODE;
}

void SmartTheater::setBluetoothMode() {
    this->mode = BLUETOOTH_MODE;
}



void SmartTheater::setCurtainsOpenPercentage(int percentage){
    this->curtains->setPercentage(percentage);
}

void SmartTheater::setDistanceActor(int distanceActor){
    this->distanceActor = distanceActor;
}

void SmartTheater::setMusicVolume(double volume){
    this->music->setVolume(volume);
}

void SmartTheater::setMusicSong(int song){
    this->music->setSong(song);
}

void SmartTheater::setMusicFrequency(int frequency){
    this->music->setFrequency(frequency);
}

void SmartTheater::setStageLightColor(int r, int g, int b){
    this->stageLightSystem->setRGB(r, g, b);
}

void SmartTheater::setStageLightStartTime(double startTime){
    this->stageLightSystem->setStartTime(startTime);
}

void SmartTheater::setStageLightEndTime(double endTime){
    this->stageLightSystem->setEndTime(endTime);
}

void SmartTheater::setStageLightBrightness(int brightness){
    this->stageLightSystem->setBrightness(brightness);
}

void SmartTheater::setMusicStartTime(double startTime){
    this->music->setStartTime(startTime);
}

void SmartTheater::setMusicEndTime(double endTime){
    this->music->setEndTime(endTime);
}

unsigned long SmartTheater::getRoutineDuration(){
    return this->timer;
}

void SmartTheater::setRoutineDuration(unsigned long timer){
    this->timer = timer;
}





