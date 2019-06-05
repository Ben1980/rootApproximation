#ifndef BISECTION_H
#define BISECTION_H

#include "iteration.h"
#include <cassert>

class Bisection : public Iteration {
public:
    Bisection(double epsilon, const std::function<double (double)> &f) : Iteration(epsilon), mf(f) {}

    double solve(double a, double b) override {
        mNumberOfSteps = 0;

        //Algorithm works in range [a,b] if criteria f(a)*f(b) < 0 and f(a) > f(b) is fulfilled
        assert(mf(a)*mf(b) < 0);
        if(mf(a) < mf(b)) {
            std::swap(a,b);
        }

        fmt::print("Bisection -> [{:}, {:}]\n", a, b);
        fmt::print("{:<5}|{:<20}|{:<20}|{:<20}|{:<20}\n", "K", "a", "b", "x", "f(x)");
        fmt::print("------------------------------------------------------------------------------------ \n");

        double x = 0.5*(a+b);
        double fx = mf(x);
        fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", mNumberOfSteps++, a, b, x, fx);

        while(fabs(fx) >= mEpsilon) {
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
