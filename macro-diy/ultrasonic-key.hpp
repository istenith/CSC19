/*
 * Header only library for a 4 pin ultrasonic sensor to work as a keyboard key over USB
 * Copyright © 2019 Abhay Raj Singh
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef ULTRASONIC_KEY_H
#define ULTRASONIC_KEY_H

#include "Arduino.h"
#include "key.hpp"

class UltrasonicKey : public Key {
    int _trigger_pin, _echo_pin;
    int _threshold_distance = 6; // setting 6cm by default

    int getDistance();

  public:
    UltrasonicKey();
    UltrasonicKey(int trigger_pin, int echo_pin, int threshold_distance);

    void setPins(int trigger_pin, int echo_pin);
    void setThreshold(int threshold_distance);

    bool isPressed() override;
};

UltrasonicKey::UltrasonicKey() {}

// Using member initialiser list
UltrasonicKey::UltrasonicKey(int trigger_pin, int echo_pin, int threshold_distance)
    : _trigger_pin(trigger_pin)
    , _echo_pin(echo_pin)
    , _threshold_distance(threshold_distance)
{
    pinMode(trigger_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
}

void UltrasonicKey::setPins(int trigger_pin, int echo_pin)
{
    _trigger_pin = trigger_pin;
    _echo_pin = echo_pin;

    pinMode(trigger_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
}

void UltrasonicKey::setThreshold(int threshold_distance)
{
    _threshold_distance = threshold_distance;
}

int UltrasonicKey::getDistance()
{
    // Clear residual signal
    digitalWrite(_trigger_pin, LOW);
    delay(2);

    // Send ultrasonic signal 8 shots @ 40KHz
    digitalWrite(_trigger_pin, HIGH);
    delay(10);

    // Get duration
    float duration = pulseIn(_echo_pin, HIGH);

    // speed of sound ~0.34cm/ms return taken into account
    return duration * 0.34 / 2;
}

inline bool UltrasonicKey::isPressed() { return getDistance() <= _threshold_distance; }

#endif /* ifndef ULTRASONIC_KEY_H */
