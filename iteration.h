#ifndef ITERATION_H
#define ITERATION_H

#include <functional>
#include <fmt/format.h>

class Iteration {
public:
    virtual double solve(double x) { return {}; }
    virtual double solve(double a, double b) { return {}; }

    int numberOfIterations() const { return mNumberOfIterations; }

protected:
    explicit Iteration(double epsilon) : mEpsilon(epsilon), mNumberOfIterations(0) {}

    void resetNumberOfIterations() { mNumberOfIterations = 0; }
    int incrementNumberOfIterations() { return mNumberOfIterations++; }
    double epsilon() const { return mEpsilon; }

private:
    const double mEpsilon;
    int mNumberOfIterations;
};

#endif