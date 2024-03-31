#include <cstdio>
class TimerService {
    public: 
    TimerService() {
       printf("Init\n");
       value = 0; 
    }

    int initTimer(int interval, void (*fn)(void)){
        if (nextTimerToSetup >= 10) return -1; 

        
    }
    int value;

    private: 
        int nextTimerToSetup = 0; 
        int timerIntervals[10];
        unsigned long previousMillis[10];
};

int main(){
    printf("hi!\n");
    TimerService timer;
    char str[10];
    sprintf(str, "%d", timer.value);
    printf(str);
    // TimerService timer;
    // std::cout << timer.value; 

    return 0; 
}