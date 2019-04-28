#include <iostream>
#include <wiringPi.h>
#include "HCSR04_array.h"



using namespace std;


int main()
{
    if (wiringPiSetup() == -1)
        return -1;

    HCSR04_array sonar_array;


    while(1){
        sonar_array.print_data();
    }
}
