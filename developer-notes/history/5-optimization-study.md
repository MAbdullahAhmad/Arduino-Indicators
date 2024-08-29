# Optimization

- buttons are getting scanned every-time
- no matters leds are blinking or not

## Time / Delay

1. `sleep`: "halt".
2. 

## Time Logic

```cpp

bool led_status = false;
bool button_status = false;

int last_updated = 0;


void loop(){
    
    button_status = digitalRead(7);

    if(button_status){
        if(millis() - last_updated > 1000){
            led_status = ! led_status;
            last_updated = millis();
        }
    }
    
    else {
        led_status = false;
    }

    digitalWrite(13, led_status);
    
}

I am studying
```