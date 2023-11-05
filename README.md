# Adapter for Viessman W200 Optolink - MQTT

This is a firmware/sketch for ESP8266 based on a design:
1. [Bauanleitung ESP32 Adafruit Feather Huzzah32 and Proto Wing](https://github.com/openv/openv/wiki/Bauanleitung-ESP32-Adafruit-Feather-Huzzah32-and-Proto-Wing)
2. [Bauanleitung ESP8266](https://github.com/openv/openv/wiki/Bauanleitung-ESP8266)
3. [ESPHome Viessman Optolink](https://deploy-preview-2737--esphome.netlify.app/components/optolink.html) - you may find this more suitable for HA

Optolink for Viessman reverse engineered protocol is described here. 

In short words - you may scratch a little circuit based on ESP8266, ir transmitter for 880nm light wave, ir reader for 880nm light wave and some resistors.

This firmware relies on https://github.com/bertmelis/VitoWifi

## Parts
1. IR reader, 880 nm - https://botland.com.pl/fototranzystory/4245-fototranzystor-sfh-313fa-5mm-870nm-5-szt-5903351245760.html
2. IR transmitter, 880 nm - https://botland.com.pl/diody-ir-podczerwone/1231-nadajnik-ir-lired5b-880-5mm-880nm-5904422300920.html
3. Resistors - https://botland.com.pl/rezystory-oporniki/4549-zestaw-rezystorow-cf-tht-14w-opisany-640szt-5904422353131.html
4. ESP8266 - https://botland.com.pl/moduly-wifi-esp8266/8241-modul-wifi-esp8266-nodemcu-v3-5904422300630.html

## 3D parts
Bauanleitung ESP32 Adafruit Feather Huzzah32 and Proto Wing
1. https://raw.githubusercontent.com/wiki/openv/openv/files/vito.stl
2. https://raw.githubusercontent.com/wiki/openv/openv/files/vito.scad