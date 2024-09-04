// 
// Pin Numbers
// 

// Right LEDs
#define R_LED_1 6
#define R_LED_2 7
#define R_LED_3 8
#define R_LED_4 9
#define R_LED_5 10

// Left LEDs
#define L_LED_1 5
#define L_LED_2 4
#define L_LED_3 3
#define L_LED_4 2
#define L_LED_5 11

// Buttons
#define R_BUTTON A1
#define L_BUTTON A3
#define P_BUTTON A2


// 
// Variables
// 

bool right_indicator_state = false;
bool right_button_previous_state = LOW;

bool left_indicator_state = false;
bool left_button_previous_state = LOW;

long previous_millis_right = 0;
long previous_millis_left = 0;

long interval = 35;

int step_right = 0;
int step_left = 0;


// 
// Helper Functions
// 

// Animate Right LEDs
void animate_right() {
    long current_millis = millis();

    if(current_millis - previous_millis_right >= interval)
    {
        previous_millis_right = current_millis;

        off_right();

        if (step_right == 0)
        {
            digitalWrite(R_LED_1, HIGH);
        }
        else if (step_right == 1) 
        {
            digitalWrite(R_LED_2, HIGH);
        }
        else if(step_right == 2)
        {
            digitalWrite(R_LED_3, HIGH);
        }
        else if(step_right == 3)
        {
            digitalWrite(R_LED_4, HIGH);
        }
        else if(step_right == 4)
        {
            digitalWrite(R_LED_5, HIGH);
        }

        step_right++;
        if (step_right > 4)
        {
            step_right = 0;
        }
    }
}

// Turn Off Right LEDs
void off_right() {
    digitalWrite(R_LED_1, LOW);
    digitalWrite(R_LED_2, LOW);
    digitalWrite(R_LED_3, LOW);
    digitalWrite(R_LED_4, LOW);
    digitalWrite(R_LED_5, LOW);
}

// Animate Left LEDs
void animate_left() {
    long current_millis = millis();

    if(current_millis - previous_millis_left >= interval)
    {
        previous_millis_left = current_millis;

        off_left();

        if (step_left == 0)
        {
            digitalWrite(L_LED_1, HIGH);
        }
        else if (step_left == 1) 
        {
            digitalWrite(L_LED_2, HIGH);
        }
        else if(step_left == 2)
        {
            digitalWrite(L_LED_3, HIGH);
        }
        else if(step_left == 3)
        {
            digitalWrite(L_LED_4, HIGH);
        }
        else if(step_left == 4)
        {
            digitalWrite(L_LED_5, HIGH);
        }

        step_left++;

        if(step_left > 4) 
        {
            step_left = 0;
        }
    }
}

// Turn Off Left LEDs
void off_left() {
    digitalWrite(L_LED_1, LOW);
    digitalWrite(L_LED_2, LOW);
    digitalWrite(L_LED_3, LOW);
    digitalWrite(L_LED_4, LOW);
    digitalWrite(L_LED_5, LOW);
}


// 
// Setup Function
// 

void setup() {

    // Begin Serial
    Serial.begin(9600);

    // Mode: Right LEDs
    pinMode(R_LED_1, OUTPUT);
    pinMode(R_LED_2, OUTPUT);
    pinMode(R_LED_3, OUTPUT);
    pinMode(R_LED_4, OUTPUT);
    pinMode(R_LED_5, OUTPUT);

    // Mode: Left LEDs
    pinMode(L_LED_1, OUTPUT);
    pinMode(L_LED_2, OUTPUT);
    pinMode(L_LED_3, OUTPUT);
    pinMode(L_LED_4, OUTPUT);
    pinMode(L_LED_5, OUTPUT);

    // Mode: Buttons
    pinMode(R_BUTTON, INPUT);
    pinMode(L_BUTTON, INPUT);
    pinMode(P_BUTTON, INPUT);

}


// 
// Loop Function
// 

void loop() {

    // Read Button States
    int right_button_state = digitalRead(R_BUTTON);
    int left_button_state  = digitalRead(L_BUTTON);

    // Log Button States @debug
    Serial.print("R_BUTTON: "); Serial.println(right_button_state);
    Serial.print("L_BUTTON: "); Serial.println(left_button_state);

    // If Right Button Pressed
    if(right_button_state == HIGH && right_button_previous_state == LOW)
    {
        right_indicator_state = !right_indicator_state;
        delay(50);
    }
    right_button_previous_state = right_button_state;

    // If Left Button Pressed
    if(left_button_state == HIGH && left_button_previous_state == LOW)
    {
        left_indicator_state = !left_indicator_state;
        delay(50);
    }
    left_button_previous_state = left_button_state;

    // Animate / Off Right Indicator
    if(right_indicator_state) {
        animate_right();
    }
    else {
        off_right();
    }

    // Animate / Off Left Indicator
    if(left_indicator_state) {
        animate_left();
    }
    else {
        off_left();
    }

}
