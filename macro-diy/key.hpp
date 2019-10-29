/*
 * Header only library for providing base class button/switch to work as a keyboard key over USB
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

#ifndef KEY_H
#define KEY_H

#include "Arduino.h"
#include "Keyboard.h"

class Key {
    bool _was_pressed = false;

  protected:
    int _key_code = 0x04; // A
  public:
    inline void setKeyCode(int key_code = -1) { _key_code = key_code; }
    virtual inline bool isPressed();
    inline bool hasKeyStroke()
    {
        if (isPressed()) {
            return !_was_pressed;
        } else {
            _was_pressed = false;
            return false;
        }
    }
    inline void processKeyStroke()
    {
        if (hasKeyStroke()) {
            Keyboard.write(_key_code);
        }
    }
};

#endif
