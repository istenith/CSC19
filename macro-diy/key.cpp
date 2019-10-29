#include "key.h"

void Key::setKeyCode(int key_code) { _key_code = key_code; }

bool Key::hasKeyStroke()
{
    if (isPressed()) {
        return !_was_pressed;
    } else {
        _was_pressed = false;
        return false;
    }
}

void Key::processKeyStroke()
{
    if (hasKeyStroke()) {
        Keyboard.write(_key_code);
    }
}
