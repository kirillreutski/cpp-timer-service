#include <cstdio>
class TimerService {
    public: 
    TimerService() {
       printf("Init\n");
       value = 0; 
    }
    int value;
};

int main(){
    printf("hi!");
    // TimerService timer;
    // std::cout << timer.value; 

    return 0; 
}