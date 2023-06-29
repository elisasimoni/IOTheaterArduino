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

  bluetoothTask->init(200);
  scheduler->addTask(bluetoothTask);

  //serialTask->init(500);
  //scheduler->addTask(serialTask);

  stageLightSystemTask->init(500);
  scheduler->addTask(stageLightSystemTask);

  musicTask->init(200);
  scheduler->addTask(musicTask);
  
  curtainsTask->init(500);
  scheduler->addTask(curtainsTask);

  spotlightTask->init(200);
  scheduler->addTask(spotlightTask);

 

}

void loop() {
  scheduler->schedule();
}
