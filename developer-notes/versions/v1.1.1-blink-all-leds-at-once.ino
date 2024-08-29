const int LED_R1 = 2;
const int LED_R2 = 3;
const int LED_R3 = 4;
const int LED_R4 = 5;
const int LED_R5 = 6;

const int LED_L1 = 8;
const int LED_L2 = 9;
const int LED_L3 = 10;
const int LED_L4 = 11;
const int LED_L5 = 12;

const int R_BUTTON = 1;
const int L_BUTTON = 0;
const int H_BUTTON = 7;

int R_BUTTON_STATE = 0;
int L_BUTTON_STATE = 0;
int H_BUTTON_STATE = 0;

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

void rightIndicator() {
  for (long i = 0; i < 3; i++) {

    digitalWrite(LED_R1, HIGH);
    digitalWrite(LED_R2, HIGH);
    digitalWrite(LED_R3, HIGH);
    digitalWrite(LED_R4, HIGH);
    digitalWrite(LED_R5, HIGH);
    
    delay(300);

    digitalWrite(LED_R1, LOW);
    digitalWrite(LED_R2, LOW);
    digitalWrite(LED_R3, LOW);
    digitalWrite(LED_R4, LOW);
    digitalWrite(LED_R5, LOW);

    delay(300);
  }  
}

void leftIndicator() {
  for(long i = 0; i < 3; i++) {

    digitalWrite(LED_L1, HIGH);
    digitalWrite(LED_L2, HIGH);
    digitalWrite(LED_L3, HIGH);
    digitalWrite(LED_L4, HIGH);
    digitalWrite(LED_L5, HIGH);
    
    delay(300);

    digitalWrite(LED_L1, LOW);
    digitalWrite(LED_L2, LOW);
    digitalWrite(LED_L3, LOW);
    digitalWrite(LED_L4, LOW);
    digitalWrite(LED_L5, LOW);
    
    delay(300);
  }
}

void hazardLights() {
  // Loop with a large number of iterations to simulate an infinite loop
  for (long i = 0; i < 3; i++) {
    
    // Blink all LEDs
    digitalWrite(LED_R1, HIGH);
    digitalWrite(LED_R2, HIGH);
    digitalWrite(LED_R3, HIGH);
    digitalWrite(LED_R4, HIGH);
    digitalWrite(LED_R5, HIGH);
    
    digitalWrite(LED_L1, HIGH);
    digitalWrite(LED_L2, HIGH);
    digitalWrite(LED_L3, HIGH);
    digitalWrite(LED_L4, HIGH);
    digitalWrite(LED_L5, HIGH);
    
    delay(300);

    digitalWrite(LED_R1, LOW);
    digitalWrite(LED_R2, LOW);
    digitalWrite(LED_R3, LOW);
    digitalWrite(LED_R4, LOW);
    digitalWrite(LED_R5, LOW);
    
    digitalWrite(LED_L1, LOW);
    digitalWrite(LED_L2, LOW);
    digitalWrite(LED_L3, LOW);
    digitalWrite(LED_L4, LOW);
    digitalWrite(LED_L5, LOW);
    
    delay(300);
  }

  // Turn off all LEDs when exiting the loop
  digitalWrite(LED_R1, LOW);
  digitalWrite(LED_R2, LOW);
  digitalWrite(LED_R3, LOW);
  digitalWrite(LED_R4, LOW);
  digitalWrite(LED_R5, LOW);
  
  digitalWrite(LED_L1, LOW);
  digitalWrite(LED_L2, LOW);
  digitalWrite(LED_L3, LOW);
  digitalWrite(LED_L4, LOW);
  digitalWrite(LED_L5, LOW);
}

void loop() {
  R_BUTTON_STATE = digitalRead(R_BUTTON);
  L_BUTTON_STATE = digitalRead(L_BUTTON);
  H_BUTTON_STATE = digitalRead(H_BUTTON);

  if (R_BUTTON_STATE == HIGH)
  {
    rightIndicator();
  }
  if(L_BUTTON_STATE == HIGH)
  {
    leftIndicator();
  }
  if (H_BUTTON_STATE == HIGH)
  {
    hazardLights();
  }
  
  delay(1);
}
