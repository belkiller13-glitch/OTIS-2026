#include "InputSignal.h"
#include <cmath>

double getInput(SignalType type, int tau, double amplitude)
{
    switch (type)
    {
    case SignalType::Step:
        // u(t) = A
        return amplitude;

    case SignalType::Impulse:
        // u(0) = A, u(t > 0) = 0
        return (tau == 0) ? amplitude : 0.0;

    case SignalType::Harmonic:
        // u(t) = A*sin(t)
        return amplitude * std::sin(static_cast<double>(tau));
    }

    return 0.0;
}
