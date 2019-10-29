/*
 * Header only library for LDR module to work as a keyboard key over USB
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

#ifndef LDR_KEY_H
#define LDR_KEY_H

#include "Arduino.h"
#include "key.hpp"

template <bool IsDigital>
class LdrKey : public Key {
    int _pin;
    int _threshold;

  public:
    LdrKey();
    explicit LdrKey(int pin);
    LdrKey(int pin, int key_code);

    void setPins(int pin);
    void setTreshold(int threshold);

    bool isPressed() override;
};

using DigitalLdrKey = LdrKey<true>;
using AnalogLdrKey = LdrKey<false>;


template <bool IsDigital>
LdrKey<IsDigital>::LdrKey()
{
}

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
    return analogRead(_pin) > _threshold;
}

#endif /* ifndef LDR_KEY_H */
