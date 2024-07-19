#include <DoubleDriver.hpp>

Encoder encoderLeft(10, 11);
DCMotor motorLeft(3, 5);

Encoder encoderRight(8, 9);
DCMotor motorRight(6, 9);

void setup()
{
    Serial.begin(9600);
    DoubleDriver dd(encoderLeft, motorLeft, encoderRight, motorRight);
    dd.goFront(150, 100);
    dd.stop();
}

void loop()
{
    /** Nothing in here */
}
