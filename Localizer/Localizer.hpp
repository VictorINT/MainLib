#ifndef LOCALIZER_HPP
#define LOCALIZER_HPP

#include <Arduino.h>

sturct pos
{
    float x, y;
};

typedef struct pos pos;

class Localizer
{
public:
    Localizer(Encoder **encoderArray, int nrOfEncoders, char EncoderConfig); // passing the pointer to array of Encoder objects.

    pos getPos();

    void setInitPos(pos initPos);

    float getDistance(pos actual);

private:
    Encoder **encArray;
    int nrEncs;
    pos _initPos;
};

#endif
