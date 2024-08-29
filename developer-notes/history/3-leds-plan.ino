#define LED_R1 2
#define LED_R2 3
#define LED_R3 4
#define LED_R4 5
#define LED_R5 6

#define LED_L1 8
#define LED_L2 9
#define LED_L3 10
#define LED_L4 11
#define LED_L5 12

#define BUTTON_LEFT 0
#define BUTTON_RIGHT 1
#define BUTTON_HAZARD 7

void setup(){
    // Right LEDS
    pinMode(LED_R1, OUTPUT);
    pinMode(LED_R2, OUTPUT);
    pinMode(LED_R3, OUTPUT);
    pinMode(LED_R4, OUTPUT);
    pinMode(LED_R5, OUTPUT);

    // Left LEDS
    pinMode(LED_L1, OUTPUT);
    pinMode(LED_L2, OUTPUT);
    pinMode(LED_L3, OUTPUT);
    pinMode(LED_L4, OUTPUT);
    pinMode(LED_L5, OUTPUT);

    // Left LEDS
    pinMode(BUTTON_LEFT,   INPUT_PULLUP);
    pinMode(BUTTON_RIGHT,  INPUT_PULLUP);
    pinMode(BUTTON_HAZARD, INPUT_PULLUP);
}

// void blink_leds(){
//     digitalWrite(LED_R1, HIGH);
//     digitalWrite(LED_R2, HIGH);
//     digitalWrite(LED_R3, HIGH);
//     digitalWrite(LED_R4, HIGH);
//     digitalWrite(LED_R5, HIGH);
//     digitalWrite(LED_L1, HIGH);
//     digitalWrite(LED_L2, HIGH);
//     digitalWrite(LED_L3, HIGH);
//     digitalWrite(LED_L4, HIGH);
//     digitalWrite(LED_L5, HIGH);
//     delay(1000);

//     digitalWrite(LED_R1, LOW);
//     digitalWrite(LED_R2, LOW);
//     digitalWrite(LED_R3, LOW);
//     digitalWrite(LED_R4, LOW);
//     digitalWrite(LED_R5, LOW);
//     digitalWrite(LED_L1, LOW);
//     digitalWrite(LED_L2, LOW);
//     digitalWrite(LED_L3, LOW);
//     digitalWrite(LED_L4, LOW);
//     digitalWrite(LED_L5, LOW);
//     delay(1000);
// }

void loop(){
    if(digitalRead(BUTTON_LEFT)){
        left_leds_transition();
    }
    if(digitalRead(BUTTON_RIGHT)){
        right_leds_transition();
    }
    if(digitalRead(BUTTON_HAZARD)){
        hazard_leds_transition();
    }
    delay(1);
}