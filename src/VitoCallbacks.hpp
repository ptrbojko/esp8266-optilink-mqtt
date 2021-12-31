#pragma once

#include <VitoWiFi.h>

void tempCallbackHandler(const IDatapoint& dp, DPValue value);
void unsignedByteCallbackHandler(const IDatapoint& dp, DPValue value);
void shortCallbackHandler(const IDatapoint& dp, DPValue value);
void intCallbackHandler(const IDatapoint& dp, DPValue value);