# Easy lib to keep several actions to run by timings

# Usage

```
// this callback will be run
void callback(void) {
    printf("callback called!");
}

TimerService timer;


void setup(){    
    int timerId = timer.initTimer(1000, callback); // 1000 milliseconds period = 1 second
    timer.runTimerImmediately(timerId); // method to run timer immediately, e.g. on external event
}
```
