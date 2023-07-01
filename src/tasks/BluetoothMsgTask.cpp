#include "BluetoothMsgTask.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include "../kernel/MsgServiceBluetooth.h"
#include "../model/SmartTheater.h"
#include "config.h"



BluetoothMsgTask::BluetoothMsgTask(SmartTheater* theater) {
    channel = new MsgServiceBluetooth(RX_PIN, TX_PIN);
    channel->init();
    this->theater = theater;
}

void BluetoothMsgTask::tick() {
    if (channel->isMsgAvailable()) {
        Msg* msg = channel->receiveMsg();
        String content = msg->getcontent();
        delete(msg);
        handleContent(content);
    } else {
        //notify();
    }
}

void BluetoothMsgTask::handleContent(String content) {
    /*if(theater->isNoShow()) {
        theater->setBluetoothMode();
            
    } else if (theater->isBluetoothMode() && theater->isNoShow()) {
        theater->setSerialMode();

    }*/
    //content="{\"A\":\"1\", \"b\":\"122\",\"c\":\"122\",}";
    //Serial.print(content);
    if(theater->isBluetoothMode()){
        Serial.print("Bluetooth mode ON\n");
        DynamicJsonDocument json(256);
        DeserializationError error = deserializeJson(json,content);    
        Serial.print(error.c_str());
        
        if (!error) {

            if(json.containsKey("A")){ //routineDuration
                int routineDuration = json["A"].as<int>();
                theater->setRoutineDuration(routineDuration);
                Serial.print(routineDuration);
                //theater->startRoutine();
              
            }
            
            if(json.containsKey("B")) { //stageLightStartTime
                bool stageLightStartTime = json["B"].as<int>();
                theater->setStageLightStartTime(stageLightStartTime);
                Serial.print(stageLightStartTime);
               
            }

             if(json.containsKey("C")) { //stageLightEndTime
                bool stageLightEndTime = json["C"].as<int>();
                theater->setStageLightEndTime(stageLightEndTime);
                Serial.print(stageLightEndTime);
              
            }

            if(json.containsKey("D")){ //musicStartTime
                int musicStartTime = json["D"].as<int>();
                theater->setMusicStartTime(musicStartTime);   
                Serial.print(musicStartTime);
               
            }

            if(json.containsKey("E")){ //musicEndTime
                int musicEndTime = json["E"].as<int>()*100;
                theater->setMusicEndTime(musicEndTime);   
                Serial.print(musicEndTime);
               
            }

            if(json.containsKey("G")){ //musicSong
                int musicSong = json["F"].as<int>();
                theater->setMusicSong(musicSong);   
                Serial.print(musicSong);
                
            }

            if(json.containsKey("F")){ //musicVolume
                int musicVolume = json["G"].as<int>();
                theater->setMusicVolume(musicVolume);   
                Serial.print(musicVolume);
                
            }

             if (json.containsKey("H")) { //stageLightBrightness
                int stageLightBrightness = json["H"].as<int>();
                theater->setStageLightBrightness(stageLightBrightness);
                Serial.print(stageLightBrightness);
               
            }

            

        }
    }
  
}

void BluetoothMsgTask::notify() {

 
}