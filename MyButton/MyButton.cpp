#include "MyButton.h"

MyButton::MyButton(int pin) : button(pin), isPressing(false), isLongDetected(false), shortPressCallback(nullptr), longPressCallback(nullptr) {}

void MyButton::setup(void (*shortCallback)(), void (*longCallback)()) {
  button.setDebounceTime(50);
  shortPressCallback = shortCallback;
  longPressCallback = longCallback;
}

void MyButton::update() {
    button.loop();
    // ... existing button logic ...
    if(button.isPressed()){
      pressedTime = millis();
      isPressing = true;
      isLongDetected = false;
    }
    if(button.isReleased()) {
      isPressing = false;
      long pressDuration = millis() - pressedTime;
      if(pressDuration < ShortPressTime && shortPressCallback != nullptr) {
        shortPressCallback(); // Call the short press function
      }
    }
    if(isPressing && !isLongDetected) {
      long pressDuration = millis() - pressedTime;
      if(pressDuration > LongPressTime && longPressCallback != nullptr) {
        isLongDetected = true;
        longPressCallback(); // Call the long press function
      }
    }
  }