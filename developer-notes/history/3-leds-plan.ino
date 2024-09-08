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