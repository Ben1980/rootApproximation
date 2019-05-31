#ifndef SECANT_H
#define SECANT_H

#include "iteration.h"
#include <cassert>
#include <limits>

class Secant : public Iteration {
public:
    explicit Secant(const std::function<double (double)> &f) : mf(f) {}

    double solve(double a, double b) override {
        mNumberOfSteps = 0;

        //Algorithm works in range [a,b] if criteria f(a) > f(b) is fulfilled
        if(mf(a) < mf(b)) {
            std::swap(a,b);
        }

        fmt::print("Secant -> [{:}, {:}]\n", a, b);
        fmt::print("{:<5}|{:<20}|{:<20}\n", "K", "x", "f(x)");
        fmt::print("-------------------------------------------------- \n");

        double x = b;
        double lastX = a;
        double fx = mf(b);
        double lastFx = mf(a);

        fmt::print("{:<5}|{:<20.15f}|{:<20.15f}\n", mNumberOfSteps++, x, fx);

        while(fabs(fx) >= EPSILON) {
            const double functionDifference = fx - lastFx;

            assert(fabs(functionDifference) >= std::numeric_limits<double>::min());

            const double x_tmp = x - fx*(x-lastX)/functionDifference;
            lastFx = fx;
            lastX = x;
            x = x_tmp;
            fx = mf(x);

            fmt::print("{:<5}|{:<20.15f}|{:<20.15f}\n", mNumberOfSteps++, x, fx);
        }

        fmt::print("\n");

        return x;
    }

private:
    const std::function<double (double)> &mf;
};

#endif
