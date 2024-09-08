// This program is used for indicators in automoblies

//
// Pin numbers
//

// Right led pins
#define R_LED_1 7
#define R_LED_2 8
#define R_LED_3 9
#define R_LED_4 10
#define R_LED_5 11

// Left led pins    
#define L_LED_1 6
#define L_LED_2 5
#define L_LED_3 4
#define L_LED_4 3
#define L_LED_5 2

#define P_LED 12

#define SEV_SEG_A A5
#define SEV_SEG_B A5
#define SEV_SEG_F A5

#define SEV_SEG_C A4
#define SEV_SEG_D A4
#define SEV_SEG_E A4

// Button pins
#define P_BUTTON A0 // Power button
#define R_BUTTON A3 // Right indicator button
#define L_BUTTON A1 // Left indicator button
#define H_BUTTON A2 // Hazard lights button

//
// Variables
//

// Right Indicator
bool right_led_state = false;
bool right_button_last_state = LOW;

// Left Indicator
bool left_led_state = false;
bool left_button_last_state = LOW;

// Hazard Button
bool hazard_led_state = false;
bool hazard_button_last_state = LOW;

// Power Button
bool system_on = false;
int power_button_last_state = LOW;
long power_button_hold_time = 0;
bool power_button_held = false;
bool led_power_blink = false;

// millis
long last_millis_right = 0;
long last_millis_left = 0;

// Interval
long interval = 50;

// current steps 
int right_step = 0;
int left_step = 0;

//
// Functions
//

void power_blink() {
    long start_time = millis();

    while(millis() - start_time < 2000)
    {
        digitalWrite(R_LED_1, HIGH);
        digitalWrite(R_LED_2, HIGH);
        digitalWrite(R_LED_3, HIGH);
        digitalWrite(R_LED_4, HIGH);
        digitalWrite(R_LED_5, HIGH);

        digitalWrite(L_LED_1, HIGH);
        digitalWrite(L_LED_2, HIGH);
        digitalWrite(L_LED_3, HIGH);
        digitalWrite(L_LED_4, HIGH);
        digitalWrite(L_LED_5, HIGH);

        digitalWrite(SEV_SEG_A, HIGH);
        digitalWrite(SEV_SEG_C, HIGH);

        delay(800);

        digitalWrite(R_LED_1, LOW);
        digitalWrite(R_LED_2, LOW);
        digitalWrite(R_LED_3, LOW);
        digitalWrite(R_LED_4, LOW);
        digitalWrite(R_LED_5, LOW); 

        digitalWrite(L_LED_1, LOW);
        digitalWrite(L_LED_2, LOW);
        digitalWrite(L_LED_3, LOW);
        digitalWrite(L_LED_4, LOW);
        digitalWrite(L_LED_5, LOW);

        digitalWrite(SEV_SEG_A, LOW);
        digitalWrite(SEV_SEG_C, LOW);

        delay(800);
    }
}


// Right Indicator function
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

// Right Indicator off function
    void right_indicator_off() {
        digitalWrite(R_LED_1, LOW);
        digitalWrite(R_LED_2, LOW);
        digitalWrite(R_LED_3, LOW);
        digitalWrite(R_LED_4, LOW);
        digitalWrite(R_LED_5, LOW);
    }

// Left Indicator function
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

// Ledt Indicator off function
    void left_indicator_off() {
        digitalWrite(L_LED_1, LOW);
        digitalWrite(L_LED_2, LOW);
        digitalWrite(L_LED_3, LOW);
        digitalWrite(L_LED_4, LOW);
        digitalWrite(L_LED_5, LOW);
    }

// Setup function
    void setup() {
        
        // Serial Monitor
        Serial.begin(9600);

        // pinMode right led's
        pinMode(R_LED_1, OUTPUT);
        pinMode(R_LED_2, OUTPUT);
        pinMode(R_LED_3, OUTPUT);
        pinMode(R_LED_4, OUTPUT);
        pinMode(R_LED_5, OUTPUT);
        
        // pinMode left led's
        pinMode(L_LED_1, OUTPUT);
        pinMode(L_LED_2, OUTPUT);
        pinMode(L_LED_3, OUTPUT);
        pinMode(L_LED_4, OUTPUT);
        pinMode(L_LED_5, OUTPUT);

        // pinMode buttons
        pinMode(R_BUTTON, INPUT);
        pinMode(L_BUTTON, INPUT);
        pinMode(H_BUTTON, INPUT);
    }

// Loop Function
    void loop() 
    {
        // Reading button states
        int power_button_state = digitalRead(P_BUTTON);
        int right_button_state = digitalRead(R_BUTTON);
        int left_button_state = digitalRead(L_BUTTON);
        int hazard_button_state = digitalRead(H_BUTTON);

        // Printing button state on serial monitor
        Serial.print("Power Button: ");  Serial.println(power_button_state);
        Serial.print("Right Button: ");  Serial.println(right_button_state);  
        Serial.print("Left Button: ");  Serial.println(left_button_state);
        Serial.print("Hazard Button: "); Serial.println(hazard_button_state);

        if(power_button_state == HIGH && power_button_last_state == LOW)
        {
            power_button_hold_time = millis();
            power_button_held = true;
        }

        if(power_button_state == LOW && power_button_held && (millis() - power_button_hold_time < 2000))
        {
            system_on = !system_on;
            power_button_held = false;
            led_power_blink = true;
            digitalWrite(P_LED, HIGH);
        }
        if(power_button_last_state == HIGH && power_button_held && (millis() - power_button_hold_time > 2000))
        {
            system_on = false;
            power_button_held = false;
            digitalWrite(P_LED, LOW);
        }
        power_button_last_state = power_button_state;

        if(system_on)
        {
            if(led_power_blink)
            {
                power_blink();
            }
            led_power_blink = false;
            
        // if right button pressed
        if(right_button_state == HIGH && right_button_last_state == LOW)
        {
            right_led_state = !right_led_state;
            left_led_state = false;
            hazard_led_state = false;
            delay(50);
        }
        right_button_last_state = right_button_state;

        // if left button pressed
        if(left_button_state == HIGH && left_button_last_state == LOW)
        {
            left_led_state = !left_led_state;
            right_led_state = false;
            hazard_led_state = false;
            delay(50);
        }
        left_button_last_state = left_button_state;

        // if hazard button pressed
        if(hazard_button_state == HIGH && hazard_button_last_state == LOW)
        {
            hazard_led_state = !hazard_led_state;
            left_led_state = false;
            right_led_state = false;
            delay(50);
        }
        hazard_button_last_state = hazard_button_state;

        // Right Indicator
        if(right_led_state) {
            right_indicator();
        }
        else {
            right_indicator_off();
        }

        // Left Indicator
        if(left_led_state) {
            left_indicator();
        }
        else {
            left_indicator_off();
        }

        // Hazard Lights
        if (hazard_led_state)
        {
            right_indicator();
            left_indicator();
        }
        else {
            right_indicator_off();
            left_indicator_off();
        }
        }

    }