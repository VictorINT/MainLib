#include <Encoder.hpp>

Encoder encoder(2, 3);  // Pins for the encoder

void setup() {
    Serial.begin(9600);
    encoder.init();
}

void loop() {
    encoder.update();
    Serial.print("Encoder position: ");
    Serial.println(encoder.read());
    delay(100);
}

