#include "Music.h"
#include "devices/Buzzer.h"
#include "Arduino.h"

Music::Music(int musicPin) {
    music = new Buzzer(musicPin);
}

void Music::turnOn(int frequency, int duration) {
    music->playTone(frequency, duration);
    
}

void Music::turnOff() {
    music->switchOff();
    
}

unsigned long Music::getStartTime() {
    return startTime;
}

unsigned long Music::getEndTime() {
    return endTime;
}

int Music::getFrequency() {
    return frequency;
}

int Music::getDuration() {
    return duration;
}

void Music::setStartTime(unsigned long startTime) {
    this->startTime = startTime;
}

void Music::setEndTime(unsigned long endTime) {
    this->endTime = endTime;
}

void Music::setFrequency(int frequency) {
    this->frequency = frequency;
}

void Music::setVolume(int volume) {
    this->volume = volume;
}

int Music::getVolume() {
    return volume;
}
void Music::setSong(int song) {
    this->song = song;
}

int Music::getSong() {
    return song;
}





