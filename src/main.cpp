#include <Arduino.h>
#include "model/SmartTheater.h"
#include "kernel/Scheduler.h"
#include "tasks/SpotlightTask.h"
#include "kernel/Task.h"
#include "tasks/CurtainsTask.h"
#include "tasks/MusicTask.h"
#include "tasks/StageLightSystemTask.h"
#include "tasks/BluetoothMsgTask.h"
#include "tasks/SerialMsgTask.h"
#include "tasks/TimerTask.h"
#include "config.h"


SmartTheater* theater;
Scheduler* scheduler;

void setup() {
  scheduler = new Scheduler();
  scheduler->init(50); 

  theater = new SmartTheater(SPOTLIGHT_PIN, LIGHT_R_PIN,LIGHT_G_PIN, LIGHT_B_PIN, CURTAINS_PIN, MUSIC_PIN); 
  Task* spotlightTask = new SpotlightTask(theater);
  Task* curtainsTask = new CurtainsTask(theater);
  Task* musicTask = new MusicTask(theater);
  Task* stageLightSystemTask = new StageLightSystemTask(theater);
  Task* bluetoothTask = new BluetoothMsgTask(theater);
  Task* serialTask = new SerialMsgTask(theater);
  Task* timerTask = new TimerTask(theater);

  bluetoothTask->init(200);
  stageLightSystemTask->init(500);
  musicTask->init(200);
  curtainsTask->init(500);
  spotlightTask->init(200);
  timerTask->init(100);
  


  serialTask->init(500);
  //scheduler->addTask(serialTask);

  scheduler->addTask(stageLightSystemTask);

 
  scheduler->addTask(musicTask);
  

  scheduler->addTask(curtainsTask);

  
  scheduler->addTask(spotlightTask);

  scheduler->addTask(bluetoothTask);

}

void loop() {
  scheduler->schedule();
}
