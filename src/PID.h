#ifndef PID_H
#define PID_H


class PID
{
private:
    double previous_error = 0;
    double KP;
    double KI;
    double KD;
    double errorSum = 0;
    unsigned long previous_time = 0;
    bool output_limit = false;
    double min_output;
    double max_output;
public:
    PID(double kp = 0, double ki= 0, double kd = 0);
    double Calculate(double error, unsigned long current_time);
    void ReverseOutput(void);
    void SetOutputLimits(double min, double max);
};


#endif