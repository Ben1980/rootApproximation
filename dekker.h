#ifndef DEKKER_H
#define DEKKER_H

#include "iteration.h"

class Dekker : public Iteration {
public:
    Dekker(double epsilon, const std::function<double (double)> &f) : Iteration(epsilon), mf(f) {}

    double solve(double a, double b) override {
        mNumberOfSteps = 0;

        double mfa = mf(a);
        double mfb = mf(b);

        //Algorithm works in range [a,b] if criteria f(a)*f(b) < 0 and f(a) > f(b) is fulfilled
        assert(mfa*mfb < 0);
        if(fabs(mfa) < fabs(mfb)) {
            std::swap(a,b);
            std::swap(mfa,mfb);
        }

        fmt::print("Dekker -> [{:}, {:}]\n", a, b);
        fmt::print("{:<5}|{:<20}|{:<20}|{:<20}|{:<20}\n", "K", "a", "b", "f(a)", "f(b)");
        fmt::print("------------------------------------------------------------------------------------ \n");
        fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", mNumberOfSteps++, a, b, mfa, mfb);

        double c = a;
        double mfc = mf(c);

        while(fabs(b-a) > mEpsilon) {
            double s = b - mfb * (b - c) / (mfb - mfc);
            double m = 0.5 * (a + b);

            c = b;

            if ((b > m && s > m && s < b) ||
                (b < m && s > b && s < m)) {
                b = s;
            } else {
                b = m;
            }

            mfa = mf(a);
            mfb = mf(b);
            mfc = mf(c);
            if (mfa * mfb > 0 && mfb * mfc < 0) {
                a = c;
            }

            mfa = mf(a);
            if(fabs(mfa) < fabs(mfb)) {
                std::swap(a,b);
                std::swap(mfa,mfb);
            }

            fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", mNumberOfSteps++, a, b, mfa, mfb);
        }

        fmt::print("\n");

        return b;
    }

private:
    const std::function<double (double)> &mf;
};

#endif