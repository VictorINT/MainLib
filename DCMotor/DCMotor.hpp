#ifndef DCMOTOR_HPP
#define DCMOTOR_HPP

#include <Arduino.h>

#define FORWARD true
#define BACKWARD false

class DCMotor
{
public:
    DCMotor(int pin1, int pin2);
    void init();
    void moveForward(int speed);
    void moveBackward(int speed);
    void halt();

private:
    int _pin1;
    int _pin2;
};

#endif
