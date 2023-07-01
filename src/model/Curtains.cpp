#include "Curtains.h"
#include "devices/servo_motor_impl.h"
#include "config.h"

Curtains::Curtains(int servoPIN){
    this->servoMotor = new ServoMotorImpl(servoPIN);
    this->openPercentage = 0;
}

void Curtains::open(){
    this->servoMotor->on();
}

void Curtains::close(){
    this->servoMotor->off();
}

void Curtains::plainOpen() {
    this->servoMotor->setPosition(OPEN_ANGLE);  
    this->openPercentage = 180; // Imposta la percentuale di apertura al 100%
    
   
}

void Curtains::plainClose() {
    this->servoMotor->setPosition(CLOSE_ANGLE);
    this->openPercentage = 0; // Imposta la percentuale di apertura a 0%
}

void Curtains::setPercentage(int percentage) {
    int targetPosition = map(percentage, 0, 100, CLOSE_ANGLE, OPEN_ANGLE);
    this->servoMotor->setPosition(targetPosition);
    this->openPercentage = percentage; // Salva la nuova percentuale di apertura
}


int Curtains::getPercentage(){
    return this->openPercentage;
}

void Curtains::setStartTime(double startTime){
    this->startTime = startTime;
}

void Curtains::setEndTime(double endTime){
    this->endTime = endTime;
}

double Curtains::getEndTime(){
    return this->endTime;
}

double Curtains::getStartTime(){
    return this->startTime;
}

