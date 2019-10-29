#ifndef KEY_H
#define KEY_H

#include "Arduino.h"
#include "Keyboard.h"

class Key {
    bool _was_pressed = false;

  protected:
    int _key_code = 0x04; // A
  public:
    virtual inline void setKeyCode(int key_code = -1);
    virtual inline bool isPressed();
    virtual inline bool hasKeyStroke();
    virtual inline void processKeyStroke();
};

#endif
