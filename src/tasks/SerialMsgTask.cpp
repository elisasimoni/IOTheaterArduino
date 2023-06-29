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
   /* if (room->isAutoMode() && content.equals("chmod MANUAL_SERIAL")) {
        room->setSerialMode();
    } else if (room->isSerialMode() && content.equals("chmod AUTO")) {
        room->setAutoMode();
    } else {*/
        // theater->setSerialMode();
        // DynamicJsonDocument json(128);
        // DeserializationError error = deserializeJson(json, content);
        // if (!error) {
        //     if (json.containsKey("routineTimer")) {
        //         int presenceDetected = json["presenceDetected"].as<int>() ? true : false;
        //         theater->setPresenceDetected(presenceDetected);
        //     }

        //     if (json.containsKey("lightLevel")) {
        //         double lightLevel = json["lightLevel"].as<double>();
        //         theater->setLightLevel(lightLevel);
        //     }

        //     if (json.containsKey("hour")) {
        //         int hour = json["hour"].as<int>();
        //         theater->setHour(hour);
        //     }

        //     // input from Serial
        //     if (room->isSerialMode()) {
        //         if (json.containsKey("remoteBlindOpenPercentage")) {
        //             int remoteBlindOpenPercentage = json["remoteBlindOpenPercentage"].as<int>();
        //             theater->setRemoteBlindOpenPercentage(remoteBlindOpenPercentage);
        //         }

        //         if (json.containsKey("remoteLightOn")) {
        //             int remoteLightOn = json["remoteLightOn"].as<int>() == 1 ? true : false;
        //             theater->setRemoteLightValue(remoteLightOn);
        //         }
        //     }
        // }
    }
//}

void SerialMsgTask::notify() {
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
    
    //String updateString = "{";
    // updateString += "\"blindOpenPercentage\": " + String(blindOpenPercentage) + ",";
    // updateString += "\"lightOn\": " + String(lightOn) + ",";
    // updateString += "\"controlMode\": \"" + controlMode + "\"";
    // updateString += "}";
    //channel->sendMsg(Msg(updateString));
}