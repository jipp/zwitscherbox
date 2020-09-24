#include <Arduino.h>

#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

const int32_t softwareSerialSpeed = 9600;
const uint8_t volume = 10;
int song = 1;

SoftwareSerial softwareSerial(0, 1); // RX, TX
DFRobotDFPlayerMini dfRobotDFPlayerMini;

void setup()
{
  softwareSerial.begin(softwareSerialSpeed);

  if (!dfRobotDFPlayerMini.begin(softwareSerial))
  {
    while (true)
    {
      ;
    }
  }

  dfRobotDFPlayerMini.volume(volume);
  dfRobotDFPlayerMini.play(song);
}

void loop()
{
}