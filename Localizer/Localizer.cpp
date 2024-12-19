#include "Encoder.hpp"

Localizer::Localizer()
{
    for (int i = 0; i < NR_OF_ENCODERS; i++)
    {
        ENCODERS_ARRAY[i].init();
        _lastPosition[i] = 0;
    }
    rotateAngle = 0.0f;
}

void increaseRotateAngle(float *rtAng, float value)
{
    //! Increasig triconometrically
    *rtAng += value;
    if (*rtAng > 360.0f)
        *rtAng -= (float)360.0;
}

pos Localizer::getPos()
{
    //! differential driving localizer]
    pos actualLeft, actualRight;
    actualLeft.y = ENCODERS_ARRAY[0].read() - _lastPosition[0]; //! y scale relative to the robot.
    actualRight.y = ENCODERS_ARRAY[1].read() - _lastPosition[1];
    if (actualLeft.y > 0 && actualRight.y > 0)
    {
        //! calculate based on angle and nrOfThciks (Encoders -> meter system)
        actualLeft.y = actualRight.y * sin(rotateAngle);
        actualLeft.x = actualRight.y * cos(rotateAngle);
    }
    else if (actualLeft.y > 0 && actualRight.y < 0)
    {
        //! rotate to left.
        float value = abs(actualLeft.y) + abs(actualRight.y);
        value *= FROM_ENCODER_THICKS_TO_CENTIMETERS;
        increaseRotateAngle(&rotateAngle, value);
    }
    else if (actualLeft.y < 0 && actualRight.y > 0)
    {
        //! rotate to right.
        float value = abs(actualLeft.y) + abs(actualRight.y);
        value *= FROM_ENCODER_THICKS_TO_CENTIMETERS;
        increaseRotateAngle(&rotateAngle, -value);
    }
    else if (actualLeft.y < 0 && actualRight.y < 0)
    {
        //! rmoves backwards
        actualLeft.y = actualRight.y * sin(360 - rotateAngle);
        actualLeft.x = actualRight.y * cos(360 - rotateAngle);
    }
    return actualLeft;
}

void Localizer::setInitPos(pos initPos)
{
    _initPos = initPos;
}

float Localizer::getDistance(pos actual)
{
    actual = getPos(); // update the position
    return sqrt((_initPos.x - actual.x) ^ 2 + (_initPos.y - actual.y) ^ 2);
}