```cpp

class Timer {
    // {...}


    public:
    
    auto callback;

    void exec(){
        
    }


};

// Time
left_timer = new Timer(1000); // seperate
right_timer = new Timer(1000); // seperate
hazard_timer = new Timer(500); // seperate

// Logic
void left_function(){
    led_status = ! led_status;
}

// Assign Logic
left_timer.callback = left_function;

void setup(){

}

void loop(){

    button_status = digitalRead(7);

    if(button_status){
        left_timer.exec();
    }
    
    else {
        led_status = false;
    }

    digitalWrite(12, led_status ? HIGH : LOW);
    
}

```