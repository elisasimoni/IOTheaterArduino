#ifndef __SPOTLIGHT__
#define __SPOTLIGHT__

#include "devices/Light.h"

class Spotlight{
private:
    Light* light;
    int distance;
    enum state {OFF, ON} state;
    
public:
    void turnOn();
    void turnOff();
    bool getState();
    Spotlight(int lightPIN);
};


#endif

