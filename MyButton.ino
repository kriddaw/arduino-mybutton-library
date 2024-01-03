#include <ezButton.h>

class MyButton {
public:
  ezButton button;
  unsigned long pressedTime;
  bool isPressing;
  bool isLongDetected;
  static const int ShortPressTime = 1000;
  static const int LongPressTime = 1000;

  // Function pointers for callbacks
  void (*shortPressCallback)() = nullptr;
  void (*longPressCallback)() = nullptr;

  MyButton(int pin) : button(pin), isPressing(false), isLongDetected(false) {}

  void setup(void (*shortCallback)(), void (*longCallback)()) {
    button.setDebounceTime(50);
    shortPressCallback = shortCallback;
    longPressCallback = longCallback;
  }

  void update() {
    button.loop();
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
};

MyButton btn1(3);
MyButton btn2(4);
MyButton btn3(5);

const int buzzer = 2;
void beeper(int numBeeps, int beepDuration) {
  for (int i = 0; i < numBeeps; i++) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(beepDuration);
    digitalWrite(buzzer, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(beepDuration);
  }
}

void btn1ShortPress() {
  Serial.println("Button 1 Short Pressed");
  beeper(1, 50);
}

void btn1LongPress() {
  Serial.println("Button 1 Long Pressed");
  beeper(1, 150);
}

void btn2ShortPress() {
  Serial.println("Button 2 Short Pressed");
  beeper(2, 50);
}

void btn2LongPress() {
  Serial.println("Button 2 Long Pressed");
  beeper(2, 150);
}

void btn3ShortPress() {
  Serial.println("Button 3 Short Pressed");
  beeper(3, 50);
}

void btn3LongPress() {
  Serial.println("Button 3 Long Pressed");
  beeper(3, 150);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(buzzer, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  btn1.setup(btn1ShortPress, btn1LongPress);
  btn2.setup(btn2ShortPress, btn2LongPress);
  btn3.setup(btn3ShortPress, btn3LongPress);
}

void loop() {
  // put your main code here, to run repeatedly:
  btn1.update();
  btn2.update();
  btn3.update();
}
