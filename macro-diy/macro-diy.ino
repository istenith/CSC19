#include "push-key.h"
#include "ultrasonic-key.h"

UltrasonicKey us_button(5, 6, 7);
PushKey pk_button(2, 0x52);

void setup() {}

void loop()
{
	us_button.processKeyStroke();
}
