/*
 * Header only library for a push button/switch to work as a keyboard key over USB
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

#ifndef PUSH_KEY_H
#define PUSH_KEY_H

#include "Arduino.h"
#include "key.hpp"

class PushKey : public Key {
    int _read_pin;

  public:
    PushKey();

    explicit PushKey(const int read_pin);
    PushKey(const int read_pin, const int key_code);

    void setPins(const int read_pin);

    bool isPressed() override;
};

PushKey::PushKey() {}
PushKey::PushKey(const int read_pin)
    : _read_pin(read_pin)
{
}

PushKey::PushKey(const int read_pin, const int key_code)
    : PushKey(read_pin)
{
    Key::setKeyCode(key_code);
}
void PushKey::setPins(const int read_pin) { _read_pin = read_pin; }

bool PushKey::isPressed() { return digitalRead(_read_pin) == HIGH; }
#endif /* ifndef PUSH_KEY_H */
