#ifndef ULTRASONIC_KEY_H
#define ULTRASONIC_KEY_H

#include "key.h"

class UltrasonicKey : public Key {
    int _trigger_pin, _echo_pin;
    int _threshold_distance = 6; // setting 6cm by default

    int getDistance();

  public:
    UltrasonicKey();
    UltrasonicKey(int trigger_pin, int echo_pin, int threshold_distance);

    void setPins(int trigger_pin, int echo_pin);
    void setThreshold(int threshold_distance);

    bool isPressed();
};

#endif /* ifndef ULTRASONIC_KEY_H */
