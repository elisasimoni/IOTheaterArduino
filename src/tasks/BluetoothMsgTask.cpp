#include "BluetoothMsgTask.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include "../kernel/MsgServiceBluetooth.h"
#include "../model/SmartTheater.h"
#include "config.h"


BluetoothMsgTask::BluetoothMsgTask(SmartTheater* theater) {
    this->channel = new MsgServiceBluetooth(RX_PIN, TX_PIN);
    this->channel->init();
    this->theater = theater;
    theater->setBluetoothMode();


}

void BluetoothMsgTask::tick() {
   
 Serial.print("N");
    if (channel->isMsgAvailable()) {
              Serial.print("M");
        Msg* msg = channel->receiveMsg();
        String content = msg->getcontent();
        delete(msg);
        handleContent(content);
    }else{
        Serial.print("P");
    }
    notify();
}


void BluetoothMsgTask::handleContent(String content) {
    // if(theater->isNoShow() && content.equals("SHOW") ) {
    //     theater->setBluetoothMode();
            
    // } else if (theater->isBluetoothMode()&& content.equals("NO_SHOW")) {
    //     theater->setSerialMode();

    // }else 
     Serial.print("1");
    if(theater->isBluetoothMode()){
       Serial.print("1");
        DynamicJsonDocument json(128);
        DeserializationError error = deserializeJson(json, content);
        if (!error) {

            if(json.containsKey("routineDuration")){
                int routineDuration = json["routineDuration"].as<float>()*1000;
                theater->setRoutineDuration(routineDuration);
                Serial.print("2");
                
            }

            if (json.containsKey("stageLightColor")) {
                int stageLightColor = json["stageLightColor"];
                theater->setStageLightColor(stageLightColor, 0,0);
                
            }

            if(json.containsKey("stageLightStartTime")) {
                bool stageLightStartTime = json["stageLightStartTime"].as<int>();
                theater->setStageLightStartTime(stageLightStartTime);
            }

             if(json.containsKey("stageLightEndTime")) {
                bool stageLightEndTime = json["stageLightEndTime"].as<int>();
                theater->setStageLightEndTime(stageLightEndTime);
            }

            if (json.containsKey("stageLightBrightness")) {
                int stageLightBrightness = json["stageLightBrightness"].as<int>();;
                theater->setStageLightBrightness(stageLightBrightness);
            }

            if(json.containsKey("musicSong")){
                int musicSong = json["musicSong"].as<int>();
                theater->setMusicSong(musicSong);   
            }

            if(json.containsKey("musicVolume")){
                int musicVolume = json["musicVolume"].as<int>();
                theater->setMusicVolume(musicVolume);   
            }

            if(json.containsKey("musicStartTime")){
                int musicStartTime = json["musicStartTime"].as<int>();
                theater->setMusicStartTime(musicStartTime);   
            }

            if(json.containsKey("musicEndTime")){
                int musicEndTime = json["musicEndTime"].as<int>();
                theater->setMusicEndTime(musicEndTime);   
            }


        }
    }
  
}

void BluetoothMsgTask::notify() {
    // int blindOpenPercentage = room->getRollerBlinds()->getOpenPercentage();
    // int lightOn = room->getLight()->isOn() ? 1 : 0;
    // String controlMode = "";
    // if (room->isAutoMode()) {
    //     controlMode = "AUTO";
    // } else if (room->isSerialMode()) {
    //     controlMode = "MANUAL_SERIAL";
    // } else if (room->isBluetoothMode()) {
    //     controlMode = "MANUAL_BT";
    // }
    int routineDuration = theater->getRoutineDuration();
    String updateString = "{";
    updateString += "\"routineDuration\": " + String(routineDuration) + ",";
    // updateString += "\"lightOn\": " + String(lightOn) + ",";
    // updateString += "\"controlMode\": \"" + controlMode + "\"";
    // updateString += "}";
    channel->sendMsg(Msg(updateString));
}