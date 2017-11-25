#include "Bluetooth.h"

#define STATE_PIN 0
#define EN_PIN 2
#define ERROR_PIN 13
#define VALUE_COUNT 1
//variables

int ToRead[VALUE_COUNT], ToWrite[VALUE_COUNT];

Bluetooth *Master;

void setup() {
  Master = new Bluetooth(true, ERROR_PIN, EN_PIN, STATE_PIN, VALUE_COUNT);
}

void loop() {
  Master->read();
  Serial.println(Master->getRead(0));
  delay(endDelay);
}

int something()//getting some data to send
{
  return analogRead(0);
}
