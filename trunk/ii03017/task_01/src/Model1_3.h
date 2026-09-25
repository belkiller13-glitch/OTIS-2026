#pragma once
#include "Model.h"

class Model1_3 final : public Model
{
private:
    double a1;
    double a2;
    double b;

public:
    Model1_3(double a1, double a2, double b);

    double calculateNext(
        double y,
        double yPrev,
        double u,
        double dt
    ) const override;

    const char* getName() const override;
};
