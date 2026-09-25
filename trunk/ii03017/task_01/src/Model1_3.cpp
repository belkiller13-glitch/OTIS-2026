#include "Model1_3.h"

Model1_3::Model1_3(double a1, double a2, double b)
    : a1(a1), a2(a2), b(b)
{
}

double Model1_3::calculateNext(
    double y,
    double yPrev,
    double u,
    double /*dt*/
) const
{
    // Model 1.3:
    // y(t+1) = a1*y(t) + a2*y(t-1) + b*u(t)
    return a1 * y + a2 * yPrev + b * u;
}

const char* Model1_3::getName() const
{
    return "Model 1.3 - Second-Order Linear Model";
}
