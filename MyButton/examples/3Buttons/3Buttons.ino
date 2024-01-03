#include <MyButton.h>

/* must have ezButton library installed

option to connect buzzer: to test
connect buzzer to pin 2 and uncomment
corresponding code in sketch */

MyButton btn1(3);
MyButton btn2(4);
MyButton btn3(5);

// const int buzzer = 2; // uncomment if buzzer attached
void beeper(int numBeeps, int beepDuration)
{
  for (int i = 0; i < numBeeps; i++)
  {
    // digitalWrite(buzzer, HIGH); // uncomment if buzzer attached
    digitalWrite(LED_BUILTIN, HIGH);
    delay(beepDuration);
    // digitalWrite(buzzer, LOW); // uncomment if buzzer attached
    digitalWrite(LED_BUILTIN, LOW);
    delay(beepDuration);
  }
}

void btn1ShortPress()
{
  Serial.println("Button 1 Short Pressed");
  beeper(1, 50);
}

void btn1LongPress()
{
  Serial.println("Button 1 Long Pressed");
  beeper(1, 150);
}

void btn2ShortPress()
{
  Serial.println("Button 2 Short Pressed");
  beeper(2, 50);
}

void btn2LongPress()
{
  Serial.println("Button 2 Long Pressed");
  beeper(2, 150);
}

void btn3ShortPress()
{
  Serial.println("Button 3 Short Pressed");
  beeper(3, 50);
}

void btn3LongPress()
{
  Serial.println("Button 3 Long Pressed");
  beeper(3, 150);
}

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  // pinMode(buzzer, OUTPUT); // uncomment if buzzer attached

  btn1.setup(btn1ShortPress, btn1LongPress);
  btn2.setup(btn2ShortPress, btn2LongPress);
  btn3.setup(btn3ShortPress, btn3LongPress);
}

void loop()
{
  btn1.update();
  btn2.update();
  btn3.update();
}