#include <iostream>
class TimerService {
    public: 
    TimerService() {

    }
    int value = 0; 
};

int main(){
    TimerService timer();  
    cout << timer.value; 
}