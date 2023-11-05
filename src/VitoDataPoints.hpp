#pragma once

#include <VitoWiFi.h>

// boiler
extern DPTemp boilerTargetTemp; // Temperatura zadana boilera
extern DPTemp boilerRealTemp; // Temperatura rzeczywista boilera
extern DPMode operatingMode; // Status palnika
extern DPMode heatingValveStatus; // Status zaworu CO/CWU

// extsensor
extern DPTemp outRealTemp;  // Temperatura rzeczywista czujnika zewn.
extern DPTemp outMeanTemp;  // Temperatura uśredniona czujnika zewn.

// M2
extern DPTemp flowM2RealTemp; // Temperatura rzeczywista w obiegu 2
extern DPTemp flowM2TargetTemp; // Temperatura zadana w obiegu 2
extern DPTempS flowM2NormalSetTemp; // Temperatura pomieszczenia normalna ustawiona w obiegu 2
extern DPTempS flowM2ReducedSetTemp; // Temperatura pomieszczenia zredukowana ustawiona w obiegu 2
extern DPTempS flowM2PartySetTemp; // Temperatura pomieszczenia party ustawiona w obiegu 2
extern DPMode flowM2OperatingStatus; // Status pracy
extern DPMode flowM2OperatingMode; // Status pracy
extern DPMode flowM2EcoMode;
extern DPMode flowM2PartyMode;

// M3
extern DPTemp flowM3RealTemp; // Temperatura rzeczywista w obiegu 3
extern DPTemp flowM3TargetTemp; // Temperatura zadana w obiegu 3
extern DPTempS flowM3NormalSetTemp; // Temperatura pomieszczenia normalna ustawiona w obiegu 2
extern DPTempS flowM3ReducedSetTemp; // Temperatura pomieszczenia zredukowana ustawiona w obiegu 2
extern DPTempS flowM3PartySetTemp; // Temperatura pomieszczenia zredukowana ustawiona w obiegu 2
extern DPMode flowM3OperatinStatus; // Status pracy
extern DPMode flowM3OperatingMode; // Status pracy
extern DPMode flowM3EcoMode;
extern DPMode flowM3PartyMode;

// watertank
extern DPTemp tankRealTemp; // Temperatura rzeczywista w CWU
extern DPTempS tankSetTemp; // Temperatura ustawiona w CWU
extern DPMode tankCircMode; // Cyrkulacja pompy CWU
extern DPMode tankCircMode2; // Cyrkulacja pompy CWU