#ifndef NEWTON_H
#define NEWTON_H

#include "iteration.h"
#include <cassert>
#include <limits>

class Newton : public Iteration {
public:
    Newton(const std::function<double (double)> &f, const std::function<double (double)> &fPrime) : Iteration(11), mf(f), mfPrime(fPrime) {}

    double solve(double x) override {
        mNumberOfSteps = 0;

        fmt::print("Newton -> [x0 = {:}]\n", x);
        fmt::print("{:<5}|{:<20}|{:<20}|{:<20}\n", "K", "x", "f(x)", "f'(x)");
        fmt::print("------------------------------------------------------------------ \n");

        double fx = mf(x);
        double fxPrime = mfPrime(x);
        fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", mNumberOfSteps++, x, fx, fxPrime);

        while(fabs(fx) >= EPSILON) {
            assert(fabs(fxPrime) >= std::numeric_limits<double>::min());

            x -= fx/fxPrime;

            fx = mf(x);
            fxPrime = mfPrime(x);

            fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", mNumberOfSteps++, x, fx, fxPrime);
        }

        fmt::print("\n");

        return x;
    }

private:
    const std::function<double (double)> &mf;
    const std::function<double (double)> &mfPrime;
};

#endif
