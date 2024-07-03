#ifndef DCMOTOR_HPP
#define DCMOTOR_HPP

#include <Arduino.h>
#include <Encoder.hpp>

#define FORWARD true
#define BACKWARD false

class DCMotor
{
public:
    DCMotor(int pin1, int pin2);
    void begin();
    void moveForward(int speed);
    void moveBackward(int speed);
    void moveCounts(int speed, bool direction, int counts) void stop();

private:
    int _pin1;
    int _pin2;
};

#endif
