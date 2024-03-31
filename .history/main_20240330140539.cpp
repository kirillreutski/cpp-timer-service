#include <iostream>
class TimerService {
    public: 
    TimerService(int v) {
        value = v; 
    }
    int value = 0; 
};

int main(){
    TimerService timer();  
    std::cout << timer.value; 
}