#include <cstdio>
//compile: clang main.cpp

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

    void changeInterval(int timerId, int interval) {
        timerIntervals[timerId] = interval;
    }

    void run(unsigned long currentMillis) {

        for (int i = 0; i < nextTimerToSetup; i ++) {
            if (currentMillis - previousMillis[i] >= timerIntervals[i]) {
                previousMillis[i] = currentMillis;
                
                callbacks[i](); 
            }
        }
    }
    
    private: 
        int nextTimerToSetup;
        int timerIntervals[10];
        unsigned long previousMillis[10];
        ArrayOfCallbacks callbacks[10];
};

// void callback(void) {
//     printf("callback called!");
// }

// int main(){
//     // printf("hi!\n");
//     // TimerService timer;
//     // char str[10];
//     // sprintf(str, "%d", timer.value);
//     // printf(str);
//     int timerId = timer.initTimer(1000, callback);
//     timer.runTimerImmediately(timerId);
//     // TimerService timer;
//     // std::cout << timer.value; 
    
//     return 0; 
// }


