#include "MsgServiceBluetooth.h"


MsgServiceBluetooth::MsgServiceBluetooth(int rxPin, int txPin) {
    this->channel = new SoftwareSerial(rxPin, txPin);
}

void MsgServiceBluetooth::init() {
    channel->begin(9600);
    //content.reserve(7000);
    content = "";
   
    currentMsg = NULL;
    availableMsg = false;
}

bool MsgServiceBluetooth::isMsgAvailable() {
    Serial.print("\n");
    while (channel->available()) {
        char ch = (char) channel->read();
        if (ch == '\n') {
            Serial.print(content);
            Serial.print("\n");
            currentMsg = new Msg(content);

            if(!currentMsg){
                Serial.print("E' VUOTO!\n");
            }else{
                currentMsg->getcontent();
            }
            availableMsg = true;
            
            return true;
        } else {
           
            content += ch;
        }
    }
    return false;
}

Msg* MsgServiceBluetooth::receiveMsg() {
    if (availableMsg) {
        Serial.print("Siamo fantastici\n");
        Msg* msg = currentMsg;
        availableMsg = false;
        currentMsg = NULL;
        content = "";
        return msg;
    }
    return NULL;
}

void MsgServiceBluetooth::sendMsg(Msg msg) {
    channel->println(msg.getcontent());
}