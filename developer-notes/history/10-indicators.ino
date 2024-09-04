    const int R_LED_1 = 6;
    const int R_LED_2 = 7;
    const int R_LED_3 = 8;
    const int R_LED_4 = 9;
    const int R_LED_5 = 10;

    const int L_LED_1 = 5;
    const int L_LED_2 = 4;
    const int L_LED_3 = 3;
    const int L_LED_4 = 2;
    const int L_LED_5 = 1;

    const int R_BUTTON = 11;
    const int L_BUTTON = 13;
    const int P_BUTTON = 12;

    bool R_LED_STATE = false;
    bool R_BUTTON_P_STATE = LOW;

    bool L_LED_STATE = false;
    bool L_BUTTON_P_STATE = LOW;

    long P_MILLIS_R = 0;
    long P_MILLIS_L = 0;
    long interval = 35;
    int R_CURRENT_STEP = 0;
    int L_CURRENT_STEP = 0;

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

    void R_LED_TRANSITION() {
        long C_MILLIS_R = millis();

        if(C_MILLIS_R - P_MILLIS_R >= interval)
        {
            P_MILLIS_R = C_MILLIS_R;

            R_LED_OFF();

            if (R_CURRENT_STEP == 0)
            {
                digitalWrite(R_LED_1, HIGH);
            }
            else if (R_CURRENT_STEP == 1) 
            {
                digitalWrite(R_LED_2, HIGH);
            }
            else if(R_CURRENT_STEP == 2)
            {
                digitalWrite(R_LED_3, HIGH);
            }
            else if(R_CURRENT_STEP == 3)
            {
                digitalWrite(R_LED_4, HIGH);
            }
            else if(R_CURRENT_STEP == 4)
            {
                digitalWrite(R_LED_5, HIGH);
            }

            R_CURRENT_STEP++;
            if (R_CURRENT_STEP > 4)
            {
                R_CURRENT_STEP = 0;
            }
        }
    }

    void R_LED_OFF() {
        digitalWrite(R_LED_1, LOW);
        digitalWrite(R_LED_2, LOW);
        digitalWrite(R_LED_3, LOW);
        digitalWrite(R_LED_4, LOW);
        digitalWrite(R_LED_5, LOW);
    }

    void L_LED_TRANSITION() {
        long C_MILLIS_L = millis();

        if(C_MILLIS_L - P_MILLIS_L >= interval)
        {
            P_MILLIS_L = C_MILLIS_L;

            L_LED_OFF();

            if (L_CURRENT_STEP == 0)
            {
                digitalWrite(L_LED_1, HIGH);
            }
            else if (L_CURRENT_STEP == 1) 
            {
                digitalWrite(L_LED_2, HIGH);
            }
            else if(L_CURRENT_STEP == 2)
            {
                digitalWrite(L_LED_3, HIGH);
            }
            else if(L_CURRENT_STEP == 3)
            {
                digitalWrite(L_LED_4, HIGH);
            }
            else if(L_CURRENT_STEP == 4)
            {
                digitalWrite(L_LED_5, HIGH);
            }

            L_CURRENT_STEP++;

            if(L_CURRENT_STEP > 4) 
            {
                L_CURRENT_STEP = 0;
            }
        }
    }

    void L_LED_OFF() {
        digitalWrite(L_LED_1, LOW);
        digitalWrite(L_LED_2, LOW);
        digitalWrite(L_LED_3, LOW);
        digitalWrite(L_LED_4, LOW);
        digitalWrite(L_LED_5, LOW);
    }

    void loop() {
        int R_BUTTON_STATE = digitalRead(R_BUTTON);
        int L_BUTTON_STATE = digitalRead(L_BUTTON);

        Serial.print("R_BUTTON: ");
        Serial.println(R_BUTTON_STATE);
        Serial.print("L_BUTTON: ");
        Serial.println(L_BUTTON_STATE);

        if(R_BUTTON_STATE == HIGH && R_BUTTON_P_STATE == LOW)
        {
            R_LED_STATE = !R_LED_STATE;
            delay(50);
        }
        R_BUTTON_P_STATE = R_BUTTON_STATE;

        if(L_BUTTON_STATE == HIGH && L_BUTTON_P_STATE == LOW)
        {
            L_LED_STATE = !L_LED_STATE;
            delay(50);
        }
        L_BUTTON_P_STATE = L_BUTTON_STATE;

        if(R_LED_STATE) {
            R_LED_TRANSITION();
        }
        else {
            R_LED_OFF();
        }

        if(L_LED_STATE) {
            L_LED_TRANSITION();
        }
        else {
            L_LED_OFF();
        }
    }