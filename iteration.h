#ifndef ITERATION_H
#define ITERATION_H

#include <functional>
#include <fmt/format.h>

class Iteration {
public:
    virtual double solve(double x) { return {}; }
    virtual double solve(double a, double b) { return {}; }
    virtual double solve(double a, double my, double b) { return {}; }

    int numberOfSteps() const { return mNumberOfSteps; }

protected:
    Iteration() : mNumberOfSteps(0) {}

    constexpr static const double EPSILON = 1e-9;

    int mNumberOfSteps;
};

#endif