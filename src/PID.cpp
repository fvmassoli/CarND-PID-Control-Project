#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    p_error = 0;
    i_error = 0;
    d_error = 0;

    // Twiddle parameters
    twiddle = false;
    dp = {0.1*Kp,0.1*Kd,0.1*Ki};
    step = 1;
    n_settle_steps = 100;
    n_eval_steps = 2000;
    best_error = std::numeric_limits<double>::max();
}

void PID::UpdateError(double cte) {

    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;

}

double PID::TotalError() {

    return ( - Kp * p_error - Kd * d_error - Ki * i_error );

}



/** alternative implementation using twiddle */

/**
void PID::UpdateError(double cte) {
    if (step == 1) {
        // to get correct initial d_error
        p_error = cte;
    }
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;

    // update total error only if we're past number of settle steps
    if (step % (n_settle_steps + n_eval_steps) > n_settle_steps){
        total_error += pow(cte,2);
    }

    // last step in twiddle loop... twiddle it?
    if (twiddle && step % (n_settle_steps + n_eval_steps) == 0){
        if (total_error < best_error) {
            best_error = total_error;
            if (step !=  n_settle_steps + n_eval_steps) {
                dp[param_index] *= 1.1;            
            }
            param_index = (param_index + 1) % 3;
        }
        
        // TODO ...

        total_error = 0;
        cout << "new parameters" << endl;
        cout << "P: " << Kp << ", I: " << Ki << ", D: " << Kd << endl;        
    }
    step++;
}
*/

