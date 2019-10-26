#include "ultrasonic-key.h"
#include "Arduino.h"
#include "Keyboard.h"

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
