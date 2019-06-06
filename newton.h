#ifndef NEWTON_H
#define NEWTON_H

#include "iteration.h"

class Newton : public Iteration {
public:
    Newton(double epsilon, const std::function<double (double)> &f, const std::function<double (double)> &fPrime) : Iteration(epsilon), mf(f), mfPrime(fPrime) {}

    double solve(double x) override {
        resetNumberOfIterations();

        fmt::print("Newton -> [x0 = {:}]\n", x);
        fmt::print("{:<5}|{:<20}|{:<20}|{:<20}\n", "K", "x", "f(x)", "f'(x)");
        fmt::print("------------------------------------------------------------------ \n");

        double fx = mf(x);
        double fxPrime = mfPrime(x);
        fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), x, fx, fxPrime);

        while(fabs(fx) >= epsilon()) {
            x = calculateX(x, fx, fxPrime);

            fx = mf(x);
            fxPrime = mfPrime(x);

            fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), x, fx, fxPrime);
        }

        fmt::print("\n");

        return x;
    }

private:
    static double calculateX(double x, double fx, double fxPrime) {
        assert(fabs(fxPrime) >= std::numeric_limits<double>::min());

        return x - fx/fxPrime;
    }

    const std::function<double (double)> &mf;
    const std::function<double (double)> &mfPrime;
};

#endif
