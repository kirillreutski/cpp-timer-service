#include <iostream>
class TimerService {
    public: 
    TimerService() {
       
    }
    int value = 0; 
};

int main(){
    TimerService timer = TimerService(5);  
    std::cout << timer.value; 
}