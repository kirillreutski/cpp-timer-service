#include <cstdio>


typedef void (*ArrayOfCallbacks) (void);

class TimerService {
    public: 
    TimerService() {
        nextTimerToSetup = 0; 
    }

    int initTimer(int interval, void (*fn)(void)){
        if (nextTimerToSetup >= 10) return -1; 
        timerIntervals[nextTimerToSetup] = interval;
        callbacks[nextTimerToSetup] = fn;
        int returnValue = nextTimerToSetup; 
        nextTimerToSetup ++; 
        return returnValue;
    }

    void runTimerImmediately(int timerId) {
        callbacks[timerId](); 
    }

    void run() {
        
    }
    
    private: 
        int nextTimerToSetup;
        int timerIntervals[10];
        unsigned long previousMillis[10];
        ArrayOfCallbacks callbacks[10];
};
TimerService timer; 

void callback(void) {
    printf("callback called!");
}

int main(){
    // printf("hi!\n");
    // TimerService timer;
    // char str[10];
    // sprintf(str, "%d", timer.value);
    // printf(str);
    int timerId = timer.initTimer(1000, callback);
    timer.runTimerImmediately(timerId);
    // TimerService timer;
    // std::cout << timer.value; 

    return 0; 
}


