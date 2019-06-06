#ifndef DEKKER_H
#define DEKKER_H

#include "iteration.h"

class Dekker : public Iteration {
public:
    Dekker(double epsilon, const std::function<double (double)> &f) : Iteration(epsilon), mf(f) {}

    double solve(double a, double b) override {
        resetNumberOfIterations();

        double fa = mf(a);
        double fb = mf(b);

        checkAndFixAlgorithmCriteria(a, b, fa, fb);

        fmt::print("Dekker -> [{:}, {:}]\n", a, b);
        fmt::print("{:<5}|{:<20}|{:<20}|{:<20}|{:<20}\n", "K", "a", "b", "f(a)", "f(b)");
        fmt::print("------------------------------------------------------------------------------------ \n");
        fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), a, b, fa, fb);

        double lastB = a;
        double lastFb = mf(lastB);

        while(fabs(b-a) > epsilon()) {
            const double s = calculateSecant(b, fb, lastB, lastFb);
            const double m = calculateBisection(a, b);

            lastB = b;

            b = isSecantMethodAllowed(b, s, m) ? s : m;

            lastFb = fb;
            fb = mf(b);

            if (fa * fb > 0 && fb * lastFb < 0) {
                a = lastB;
            }

            fa = mf(a);
            checkAndFixAlgorithmCriteria(a, b, fa, fb);

            fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), a, b, fa, fb);
        }

        fmt::print("\n");

        return b;
    }

private:
    static void checkAndFixAlgorithmCriteria(double &a, double &b, double &fa, double &fb) {
        //Algorithm works in range [a,b] if criteria f(a)*f(b) < 0 and f(a) > f(b) is fulfilled
        assert(fa*fb < 0);
        if (fabs(fa) < fabs(fb)) {
            std::swap(a, b);
            std::swap(fa, fb);
        }
    }

    static double calculateSecant(double b, double fb, double lastB, double lastFb) {
        //No need to check division by 0, in this case the method returns NAN which is taken care by isSecantMethodAllowed method
        return b-fb*(b-lastB)/(fb-lastFb);
    }

    static double calculateBisection(double a, double b) {
        return 0.5*(a+b);
    }

    static bool isSecantMethodAllowed(double b, double s, double m) {
        //Value s calculated by secant method has to be between m and b
        return (b > m && s > m && s < b) ||
               (b < m && s > b && s < m);
    }

    const std::function<double (double)> &mf;
};

#endif