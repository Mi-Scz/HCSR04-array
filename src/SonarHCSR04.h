#ifndef SONARHCSR04_H
#define SONARHCSR04_H

#include <bitset>


class SonarHCSR04
{
  public:
    SonarHCSR04();
    double distance();
    void select_sensor(int i);
    int get_sensor_nmb();

  private:
    void recordPulseLength();
    int trigger;
    int echo;
    float max_dist;
    float min_dist;
    unsigned int timeout;
    volatile long startTimeUsec;
    volatile long endTimeUsec;
    double distanceMeters;
    long travelTimeUsec;
    long now;
    int pin_ch_A;
    int pin_ch_B;
    int pin_ch_C;
    int sensor_nmb;
    std::bitset<3> bin_set;
};

#endif
