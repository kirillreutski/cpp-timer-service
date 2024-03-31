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
    TimerService timer;
    char str[10];
    sprintf(str, "%d", timer.value);
    printf(str);
    // TimerService timer;
    // std::cout << timer.value; 

    return 0; 
}