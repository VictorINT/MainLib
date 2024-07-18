#ifndef DOUBLEDRIVER_HPP
#define DOUBLEDRIVER_HPP

#include <Arduino.h>
#include <Driver.hpp>

class DoubleDriver : public Driver
{
public:
    DoubleDriver(Encoder &enc, DCMotor &dc, Encoder &encoder2, DCMotor &motor2)
        : Driver(enc, dc), encoder2(encoder2), motor2(motor2) {}

    virtual void goFront(int speed, int distance) override;
    virtual void goBack(int speed, int distance) override;
    void rotate(int speed, int angle);

protected:
    Encoder &encoder2;
    DCMotor &motor2;
};

#endif