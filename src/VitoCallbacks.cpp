#include "VitoCallbacks.hpp"
#include "Connection.hpp"
#include "Properties.hpp"

void publish(const IDatapoint& dp, char* value) {
  char topic[sizeof(topicPrefix) + sizeof(dp.getGroup()) + sizeof(dp.getName()) + 5];
  sprintf(topic, "%s/%s/%s", topicPrefix, dp.getGroup(), dp.getName());
  client.publish(topic, value);
}

void tempCallbackHandler(const IDatapoint& dp, DPValue value) {
  char result[8];
  dtostrf(value.getFloat(), 1, 2, result);
  publish(dp, result);
}

void unsignedByteCallbackHandler(const IDatapoint& dp, DPValue value) {
  char result[8];
  ltoa(value.getU8(), result, 10);
  publish(dp, result);
}