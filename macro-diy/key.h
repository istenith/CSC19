#ifndef KEY_H
#define KEY_H


class Key {
  protected:
    int _key_code = 0x04; // A
    bool _was_pressed = false;

  public:
    virtual inline bool isPressed() = 0;
    virtual inline void setKeyCode(const int key_code) { _key_code = key_code; }
    virtual inline bool hasKeyStroke();
    virtual inline bool processKeyStroke(int key_code = -1);
};

inline bool Key::hasKeyStroke()
{
    // returns true only once initially while key is pressed
    if (isPressed()) {
        return !_was_pressed;
    } else {
        _was_pressed = false;
		return false;
    }
}

bool Key::processKeyStroke(int key_code)
{
    // Writes directly

    if (key_code == -1) {
        key_code = _key_code;
    }

    if (hasKeyStroke()) {
        Keyboard.write(key_code);
    }
}
#endif
