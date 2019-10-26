#ifndef PUSH_KEY_H
#define PUSH_KEY_H

#include "Arduino.h"
#include "Keyboard.h"
#include "key.h"

class PushKey : public Key {
    int _read_pin;

  public:
    PushKey();

    explicit PushKey(const int read_pin);
    PushKey(const int read_pin, const int key_code);

    void setPins(const int read_pin);

    bool isPressed() override;
};

#endif /* ifndef PUSH_KEY_H */
