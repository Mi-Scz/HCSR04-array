#include <iostream>
#include <wiringPi.h>
#include "SonarHCSR04.h"



using namespace std;


int main()
{
    if (wiringPiSetup() == -1)
        return -1;

    SonarHCSR04 sonar;
    sonar.select_sensor(0);


    while(1){
        cout << "Distance is " << sonar.distance() << " m." << endl;
    }
}
