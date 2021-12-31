#pragma once

#include <ESP8266WiFi.h>
#include <VitoWiFi.h>

void callback(char* topic, byte* payload, unsigned int length);
void setupMQTTCallbacks();

extern VitoWiFiClass<P300> VitoWiFi;
