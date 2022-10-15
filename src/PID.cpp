#include <PID.h>

PID::PID(double kp,double ki,double kd)
{
    KP = kp;
    KI = ki;
    KD = kd;
}

double PID::Calculate(double error, unsigned long current_time){
    unsigned long time_change = current_time - previous_time;
    previous_time = current_time;
    float output = KP * error;
    output += KD * (error - previous_error) / time_change;
    errorSum += error * time_change;
    output += KI * errorSum;
    previous_error = error;

    if (output_limit) {
        if (output > max_output) {
            return max_output;
        }
        if (output < min_output) {
            return min_output;
        }
    }else{
        return output;
    }
}

void PID::ReverseOutput(void) {
    KP = KP * -1;
    KI = KI * -1;
    KD = KD * -1;
}

void PID::SetOutputLimits(double min, double max) {
    min_output = min;
    max_output = max;
    output_limit = true;
}