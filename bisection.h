#ifndef BISECTION_H
#define BISECTION_H

#include "iteration.h"

class Bisection : public Iteration {
public:
    Bisection(double epsilon, const std::function<double (double)> &f) : Iteration(epsilon), mf(f) {}

    double solve(double a, double b) override {
        resetNumberOfIterations();

        checkAndFixAlgorithmCriteria(a, b);

        fmt::print("Bisection -> [{:}, {:}]\n", a, b);
        fmt::print("{:<5}|{:<20}|{:<20}|{:<20}|{:<20}\n", "K", "a", "b", "x", "f(x)");
        fmt::print("------------------------------------------------------------------------------------ \n");

        double x = 0.5*(a+b);
        double fx = mf(x);
        fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), a, b, x, fx);

        while(fabs(fx) >= epsilon()) {
            x = calculateX(x, a, b, fx);
            fx = mf(x);

            fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), a, b, x, fx);
        }

        fmt::print("\n");

        return x;
    }

private:
    void checkAndFixAlgorithmCriteria(double &a, double &b) const {
        //Algorithm works in range [a,b] if criteria f(a)*f(b) < 0 and f(a) > f(b) is fulfilled
        assert(mf(a)*mf(b) < 0);
        if(mf(a) < mf(b)) {
            std::swap(a,b);
        }
    }

    static double calculateX(double x, double &a, double &b, double fx) {
        if(fx >= 0) a = x;
        if(fx < 0) b = x;

        return 0.5*(a+b);
    }

    const std::function<double (double)> &mf;
};

#endif
