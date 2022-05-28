#include <Arduino.h>

#include <iostream>
#include "SoftwareSerial.h"

const uint16_t pirPin = D0;
const int32_t softwareSerialSpeed = 9600;
unsigned char order[4] = {0xAA, 0x06, 0x00, 0xB0};
bool pirFlag = false;

SoftwareSerial softwareSerial(D3, D4); // RX, TX

void play(unsigned char track)
{
  std::cout << "play" << std::endl;
  unsigned char play[6] = {0xAA, 0x07, 0x02, 0x00, track, track + 0xB3};
  softwareSerial.write(play, 6);
}
void volume(unsigned char vol)
{
  unsigned char volume[5] = {0xAA, 0x13, 0x01, vol, vol + 0xBE};
  softwareSerial.write(volume, 5);
}

void setup()
{
  Serial.begin(SPEED);
  softwareSerial.begin(softwareSerialSpeed);
  pinMode(pirPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  volume(0x1E);
}

void loop()
{
  std::cout << "start" << std::endl;
  play(0x01);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  ESP.deepSleep(0);
  std::cout << "end" << std::endl;
}