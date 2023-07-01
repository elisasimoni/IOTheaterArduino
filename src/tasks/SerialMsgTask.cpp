#include <Arduino.h>
#include <ArduinoJson.h>
#include "SerialMsgTask.h"



SerialMsgTask::SerialMsgTask(SmartTheater* theater) {
    this->channel = new MsgServiceSerial();
    this->channel->init();
    
    this->theater = theater;
}

void SerialMsgTask::tick() {
    if (channel->isMsgAvailable()) {
        Msg* msg = channel->receiveMsg();
        String content = msg->getcontent();
        delete(msg);
        handleContent(content);
    }
    notify();
}


void SerialMsgTask::handleContent(String content) {
    if(theater->isSerialMode()){
        theater->setSerialMode();
        DynamicJsonDocument json(128);
        DeserializationError error = deserializeJson(json, content);
        if (!error) {
        
            // input from Serial
            if (theater->isSerialMode()) {
                if (json.containsKey("actorPresence")) {
                    int actorPresence = json["actorPresence"].as<int>();
                    theater->setDistanceActor(actorPresence);
                }

                if (json.containsKey("light")) {
                    bool audienceLight = json["light"].as<bool>();
                    //theater->setAudienceLight(audienceLight);
                }
            }
        }
    }
}

void SerialMsgTask::notify() {
    int musicSong = theater->getMusic()->getSong();
    int musicVolume = theater->getMusic()->getVolume();
    int curtainsState = theater->getCurtains()->getPercentage();
    int stageLightBrightness = theater->getStageLightSystem()->getBrightness();
    int stageLightColor = theater->getStageLightSystem()->getRGB();
    int spotlightState = theater->getSpotlight()->getState();



    // int stageLightColor = theater->getStageLightSystem()
    // int spotlightState = theater->getSpotlight()
    // int audienceLightState = theater->getAudienceLightSystem()
    // int lightOn = room->getLight()->isOn() ? 1 : 0;
    // String controlMode = "";
    // if (room->isAutoMode()) {
    //     controlMode = "AUTO";
    // } else if (room->isSerialMode()) {
    //     controlMode = "MANUAL_SERIAL";
    // } else if (room->isBluetoothMode()) {
    //     controlMode = "MANUAL_BT";
    // }
    
    String updateString = "{";
    updateString += "\"musicSong\": " + String(musicSong) + ",";
    updateString += "\"musicVolume\": " + String(musicVolume) + ",";
    updateString += "\"curtainsState\": " + String(curtainsState) + ",";
    updateString += "\"stageLightBrightness\": " + String(stageLightBrightness) + ",";
    updateString += "\"stageLightColor\": " + String(stageLightColor) + ",";
    updateString += "\"spotlightState\": " + String(spotlightState) + ",";



    // updateString += "\"lightOn\": " + String(lightOn) + ",";
    // updateString += "\"controlMode\": \"" + controlMode + "\"";
    // updateString += "}";
    //channel->sendMsg(Msg(updateString));
}