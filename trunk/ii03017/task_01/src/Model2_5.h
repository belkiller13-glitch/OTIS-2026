#pragma once
#include "Model.h"

class Model2_5 final : public Model
{
private:
    double a;
    double b;

    static double sign(double x);

public:
    Model2_5(double a, double b);

    double calculateNext(
        double y,
        double yPrev,
        double u,
        double dt
    ) const override;

    const char* getName() const override;
};
