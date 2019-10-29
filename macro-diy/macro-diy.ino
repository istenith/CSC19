#include "push-key.hpp"
#include "ultrasonic-key.hpp"
#include "ldr-key.hpp"

UltrasonicKey us_button(5, 6, 7);

PushKey pk_button(2, 0x52);

DigitalLdrKey lk_button(3, 0x05);

void setup() {}

void loop()
{
  us_button.processKeyStroke();
  pk_button.processKeyStroke();
  lk_button.processKeyStroke();
}
