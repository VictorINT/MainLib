#include "Servo.hpp"

Servo::Servo(int pin)
    : _pin(pin) {}

void Servo::begin()
{
    _servo.attach(_pin);
}

void Servo::moveTo(int angle)
{
    _servo.write(angle);
}
