#include "Encoder.hpp"

Localizer::Localizer(Encoder **encoderArray, , int nrOfEncoders, char EncoderConfig)
    : encArray(encoderArray), nrEncs(nrOfEncoders) {}

pos Localizer::getPos()
{
}

void Localizer::setInitPos(pos initPos)
{
    _initPos = initPos;
}

float Localizer::getDistance(pos actual)
{
    return sqrt((_initPos.x - actual.x) ^ 2 + (_initPos.y - actual.y) ^ 2);
}

/**
 * TODO:
 *
 * ! Rename PID library into constants
 * ! Add wheel measurements, encoder config file with nr of encoders,
 * ! configuration, the distance between one another + measurements  of robot.alignas
 * ! Pass that object or struct to Localizer constructor and create
 * ! a switch statement in getPos() in which The position will be calculated
 * ! based on the specific encoder/s configuration of the robot.
 *
 * -  -
 *   |
 * -  -   -  -
 *    |   |
 *
 * -  | etc..
 *
 */