#include "ldr-key.h"

template <bool IsDigital>
LdrKey<IsDigital>::LdrKey(int pin)
    : _pin(pin)
{
    pinMode(_pin, INPUT);
}

template <bool IsDigital>
LdrKey<IsDigital>::LdrKey(int pin, int key_code)
    : _pin(pin)
{
    Key::setKeyCode(key_code);
    pinMode(_pin, INPUT);
}

template <bool IsDigital>
void LdrKey<IsDigital>::setPins(int pin)
{
    _pin = pin;
    pinMode(_pin, INPUT);
}

template <bool IsDigital>
void LdrKey<IsDigital>::setTreshold(int threshold)
{
    _threshold = threshold;
}

template <>
bool LdrKey<true>::isPressed()
{
    return digitalRead(_pin) == HIGH;
}

template <>
bool LdrKey<false>::isPressed()
{
    return analogRead(_pin) > _treshold;
}
