#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <Arduino.h>
#include <ezButton.h>

class MyButton {
  public:
    MyButton(int pin);
    static const int ShortPressTime = 1000;
    static const int LongPressTime = 1000;
    void setup(void (*shortCallback)(), void (*longCallback)());
    void update();
  private:
    ezButton button;
    unsigned long pressedTime;
    bool isPressing;
    bool isLongDetected;
    void (*shortPressCallback)();
    void (*longPressCallback)();
};

#endif