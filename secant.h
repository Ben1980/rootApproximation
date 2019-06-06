#ifndef SECANT_H
#define SECANT_H

#include "iteration.h"

class Secant : public Iteration {
public:
    Secant(double epsilon, const std::function<double (double)> &f) : Iteration(epsilon), mf(f) {}

    double solve(double a, double b) override {
        resetNumberOfIterations();

        fmt::print("Secant -> [{:}, {:}]\n", a, b);
        fmt::print("{:<5}|{:<20}|{:<20}|{:<20}|{:<20}\n", "K", "a", "b", "f(a)", "f(b)");
        fmt::print("--------------------------------------------------------------------------------------\n");

        if(mf(a) > mf(b)) {
            std::swap(a,b);
        }

        double x = b;
        double lastX = a;
        double fx = mf(b);
        double lastFx = mf(a);

        fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), x, lastX, fx, lastFx);

        while(fabs(fx) >= epsilon()) {
            const double x_tmp = calculateX(x, lastX, fx, lastFx);

            lastFx = fx;
            lastX = x;
            x = x_tmp;

            fx = mf(x);

            fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), x, lastX, fx, lastFx);
        }

        fmt::print("\n");

        return x;
    }

private:
    static double calculateX(double x, double lastX, double fx, double lastFx) {
        const double functionDifference = fx - lastFx;
        assert(fabs(functionDifference) >= std::numeric_limits<double>::min());

        return x - fx*(x-lastX)/functionDifference;
    }

    const std::function<double (double)> &mf;
};

#endif
