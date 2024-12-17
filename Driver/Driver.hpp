#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <Arduino.h>
#include <Encoder.hpp>
#include <DCMotor.hpp>

/**
 * @brief
 *
 *      This is a simple movement class that uses DCMotor library to give power to motors
 *  and Encoder library to measure distance. It can be used only with encoders attached to
 *  motors, and so, it is not very precise. For greater precision, library Localizer and PIDs
 *  will be coming soon.
 *      goFront(), goBack() and rotate() could potentionally be override to implement higher
 *  precision through mechanisms like dead wheels. Or Encoder.read() could be override to combine
 *  motors encoders and something else like an accelerometer or dead wheels.
 *
 */

/**
 * @brief
 *      I was thinking that I could transform this Driver class into simply encoder+motor and then
 * create other classes that inheriate and override functions of this class like DoubleDriver and
 * QuadDriver.
 *      This way, the function rotate is different for each of them and cannot be created with one wheel,
 * and so I will not be including it in this file.
 */

#define KP 0.89 //! TO BE REMOVED LATER.

class Driver
{
public:
    Driver(Encoder &enc, DCMotor &dc);
    virtual void goFront(int speed, int distance);
    virtual void goBack(int speed, int distance);
    virtual void stop();

protected:
    Encoder &enc;
    DCMotor &dc;
};

#endif

/**
 * @brief
 *
 * TODO:
 *  1. Implement ZeroPowerBehavior();
 *
 */