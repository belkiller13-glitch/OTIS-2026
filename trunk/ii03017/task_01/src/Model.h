#pragma once

class Model
{
public:
    virtual ~Model() = default;

    // Расчёт следующего значения y.
    virtual double calculateNext(
        double y,
        double yPrev,
        double u,
        double dt
    ) const = 0;

    virtual const char* getName() const = 0;
};
