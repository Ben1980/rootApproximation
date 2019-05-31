#ifndef ITERATION_H
#define ITERATION_H

#include <functional>
#include <ostream>
#include <fmt/format.h>
#include <vector>

class Iteration {
public:
    virtual double solve(double x) { return {}; }
    virtual double solve(double a, double b) { return {}; }
    virtual double solve(double a, double my, double b) { return {}; }

    int numberOfSteps() const { return mNumberOfSteps; }
    int numberOfEvaluations() const { return mNumberOfEvaluations; }

protected:
    explicit Iteration(int numberOfEvaluations) : mNumberOfSteps(0), mNumberOfEvaluations(numberOfEvaluations) {}

    constexpr static const double EPSILON = 1e-9;

    int mNumberOfSteps;
    int mNumberOfEvaluations;
};

#endif