#pragma once
#include "Model.h"

class CubicGrowthAndControlModel : public Model{
    private:
        double a;
        double b;
        double h;
        double y = 0;

    public:
    CubicGrowthAndControlModel(double a, double b, double h)
    : a(a), b(b), h(h)
    {
    }

    double nextStep(double u) override{
        double f = a * y * y * y + b * u;
        y = y + h * f;
        return y;
    }

    void reset() override{
        y = 0;
    }
};