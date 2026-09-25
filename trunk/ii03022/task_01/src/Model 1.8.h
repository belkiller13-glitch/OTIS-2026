#pragma once
#include "Model.h"

class GeneralizedAutoregressiveLinearModel : public Model{
    private:
        double a1;
        double a2;
        double b1;
        double b2;
        double y = 0;          // y(t)
        double y_previous = 0;   // y(t - 1)
        double u_previous = 0; // u(t - 1)
    public:
        GeneralizedAutoregressiveLinearModel(double a1, double a2, double b1, double b2)
        : a1(a1), a2(a2), b1(b1),b2(b2)
        {
        }

        double nextStep(double u) override{
            double y_next = (a1 * y) + (a2 * y_previous) + (b1 * u) + (b2 * u_previous);
            y_previous = y;
            y = y_next;
            u_previous = u;
            return y_next;
        }

        void reset() override{
            y = 0;
            u_previous = 0;
            y_previous = 0;
        };
};