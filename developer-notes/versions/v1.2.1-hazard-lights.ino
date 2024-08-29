/**
 * Pins
 */

// Right LEDs
const int LED_R1 = 6;
const int LED_R2 = 5;
const int LED_R3 = 4;
const int LED_R4 = 3;
const int LED_R5 = 2;

// Left LEDs
const int LED_L1 = 8;
const int LED_L2 = 9;
const int LED_L3 = 10;
const int LED_L4 = 11;
const int LED_L5 = 12;

// Buttons
const int R_BUTTON = 1;
const int L_BUTTON = 0;
const int H_BUTTON = 7;

/**
 * States
 */

int R_BUTTON_STATE = 0;
int L_BUTTON_STATE = 0;
int H_BUTTON_STATE = 0;


/**
 * Setup
 */

void setup() {
  pinMode(LED_R1, OUTPUT);
  pinMode(LED_R2, OUTPUT);
  pinMode(LED_R3, OUTPUT);
  pinMode(LED_R4, OUTPUT);
  pinMode(LED_R5, OUTPUT);

  pinMode(LED_L1, OUTPUT);
  pinMode(LED_L2, OUTPUT);
  pinMode(LED_L3, OUTPUT);
  pinMode(LED_L4, OUTPUT);
  pinMode(LED_L5, OUTPUT);

  pinMode(R_BUTTON, OUTPUT);
  pinMode(L_BUTTON, OUTPUT);
  pinMode(H_BUTTON, OUTPUT);
}

/**
 * Helpers
 */

void rightIndicator() {
  for (long i = 0; i < 3; i++) {

    digitalWrite(LED_R1, HIGH); delay(100);
    digitalWrite(LED_R2, HIGH); delay(100);
    digitalWrite(LED_R3, HIGH); delay(100);
    digitalWrite(LED_R4, HIGH); delay(100);
    digitalWrite(LED_R5, HIGH);
    
    delay(300);

    digitalWrite(LED_R1, LOW); delay(100);
    digitalWrite(LED_R2, LOW); delay(100);
    digitalWrite(LED_R3, LOW); delay(100);
    digitalWrite(LED_R4, LOW); delay(100);
    digitalWrite(LED_R5, LOW);

    delay(300);
  }  
}

void leftIndicator() {
  for(long i = 0; i < 3; i++) {

    digitalWrite(LED_L1, HIGH); delay(100);
    digitalWrite(LED_L2, HIGH); delay(100);
    digitalWrite(LED_L3, HIGH); delay(100);
    digitalWrite(LED_L4, HIGH); delay(100);
    digitalWrite(LED_L5, HIGH);
    
    delay(300);

    digitalWrite(LED_L1, LOW); delay(100);
    digitalWrite(LED_L2, LOW); delay(100);
    digitalWrite(LED_L3, LOW); delay(100);
    digitalWrite(LED_L4, LOW); delay(100);
    digitalWrite(LED_L5, LOW);
    
    delay(300);
  }
}

void hazardLights() {
  // Loop with a large number of iterations to simulate an infinite loop
  for (long i = 0; i < 3; i++) {
    
    // Blink all LEDs
    digitalWrite(LED_R1, HIGH); digitalWrite(LED_L1, HIGH); delay(100);
    digitalWrite(LED_R2, HIGH); digitalWrite(LED_L2, HIGH); delay(100);
    digitalWrite(LED_R3, HIGH); digitalWrite(LED_L3, HIGH); delay(100);
    digitalWrite(LED_R4, HIGH); digitalWrite(LED_L4, HIGH); delay(100);
    digitalWrite(LED_R5, HIGH); digitalWrite(LED_L5, HIGH);
    
    delay(300);

    digitalWrite(LED_R1, LOW); digitalWrite(LED_L1, LOW); delay(100);
    digitalWrite(LED_R2, LOW); digitalWrite(LED_L2, LOW); delay(100);
    digitalWrite(LED_R3, LOW); digitalWrite(LED_L3, LOW); delay(100);
    digitalWrite(LED_R4, LOW); digitalWrite(LED_L4, LOW); delay(100);
    digitalWrite(LED_R5, LOW); digitalWrite(LED_L5, LOW);
    
    delay(300);
  }

}

/**
 * Loop
 */

void loop() {

  // Readt Button States
  R_BUTTON_STATE = digitalRead(R_BUTTON);
  L_BUTTON_STATE = digitalRead(L_BUTTON);
  H_BUTTON_STATE = digitalRead(H_BUTTON);

  // If Right Button Presssed
  if (R_BUTTON_STATE == HIGH)
  {
    rightIndicator();
  }

  // If Left Button Presssed
  if(L_BUTTON_STATE == HIGH)
  {
    leftIndicator();
  }

  // If Hazard Button Presssed
  if (H_BUTTON_STATE == HIGH)
  {
    hazardLights();
  }
  
  delay(1);
}
