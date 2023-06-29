#include "MsgServiceBluetooth.h"


MsgServiceBluetooth::MsgServiceBluetooth(int rxPin, int txPin) {
    this->channel = new SoftwareSerial(rxPin, txPin);
}

void MsgServiceBluetooth::init() {
    channel->begin(9600);
    content.reserve(256);
    content = "";
    currentMsg = NULL;
    availableMsg = false;
}

bool MsgServiceBluetooth::isMsgAvailable() {

  if (channel->available()) {
        char ch = (char) channel->read();
        Serial.print(ch);

        if (ch == '\n') {
            Serial.println(content);
            currentMsg = new Msg(content);
            String cont = currentMsg->getcontent();
           
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