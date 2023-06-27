#include "buzzer.h"
#include "Arduino.h"

Buzzer::Buzzer(int pin) {
  this->buzzerPin = pin;
  pinMode(buzzerPin, OUTPUT);
}

void Buzzer::playTone(int frequency, int duration) {
  tone(buzzerPin, frequency, duration);
  delay(duration); 
}

void Buzzer::switchOff() {
  noTone(buzzerPin);
}
