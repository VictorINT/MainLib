#ifndef LOCALIZER_HPP
#define LOCALIZER_HPP

#include <Arduino.h>
#include <math.h>
#include <ROBOT.hpp>

sturct pos
{
    float x, y;
};

typedef struct pos pos;

class Localizer
{
public:
    Localizer();

    pos getPos();

    void setInitPos(pos initPos);

    float getDistance(pos actual);

private:
    int _lastPosition[NR_OF_ENCODERS];
    pos _initPos;
    float rotateAngle;
};

#endif
