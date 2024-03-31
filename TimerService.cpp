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

        void setYuild(void (*fn)(void)) {
            yieldFunc = fn; 
        }

        void setLogger(void (*fn)(const char[])) {
            logger = fn; 
            log("Logger initiated");
        }

        void run(unsigned long currentMillis) {
            log("Run the cycle");
            for (int i = 0; i < nextTimerToSetup; i ++) {
                char str[20]; 
                sprintf(str, "Running %d timer", i);
                log(str);
                if (currentMillis - previousMillis[i] >= timerIntervals[i]) {
                    previousMillis[i] = currentMillis;
                    
                    callbacks[i](); 
                }
                log("Yielding...");
                doYield();
            }
        }
    
    private: 
        int nextTimerToSetup;
        int timerIntervals[10];
        unsigned long previousMillis[10];
        ArrayOfCallbacks callbacks[10];
        void (*yieldFunc)(void);
        void (*logger)(const char[]);

        void doYield(){
            if (yieldFunc == NULL) return; 
            yieldFunc(); 
        }

        void log(const char s[]) {
            if (logger == NULL) return; 
            logger(s);
        }

};