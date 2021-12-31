#include <Arduino.h>
#include <VitoWiFi.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "Properties.hpp"
#include "Connection.hpp"
#include "VitoCallbacks.hpp"
#include "VitoDataPoints.hpp"

VitoWiFi_setProtocol(P300);

void setup() {
  boilerTargetTemp.setCallback(tempCallbackHandler);
  boilerRealTemp.setCallback(tempCallbackHandler);
  operatingMode.setCallback(unsignedByteCallbackHandler);
  heatingValveStatus.setCallback(unsignedByteCallbackHandler);

  outRealTemp.setCallback(tempCallbackHandler);
  outMeanTemp.setCallback(tempCallbackHandler);
  
  flowM2RealTemp.setCallback(tempCallbackHandler);
  flowM2TargetTemp.setCallback(tempCallbackHandler);
  flowM2NormalSetTemp.setCallback(unsignedByteCallbackHandler);
  flowM2ReducedSetTemp.setCallback(unsignedByteCallbackHandler);
  flowM2PartySetTemp.setCallback(unsignedByteCallbackHandler);
  flowM2OperatingStatus.setCallback(unsignedByteCallbackHandler);
  flowM2OperatingMode.setCallback(unsignedByteCallbackHandler);
  flowM2EcoMode.setCallback(unsignedByteCallbackHandler);
  flowM2PartyMode.setCallback(unsignedByteCallbackHandler);

  flowM3RealTemp.setCallback(tempCallbackHandler);
  flowM3TargetTemp.setCallback(tempCallbackHandler);
  flowM3NormalSetTemp.setCallback(unsignedByteCallbackHandler);
  flowM3ReducedSetTemp.setCallback(unsignedByteCallbackHandler);
  flowM3PartySetTemp.setCallback(unsignedByteCallbackHandler);
  flowM3OperatinStatus.setCallback(unsignedByteCallbackHandler);
  flowM3OperatingMode.setCallback(unsignedByteCallbackHandler);
  flowM3EcoMode.setCallback(unsignedByteCallbackHandler);
  flowM3PartyMode.setCallback(unsignedByteCallbackHandler);

  tankRealTemp.setCallback(tempCallbackHandler);
  tankSetTemp.setCallback(unsignedByteCallbackHandler);

  setupWiFi();
  setupMQTT();
  VitoWiFi.setup(&Serial);
}

void loop() {
  static unsigned long lastMillis = 0;
  loopMQTT();
  if (millis() - lastMillis > 60 * 1000UL)   { // read all values every 60 seconds
    lastMillis = millis();
    VitoWiFi.readAll(); 
  }
  VitoWiFi.loop();
}