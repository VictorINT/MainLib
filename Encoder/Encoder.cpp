#include "Encoder.hpp"

Encoder::Encoder(uint8_t pinA, uint8_t pinB)
    : _pinA(pinA), _pinB(pinB), _position(0), _lastA(LOW), _lastB(LOW) {}

void Encoder::init()
{
    pinMode(_pinA, INPUT);
    pinMode(_pinB, INPUT);
    _lastA = digitalRead(_pinA);
}

int Encoder::read()
{
    return _position;
}

void Encoder::update()
{
    bool currentA = digitalRead(_pinA);
    if (currentA != _lastA)
    {
        if (digitalRead(_pinB) != currentA)
        {
            _position++;
        }
        else
        {
            _position--;
        }
    }
    _lastA = currentA;
}