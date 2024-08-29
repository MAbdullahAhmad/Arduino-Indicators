
void setup(){
    // Right LEDS
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);

    // Left LEDS
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
}

void loop(){
    for(int pin_no=2; pin_no<=12; pin_no++){
        digitalWrite(pin_no, HIGH);
        delay(500);
        digitalWrite(pin_no, LOW);
        delay(500);
    }
}