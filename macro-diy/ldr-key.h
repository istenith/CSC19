#ifndef LDR_KEY_H
#define LDR_KEY_H

#include "Arduino.h"
#include "key.h"

template <bool IsDigital>
class LdrKey : Key {
    int _pin;
    int _threshold;

  public:
    LdrKey() = 0;
    explicit LdrKey(int pin);
    LdrKey(int pin, int key_code);
    void setPins(int pin);
    void setTreshold(int threshold);

    bool isPressed() override;
};

#endif /* ifndef LDR_KEY_H */
