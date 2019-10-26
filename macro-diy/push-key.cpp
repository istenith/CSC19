#include "push-key.h"

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

bool PushKey::isPressed() { return digitalRead(_read_pin); }

