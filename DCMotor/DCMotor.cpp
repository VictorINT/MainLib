#include "DCMotor.hpp"

DCMotor::DCMotor(int pin1, int pin2)
    : _pin1(pin1), _pin2(pin2) {}

void DCMotor::init()
{
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
}

void DCMotor::moveForward(int speed)
{
    analogWrite(_pin1, speed);
    analogWrite(_pin2, 0);
}

void DCMotor::moveBackward(int speed)
{
    analogWrite(_pin1, 0);
    analogWrite(_pin2, speed);
}

void DCMotor::halt()
{
    analogWrite(_pin1, 0);
    analogWrite(_pin2, 0);
}
