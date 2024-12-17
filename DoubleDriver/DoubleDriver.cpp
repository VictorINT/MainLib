#include "DoubleDriver.hpp"

DoubleDriver::DoubleDriver(Encoder &enc, DCMotor &dc, Encoder &encoder2, DCMotor &motor2)
    : Driver(enc, dc), encoder2(encoder2), motor2(motor2)
{
    enc.init();
    dc.init();
    encoder2.init();
    motor2.init();
}

void DoubleDriver::goFront(int speed, int distance)
{
    enc.reset();
    encoder2.reset();
    int nrthicks = round((float)((distance * 119) / 19.154) * KP);
    // while ((enc.read() + encoder2.read()) / 2 < nrthicks) // mean between two of them
    while (enc.read() < nrthicks)
    {
        dc.moveForward(speed);
        motor2.moveForward(speed);
        enc.update();
        encoder2.update();
        Serial.println(enc.read());
        Serial.println(encoder2.read());
    }
}

void DoubleDriver::goBack(int speed, int distance)
{
    enc.reset();
    encoder2.reset();
    int nrthicks = round((float)((distance * 119) / 19.154) * KP);
    while (enc.read() < nrthicks)
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

void DoubleDriver::stop()
{
    dc.halt();
    motor2.halt();
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

/**
 * @brief
 * TODO:
 * Implement Localizer class that takes encoder/s and gives you position based to the starting point
 *  ! getPos() returns -> (x,y) coords.
 *  ! getDistance() returns -> distance from origin to this point
 *  ! updatePos() updates encoders
 *  ! setStartingPosition() -> sets startX and startY to custome coords.
 *
 */

/**
 * @brief
 * TODO:
 *  1. class PID? with kp, kd, ki configured.
 * TODO:
 *  2. You can pass it to Driver or smth and it uses it + The Localizer to move to a certain point
 *  TODO: (x,y) from (x0,y0) with great accuracy.
 *
 */