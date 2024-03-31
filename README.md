# cpp-timer-service
Small library to keep several actions to run by timings for C/C++ microcontroller e.g. esp8266
# Usage

```
// this callback will be run each second
void callback(void) {
    printf("callback called!");
}

// this callback will be run each 5 seconds
void callback2(void) {
    printf("callback2 called!");
}

void yuildCallback(){
    yield(); 
}

void loggerCallback(const char[] c){
    Serial.println(c);
}

TimerService timer;


void setup(){    
    timer.setYield(yuildCallback);
    timer.setLogger(loggerCallback);
    int timer1Id = timer.initTimer(1000, callback); // 1000 milliseconds period = 1 second
    int timer2Id = timer.initTimer(5 * 1000, callback2); // 5 * 1000 milliseconds period = 5 seconds
    timer.runTimerImmediately(timer1Id); // method to run timer immediately, e.g. on external event
}

void loop(){
    //...
    unsigned long currentMillis = millis();// TimerService doesn't track current time to be more abstract, so we need to pass it
    timer.run(currentMillis); // run timer checks each loop
    //...
}
```
