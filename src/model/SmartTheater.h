#ifndef __SMARTTHEATER__
#define __SMARTTHEATER__
#include "StageLightSystem.h"
#include "AudienceLightSystem.h"
#include "Spotlight.h"
#include "Curtains.h"
#include "Music.h"
#include "../config.h"


class SmartTheater{
private:
    StageLightSystem* stageLightSystem;
    AudienceLightSystem* audienceLightSystem;
    Spotlight* spotlight;
    Curtains* curtains;
    Music* music;

    //routine timer
    double routineTimer, routineStartTime; 

    //sensor board data
    int distanceActor;
    double lightIntensityAudience;

    enum {SHOW, NO_SHOW} state;
    enum {SERIAL_MODE, BLUETOOTH_MODE} mode;
public:
    SmartTheater(int spotlightPIN, int lightPIN_r, int lightPIN_g, int lightPIN_b, int curtainsPIN, int musicPIN);
    StageLightSystem* getStageLightSystem();
    AudienceLightSystem* getAudienceLightSystem();
    Spotlight* getSpotlight();
    Curtains* getCurtains();
    Music* getMusic();

    double getRoutineTimer();
    double setRoutineTimerStart();
    int getDistanceActor();
    double getLightIntensityAudience();
    bool isShow();
    bool isNoShow();
    double getTimer();
    bool isSerialMode();
    bool isBluetoothMode();
    void setSerialMode();
    void setBluetoothMode();
    void setRoutineDuration(double timer);
    void startRoutine();
    void setCurtainsOpenPercentage(int percentage);
    void setDistanceActor(int distanceActor);
    void setMusicVolume(double volume);
    void setMusicSong(int song);
    void setMusicFrequency(int frequency);
    void setStageLightColor(int r, int g, int b);
    void setStageLightStartTime(double startTime);
    void setStageLightEndTime(double endTime);
    void setStageLightBrightness(int brightness);
    void setMusicStartTime(double startTime);
    void setMusicEndTime(double endTime);
    double getRoutineDuration();
    bool isRoutineStarted();




};



#endif