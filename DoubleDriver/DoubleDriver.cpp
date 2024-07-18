#include "DoubleDriver.hpp"

DoubleDriver::DoubleDriver(Encoder &enc, DCMotor &dc, Encoder &encoder2, DCMotor &motor2)
    : encoder2(encoder2), motor2(motor2)
{
    enc.init();
    dc.init();
    encoder2.init();
    motor2.init();
}

virtual void DoubleDriver::goFront(int speed, int distance)
{
    enc.reset();
    encoder2.reset();
    int nrthicks = round((float)((distance * 119) / 19.154) * KP);
    while ((enc.read() + encoder2.read()) / 2 < nrthicks)
    {
        dc.moveForward(speed);
        motor2.moveForward(speed);
        enc.update();
        encoder2.update();
        Serial.println(enc.read());
        Serial.println(encoder2.read());
    }
}

virtual void DoubleDriver::goBack(int speed, int distance)
{
    enc.reset();
    encoder2.reset();
    int nrthicks = round((float)((distance * 119) / 19.154) * KP);
    while ((enc.read() + encoder2.read()) / 2 < nrthicks)
    {
        dc.moveBackward(speed);
        motor2.moveBackward(speed);
        enc.update();
        encoder2.update();
        Serial.println(enc.read());
        Serial.println(encoder2.read());
    }
}

void DoubleDriver::rotate(int distance, int angle)
{
    enc.reset();
    encoder2.reset();
}

/**
 * @brief
 *  TODO:
 *  1. measure how many thicks it takes to rotate 90 degrees and create rotate()
 *      ! formula: nr degrees to rotate = ((nr thicks for 90 degrees) * the angle to rotate)/90
 *  TODO:
 *  2. instad of using exact number, pass to constructor of Driver also wheel diameter and nr of thicks per full rotation
 *
 */