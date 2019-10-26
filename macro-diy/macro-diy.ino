#include "ultrasonic-key.h"

UltrasonicKey us_button(5, 6, 7);

void setup()
{
}

void loop()
{
  if(us_button.hasKeyStroke()) {
    Serial.println("Alpha Male");
  }
}
