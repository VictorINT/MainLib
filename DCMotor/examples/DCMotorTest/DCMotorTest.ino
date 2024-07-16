#include <DCMotor.hpp>
#include <Arduino.h>

void setup()
{
  DCMotor left(3, 5);
  DCMotor right(6, 9);
  left.init();
  right.init();
  left.moveForward(255);
  right.moveBackward(255);
  delay(2000);
  left.halt();
  right.halt();
}

void loop()
{
  
}
