#ifndef ULTRASONIC_KEY_H
#define ULTRASONIC_KEY_H

#include "key.h"

class UltrasonicKey : Key {
    int _trigger_pin, _echo_pin;
    int _threshold_distance = 6; // setting 6cm by default
    int _key_code = 0x04;        // A
    bool _was_pressed;

    int getDistance();

  public:
    UltrasonicKey();
    UltrasonicKey(int trigger_pin, int echo_pin, int threshold_distance);

    void setPins(int trigger_pin, int echo_pin);
    void setThreshold(int threshold_distance);

    void setKeyCode(int key_code);
    bool isPressed();
    bool hasKeyStroke();
    bool processKeyStroke(int key_code = -1);
};

#endif
