#include <iostream>
class TimerService {
    public: 
    TimerService() {
       std::cout << "construct";
    }
    int value = 0; 
};

int main(){
    TimerService timer;
    std::cout << timer.value; 
}