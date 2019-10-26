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

void UltrasonicKey::setKeyCode(int key_code) { _key_code = key_code; }

int UltrasonicKey::getDistance()
{
    // Clear residual signal
    digitalWrite(_trigger_pin, LOW);
    delay(2);

    // Send ultrasonic signal
    digitalWrite(_trigger_pin, HIGH);
    delay(10);

    // Get duration
    float duration = pulseIn(_echo_pin, HIGH);

    // speed of sound ~0.34cm/ms
    return duration * 0.34 / 2;
}

inline bool UltrasonicKey::isPressed() { return getDistance() <= _threshold_distance; }

inline bool UltrasonicKey::hasKeyStroke()
{
    // returns true only once initially while key is pressed
    if (isPressed()) {
        return !_was_pressed;
    } else {
        _was_pressed = false;
    }
}

inline bool UltrasonicKey::processKeyStroke(int key_code)
{
    // Writes directly

    if (key_code == -1) {
        key_code = _KEY_CODE;
    }

    if (hasKeyStroke()) {
        Keyboard.write(key_code);
    }
}

