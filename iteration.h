#ifndef ITERATION_H
#define ITERATION_H

#include <functional>
#include <fmt/format.h>

class Iteration {
public:
    virtual double solve(double x) { return {}; }
    virtual double solve(double a, double b) { return {}; }

    int numberOfSteps() const { return mNumberOfSteps; }

protected:
    explicit Iteration(double epsilon) : mEpsilon(epsilon), mNumberOfSteps(0) {}

    const double mEpsilon;
    int mNumberOfSteps;
};

#endif