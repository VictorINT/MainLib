#include "Driver.hpp"

Driver::Driver(Encoder &enc, DCMotor &dc)
    : enc(enc), dc(dc)
{
    enc.init();
    dc.init();
}

virtual void Driver::goFront(int speed, int distance)
{
    enc.reset();
    int nrthicks = round((float)((distance * 119) / 19.154) * KP);
    while (enc.read() < nrthicks)
    {
        dc.moveForward(speed);
        enc.update();
        Serial.println(enc.read());
    }
}

virtual void Driver::goBack(int speed, int distance)
{
    enc.reset();
    int nrthicks = round((float)((distance * 119) / 19.154) * KP);
    while (enc.read() < nrthicks)
    {
        dc.moveBackward(speed);
        enc.update();
        Serial.println(enc.read());
    }
}

void Driver::stop()
{
    dc.halt();
}