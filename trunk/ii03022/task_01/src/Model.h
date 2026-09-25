#pragma once

class Model{
    public:
        virtual ~Model() = default;
        virtual double nextStep(double u) = 0;
        virtual void reset() = 0;

    };