#include "Model2_5.h"
#include <cmath>

Model2_5::Model2_5(double a, double b)
    : a(a), b(b)
{
}

double Model2_5::sign(double x)
{
    if (x > 0.0)
        return 1.0;
    if (x < 0.0)
        return -1.0;
    return 0.0;
}

double Model2_5::calculateNext(
    double y,
    double /*yPrev*/,
    double u,
    double /*dt*/
) const
{
    // Model 2.5:
    // y(t+1) = a*y(t) + b*sign(u(t))*(1 - exp(-|u(t)|))
    return a * y + b * sign(u) * (1.0 - std::exp(-std::abs(u)));
}

const char* Model2_5::getName() const
{
    return "Model 2.5 - Signum Friction and Exponential Growth";
}
