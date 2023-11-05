#include <ESP8266WiFi.h>
#include "Properties.hpp"
#include "VitoDataPoints.hpp"
#include "MQTTCallbacks.hpp"

const char* SET_POSTFIX = "set";
const char* CMD_POSTFIX = "cmd";

void setFlowM2NSTmpCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(flowM2NormalSetTemp, DPValue(value));
}

void setFlowM2RSTmpCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(flowM2ReducedSetTemp, DPValue(value));
}

void setFlowM2PSTmpCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(flowM2PartySetTemp, DPValue(value));
}

void setFlowM3NSTmpCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(flowM3NormalSetTemp, DPValue(value));
}

void setFlowM3RSTmpCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(flowM3ReducedSetTemp, DPValue(value));
}

void setFlowM3PSTmpCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(flowM3PartySetTemp, DPValue(value));
}

void setTankSetTempCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(tankSetTemp, DPValue(value));
}

void setFlowM2OperatingModeCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(flowM2OperatingMode, DPValue(value));
}

void setFlowM3OperatingModeCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(flowM3OperatingMode, DPValue(value));
}

void setFlowM2EModeCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(flowM2EcoMode, DPValue(value));
}

void setFlowM2PModeCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(flowM2PartyMode, DPValue(value));
}

void setFlowM3EModeCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(flowM3EcoMode, DPValue(value));
}

void setFlowM3PModeCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(flowM3PartyMode, DPValue(value));
}

void setTankCircModeCallback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(tankCircMode, DPValue(value));
}

void setTankCircMode2Callback(byte* payload, unsigned int length) {
    uint8_t value = atoi((char*)payload);
    VitoWiFi.writeDatapoint(tankCircMode2, DPValue(value));
}

struct CallbackMapProto {
    IDatapoint* datapoint;
    const char* postfix;
    void (*callback)(byte* payload, unsigned int length);
};

const int CALLBACKS_COUNT = 15;

CallbackMapProto CALLBACKS_PROTO[CALLBACKS_COUNT] = {
    {&tankSetTemp, SET_POSTFIX, setTankSetTempCallback},
    {&flowM2NormalSetTemp, SET_POSTFIX, setFlowM2NSTmpCallback},
    {&flowM2ReducedSetTemp, SET_POSTFIX, setFlowM2RSTmpCallback},
    {&flowM2PartySetTemp, SET_POSTFIX, setFlowM2PSTmpCallback},
    {&flowM3NormalSetTemp, SET_POSTFIX, setFlowM3NSTmpCallback},
    {&flowM3ReducedSetTemp, SET_POSTFIX, setFlowM3RSTmpCallback},
    {&flowM3PartySetTemp, SET_POSTFIX, setFlowM3PSTmpCallback},
    {&flowM2OperatingMode, SET_POSTFIX, setFlowM2OperatingModeCallback},
    {&flowM3OperatingMode, SET_POSTFIX, setFlowM3OperatingModeCallback},
    {&flowM2EcoMode, SET_POSTFIX, setFlowM2EModeCallback},
    {&flowM2PartyMode, SET_POSTFIX, setFlowM2PModeCallback},
    {&flowM3EcoMode, SET_POSTFIX, setFlowM3EModeCallback},
    {&flowM3PartyMode, SET_POSTFIX, setFlowM3PModeCallback},
    {&tankCircMode, SET_POSTFIX, setTankCircModeCallback},
    {&tankCircMode2, SET_POSTFIX, setTankCircMode2Callback}
};

char checkedTopic[60];

bool topicMatches(char* topic, CallbackMapProto& callbackMap) {
    sprintf(checkedTopic, "%s/%s/%s/%s",
        topicPrefix,
        callbackMap.datapoint->getGroup(),
        callbackMap.datapoint->getName(),
        callbackMap.postfix);
    return strcmp(topic, checkedTopic) == 0;

}

void callback(char* topic, byte* payload, unsigned int length) {
    char topicCopy[strlen(topic)+1];
    byte payloadCopy[length];
    strcpy(topicCopy, topic);
    memcpy(payloadCopy, payload, length);
    for (int l = 0; l < CALLBACKS_COUNT; l++) {
        if (topicMatches(topic, CALLBACKS_PROTO[l])) {
            CALLBACKS_PROTO[l].callback(payloadCopy, length);
            break;
        }
    }
}