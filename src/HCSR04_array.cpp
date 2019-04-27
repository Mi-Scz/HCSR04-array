#include <iostream>
#include <stdarg.h>
#include <wiringPi.h>
#include <bitset>

#include "HCSR04_array.h"

HCSR04_array::HCSR04_array()
{
    max_dist = 4;
    min_dist = 0.02;
    timeout = (int)(max_dist*2000000/340.29); //usec

    sensor_nmb = 8;

    pin_ch_A = 0; //grau 1
    pin_ch_B = 2; //weiß 1
    pin_ch_C = 3; //schwarz 0

    trigger = 4;
    echo = 5;

    bin_set = std::bitset<3>(0);

    pinMode(pin_ch_A, OUTPUT);
    pinMode(pin_ch_B, OUTPUT);
    pinMode(pin_ch_C, OUTPUT);

    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    pullUpDnControl (echo, PUD_DOWN) ;

    digitalWrite(trigger, LOW);
    delay(500);
}

int HCSR04_array::get_sensor_nmb()
{
    return sensor_nmb;
}


double HCSR04_array::data_one(int i)
{
    delay(10);

    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    now=micros();

    while (digitalRead(echo) == LOW && micros()-now<timeout);
    recordPulseLength();


    travelTimeUsec = endTimeUsec - startTimeUsec;

    distanceMeters = ((travelTimeUsec/1000000.0)*340.29)/2;

    if ((distanceMeters >= max_dist) || (distanceMeters <= min_dist ) )
    {
        return -1;
    }
    else{
        return distanceMeters;
    }
}

double* HCSR04_array::data_one(int i)
{

    static float data[sensor_nmb];

}


void HCSR04_array::select_sensor(int i)
{
    bin_set = std::bitset<3>(i);
    digitalWrite(pin_ch_A, bin_set[0]);
    digitalWrite(pin_ch_B, bin_set[1]);
    digitalWrite(pin_ch_C, bin_set[2]);
}


void HCSR04_array::recordPulseLength()
{
    startTimeUsec = micros();
    while ( digitalRead(echo) == HIGH );
    endTimeUsec = micros();
}
















