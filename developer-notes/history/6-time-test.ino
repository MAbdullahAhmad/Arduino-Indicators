bool led_status = false;
bool button_status = false;

int last_updated = 0; // time storage

void setup(){
    pinMode(7, INPUT);
    pinMode(12, OUTPUT);
}


void loop(){
    
    button_status = digitalRead(7);

    if(button_status){
        if(millis() - last_updated > 1000){ // comparison algo
            led_status = ! led_status; // logic
            last_updated = millis(); // updation algo
        }
    }
    
    else {
        led_status = false;
    }

    digitalWrite(12, led_status ? HIGH : LOW);
    
}