#pragma once
#include "Model.h"

class  ActuatorSaturationNonLinearityModel : public Model{
    private:
        double a;
        double b;
        double uMin;
        double uMax;
        double sat(double u) const{
            if (u > uMax) return uMax;
            else if (u < uMin) return uMin;
            else return u;
        }
        double y = 0;
    public:
    ActuatorSaturationNonLinearityModel(double a, double b, double uMin, double uMax)
    : a(a), b(b), uMin(uMin), uMax(uMax)
    {
    }
    double nextStep(double u) override{
        y = a * y + b * sat(u);
        return y;
    }
    void reset() override{
        y = 0;
    }
};