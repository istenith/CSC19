#ifndef KEY_H
#define KEY_H

class Key {
    virtual inline void isPressed(int key_code) = 0;
    virtual inline bool isPressed() = 0;
    virtual inline bool hasKeyStroke() = 0;
    virtual inline bool processKeyStroke() = 0;
};

#endif
