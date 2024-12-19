#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <Encoder.hpp>

struct WHEEL
{
    float diameter;                                   //! IN CENTIMETERS
    float distanceFromCenter_x, distanceFromCenter_y; //! Relative to robot's center
};

struct ROBOT
{
    /**
     * @brief
     *  ! Firstly define your wheels
     *  ! Example:
     */
    WHEEL left = {5.4f, -7.65f, 18.2f};
    WHEEL right = {5.4f, 7.65f, 18.2f};
    float distanceBetweenWheels = abs(left.distanceFromCenter_x) + abs(right.distanceFromCenter_x);
    float weight = 0.0f; // will measure it later.
};

/**
 * @brief
 * ! Define encoders with pins
 * ! Example:
 */

Encoder encoderLeft(2, 3);
Encoder encoderRight(6, 9); // not working

#define NR_OF_ENCODERS 2;
#define FROM_ENCODER_THICKS_TO_CENTIMETERS 100; //!???

Encoder ENCODERS_ARRAY[NR_OF_ENCODERS] = {encoderLeft, encoderRight};

/**
 * @brief
 * TODO: Define a way to have different encoders configurations
 * ! In this example we have only one encoder working, the left one.
 */

/**
 * @brief
 * ! Differential driving encoder:
 * ! Measures only back and forth, no way of measuring left and right, nor of rotating witha accuracy.
 */

typedef struct ROBOT ROBOT;

#endif
