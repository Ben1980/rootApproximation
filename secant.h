#ifndef SECANT_H
#define SECANT_H

#include "iteration.h"

class Secant : public Iteration {
public:
    explicit Secant(const std::function<double (double)> &f) : Iteration(9), mf(f) {}

    double solve(double a, double b) override {
        mNumberOfSteps = 0;

        fmt::print("Secant -> [{:}, {:}]\n", a, b);
        fmt::print("{:<5}|{:<20}|{:<20}\n", "K", "x", "f(x)");
        fmt::print("-------------------------------------------------- \n");

        double x = b;
        double lastX = a;
        double fx = mf(b);
        double lastFx = mf(a);

        fmt::print("{:<5}|{:<20.15f}|{:<20.15f}\n", mNumberOfSteps++, x, fx);

        while(fabs(fx) >= EPSILON) {
            const double x_tmp = x - fx*(x-lastX)/(fx-lastFx);
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
