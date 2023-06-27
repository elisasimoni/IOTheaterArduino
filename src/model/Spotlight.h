#ifndef __SPOTLIGHT__
#define __SPOTLIGHT__

#include "devices/Light.h"

class Spotlight{
private:
    Light* light;
    int distance;
    
public:
    void turnOn();
    void turnOff();
    Spotlight(int lightPIN);
};


#endif

