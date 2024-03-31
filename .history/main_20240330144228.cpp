#include <cstdio>


typedef void (*ArrayOfCallbacks) (void);

class TimerService {
    public: 
    TimerService() {}

    int initTimer(int interval, void (*fn)(void)){
        if (nextTimerToSetup >= 10) return -1; 
        timerIntervals[nextTimerToSetup] = interval;
        callbacks[nextTimerToSetup] = fn;
        nextTimerToSetup ++; 
    }

    void runTimerImmediately(int timerId) {

    }
    
    private: 
        int nextTimerToSetup = 0; 
        int timerIntervals[10];
        unsigned long previousMillis[10];
        ArrayOfCallbacks callbacks[10];
};

int main(){
    printf("hi!\n");
    TimerService timer;
    // char str[10];
    // sprintf(str, "%d", timer.value);
    // printf(str);
    timer.initTimer(1000, callback);
    // TimerService timer;
    // std::cout << timer.value; 

    return 0; 
}

void callback(void) {
    printf("callback called!");
}