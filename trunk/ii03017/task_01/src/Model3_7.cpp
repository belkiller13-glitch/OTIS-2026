#include "Model3_7.h"
#include <cmath>

Model3_7::Model3_7(double a, double b)
    : a(a), b(b)
{
}

double Model3_7::calculateNext(
    double y,
    double /*yPrev*/,
    double u,
    double dt
) const
{
    // Differential equation:
    // dy/dt = -exp(a)*y + b*u
    //
    // Euler method:
    // y(t+1) = y(t) + dt*(-exp(a)*y(t) + b*u(t))
    return y + dt * (-std::exp(a) * y + b * u);
}

const char* Model3_7::getName() const
{
    return "Model 3.7 - Exponential Scaling Process";
}
