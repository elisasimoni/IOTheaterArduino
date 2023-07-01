#ifndef __MSG__
#define __MSG__

#include <Arduino.h>



class Msg {
private:
    String content;

public:
   
    Msg(String content) {
        Serial.println("parametro: " + content);
        this->content = content;
        Serial.println("effettivo: "+ this->content);
    }


    String getcontent() {
        return this->content;
    }
};

#endif