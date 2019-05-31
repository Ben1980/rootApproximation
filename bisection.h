#ifndef BISECTION_H
#define BISECTION_H

#include "iteration.h"

class Bisection : public Iteration {
public:
    explicit Bisection(const std::function<double (double)> &f) : Iteration(34), mf(f) {}

    double solve(double a, double b) override {
        mNumberOfSteps = 0;

        fmt::print("Bisection -> [{:}, {:}]\n", a, b);
        fmt::print("{:<5}|{:<20}|{:<20}|{:<20}|{:<20}\n", "K", "a", "b", "x", "f(x)");
        fmt::print("------------------------------------------------------------------------------------ \n");

        double x = 0.5*(a+b);
        double fx = mf(x);
        fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", mNumberOfSteps++, a, b, x, fx);

        while(fabs(fx) >= EPSILON) {
            if(fx >= 0) a = x;
            if(fx < 0) b = x;

            x = 0.5*(a+b);
            fx = mf(x);

            fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", mNumberOfSteps++, a, b, x, fx);
        }

        fmt::print("\n");

        return x;
    }

private:
    const std::function<double (double)> &mf;
};

#endif
