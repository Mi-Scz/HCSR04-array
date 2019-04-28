#ifndef HCSR04_ARRAY_H
#define HCSR04_ARRAY_H

#include <bitset>


class HCSR04_array
{
    public:
        HCSR04_array();
        float* data();
        float data(int i);
        int get_sensor_nmb();
        void print_data();

    protected:

    private:

        void recordPulseLength();
        void select_sensor(int i);
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

#endif // HCSR04_ARRAY_H
