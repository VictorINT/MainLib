#ifndef SERVO_HPP
#define SERVO_HPP

#include <Arduino.h>
#include <Servo.h>

class Servo
{
public:
    Servo(int pin);
    void begin();
    void moveTo(int angle);

private:
    int _pin;
    Servo _servo;
};

#endif
