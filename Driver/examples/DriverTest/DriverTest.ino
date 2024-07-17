#include <Driver.hpp>
#include <DCMotor.hpp>
#include <Encoder.hpp>

Encoder encoderLeft(10, 11);
DCMotor motorLeft(3, 5);

void setup()
{
    Serial.begin(9600);
    Driver left(encoderLeft, motorLeft);
    left.goFront(150, 100);
    left.stop();
}

void loop()
{
    /** Nothing in here */
}
