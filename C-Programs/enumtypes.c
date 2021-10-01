#include <stdio.h>
int main(){
    enum Car {Ford, Tesla, Toyota, Tata, volks};
    enum Car ford = Ford;
    enum Car tata = Tata;
    enum Car teska = Tesla;
    printf("Value for ford is: %d\n",ford);
    printf("Value for tata is: %d\n",tata);
    printf("Value for tesla is: %d\n",teska);
    return 0;
}