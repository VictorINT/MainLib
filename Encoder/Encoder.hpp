#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <Arduino.h>

class Encoder
{
public:
    Encoder(uint8_t pinA, uint8_t pinB);

    void init();
    int read();
    void update();
    void reset();

private:
    uint8_t _pinA, _pinB;
    int _position;
    bool _lastA;
};

#endif
