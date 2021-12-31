#include "VitoDataPoints.hpp"

// Boiler
DPTemp boilerTargetTemp("boilerTTMp", "boiler", 0x555A); // Temperatura zadana boilera
DPTemp boilerRealTemp("boilerRTmp", "boiler", 0x0802); // Temperatura rzeczywista boilera
DPMode operatingMode("opMode", "boiler", 0x2301); // Status pracy
DPMode heatingValveStatus("opValveSts", "boiler", 0x0A10); // Status zaworu CO/CWU

// External sensor
DPTemp outRealTemp("outRTmp", "extsensor", 0x0800);  // Temperatura rzeczywista czujnika zewn.
DPTemp outMeanTemp("outMTmp", "extsensor", 0x5527);  // Temperatura uśredniona czujnika zewn.

// M2
DPTemp flowM2RealTemp("flowM2RTmp", "M2", 0x3900); // Temperatura rzeczywista w obiegu 2
DPTemp flowM2TargetTemp("flowM2TTmp", "M2", 0x3544); // Temperatura zadana w obiegu 2
DPTempS flowM2NormalSetTemp("flowM2NSTmp", "M2", 0x3306, true); // Temperatura pomieszczenia normalna ustawiona w obiegu 2
DPTempS flowM2ReducedSetTemp("flowM2RSTmp", "M2", 0x3307, true); // Temperatura pomieszczenia zredukowana ustawiona w obiegu 2
DPTempS flowM2PartySetTemp("flowM2PSTmp", "M2", 0x3308, true); // Temperatura pomieszczenia party ustawiona w obiegu 2
DPMode flowM2OperatingStatus("flowM2OpSts", "M2", 0x3301); // Status pracy
DPMode flowM2OperatingMode("flowM2OpMode", "M2", 0x3323, true); // Tryb pracy
DPMode flowM2EcoMode("flowM2EMode", "M2", 0x3302, true); 
DPMode flowM2PartyMode("flowM2PMode", "M2", 0x3303, true); 

// M3
DPTemp flowM3RealTemp("flowM3RTmp", "M3", 0x4900); // Temperatura rzeczywista w obiegu 3
DPTemp flowM3TargetTemp("flowM3TTmp", "M3", 0x4544); // Temperatura zadana w obiegu 3
DPTempS flowM3NormalSetTemp("flowM3NSTmp", "M3", 0x4306, true); // Temperatura pomieszczenia normalna ustawiona w obiegu 2
DPTempS flowM3ReducedSetTemp("flowM3RSTmp", "M3", 0x4307, true); // Temperatura pomieszczenia zredukowana ustawiona w obiegu 2
DPTempS flowM3PartySetTemp("flowM3PSTmp", "M3", 0x4308, true); // Temperatura pomieszczenia zredukowana ustawiona w obiegu 2
DPMode flowM3OperatinStatus("flowM3OpSts", "M3", 0x4301); // Status pracy
DPMode flowM3OperatingMode("flowM3OpMode", "M3", 0x4323, true); // Tryb pracy
DPMode flowM3EcoMode("flowM3EMode", "M2", 0x4302, true); 
DPMode flowM3PartyMode("flowM3PMode", "M2", 0x4303, true); 

// Watertank
DPTemp tankRealTemp("tankRTmp", "watertank", 0x0812); // Temperatura rzeczywista w CWU
DPTempS tankSetTemp("tankSTmp", "watertank", 0x6300, true); // Temperatura ustawiona w CWU
