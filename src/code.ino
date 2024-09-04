// This program is used for indicators in automoblies

//
// Pin numbers
//

// Right led pins
#define R_LED_1 6
#define R_LED_2 7
#define R_LED_3 8
#define R_LED_4 9
#define R_LED_5 10

// Left led pins    
#define L_LED_1 5
#define L_LED_2 4
#define L_LED_3 3
#define L_LED_4 2
#define L_LED_5 1

// Button pins
#define R_BUTTON 11 // Right indicator button
#define L_BUTTON 13 // Left indicator button
#define H_BUTTON 12 // Hazard lights button

//
// Variable
//

// Right Indicator
bool right_led_state = false; // right led state initially set to 'false'
bool right_button_last_state = LOW; // right button last state initially set to 'LOW'

// Left Indicator
bool left_led_state = false; // left led state initially set to 'false'
bool left_button_last_state = LOW; // left button last state initially set to 'LOW'

// millis
long last_millis_right = 0; // last millis value for right indicator initially set to '0'
long last_millis_left = 0; // last millis value for left indicator initially set to '0'

// Interval
long interval = 35; // interval is set to '35'

// current steps 
int right_step = 0; // right step initially set to '0'
int left_step = 0; // left step initially set to '0'

    

    void right_indicator() {
        long current_millis = millis();

        if(current_millis - last_millis_right >= interval)
        {
            last_millis_right = current_millis;

            right_indicator_off();

            if (right_step == 0)
            {
                digitalWrite(R_LED_1, HIGH);
            }
            else if (right_step == 1) 
            {
                digitalWrite(R_LED_2, HIGH);
            }
            else if(right_step == 2)
            {
                digitalWrite(R_LED_3, HIGH);
            }
            else if(right_step == 3)
            {
                digitalWrite(R_LED_4, HIGH);
            }
            else if(right_step == 4)
            {
                digitalWrite(R_LED_5, HIGH);
            }

            right_step++;
            if (right_step > 4)
            {
                right_step = 0;
            }
        }
    }

    void right_indicator_off() {
        digitalWrite(R_LED_1, LOW);
        digitalWrite(R_LED_2, LOW);
        digitalWrite(R_LED_3, LOW);
        digitalWrite(R_LED_4, LOW);
        digitalWrite(R_LED_5, LOW);
    }

    void left_indicator() {
        long current_millis = millis();

        if(current_millis - last_millis_left >= interval)
        {
            last_millis_left = current_millis;

            left_indicator_off();

            if (left_step == 0)
            {
                digitalWrite(L_LED_1, HIGH);
            }
            else if (left_step == 1) 
            {
                digitalWrite(L_LED_2, HIGH);
            }
            else if(left_step == 2)
            {
                digitalWrite(L_LED_3, HIGH);
            }
            else if(left_step == 3)
            {
                digitalWrite(L_LED_4, HIGH);
            }
            else if(left_step == 4)
            {
                digitalWrite(L_LED_5, HIGH);
            }

            left_step++;

            if(left_step > 4) 
            {
                left_step = 0;
            }
        }
    }

    void left_indicator_off() {
        digitalWrite(L_LED_1, LOW);
        digitalWrite(L_LED_2, LOW);
        digitalWrite(L_LED_3, LOW);
        digitalWrite(L_LED_4, LOW);
        digitalWrite(L_LED_5, LOW);
    }

    void setup() {
        
        Serial.begin(9600);

        pinMode(R_LED_1, OUTPUT);
        pinMode(R_LED_2, OUTPUT);
        pinMode(R_LED_3, OUTPUT);
        pinMode(R_LED_4, OUTPUT);
        pinMode(R_LED_5, OUTPUT);

        pinMode(L_LED_1, OUTPUT);
        pinMode(L_LED_2, OUTPUT);
        pinMode(L_LED_3, OUTPUT);
        pinMode(L_LED_4, OUTPUT);
        pinMode(L_LED_5, OUTPUT);

        pinMode(R_BUTTON, INPUT);
        pinMode(L_BUTTON, INPUT);
        pinMode(P_BUTTON, INPUT);
    }

    void loop() {
        int right_button_state = digitalRead(R_BUTTON);
        int left_button_state = digitalRead(L_BUTTON);

        Serial.print("R_BUTTON: ");  Serial.println(right_button_state);  
        Serial.print("L_BUTTON: ");  Serial.println(left_button_state);

        if(right_button_state == HIGH && right_button_last_state == LOW)
        {
            right_led_state = !right_led_state;
            delay(50);
        }
        right_button_last_state = right_button_state;

        if(left_button_state == HIGH && left_button_last_state == LOW)
        {
            left_led_state = !left_led_state;
            delay(50);
        }
        left_button_last_state = left_button_state;

        if(right_led_state) {
            right_indicator();
        }
        else {
            right_indicator_off();
        }

        if(left_led_state) {
            left_indicator();
        }
        else {
            left_indicator_off();
        }
    }