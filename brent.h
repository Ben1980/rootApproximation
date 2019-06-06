#ifndef BRENT_H
#define BRENT_H

#include "iteration.h"

class Brent : public Iteration {
public:
    Brent(double epsilon, const std::function<double (double)> &f) : Iteration(epsilon), mf(f) {}

    double solve(double a, double b) override {
        resetNumberOfIterations();

        double mfa = mf(a);
        double mfb = mf(b);

        //Algorithm works in range [a,b] if criteria f(a)*f(b) < 0 and f(a) > f(b) is fulfilled
        assert(mfa*mfb < 0);
        if(fabs(mfa) < fabs(mfb)) {
            std::swap(a,b);
            std::swap(mfa,mfb);
        }

        fmt::print("Brent -> [{:}, {:}]\n", a, b);
        fmt::print("{:<5}|{:<20}|{:<20}|{:<20}|{:<20}|{:<20}\n", "K", "a", "b", "f(a)", "f(b)", "f(s)");
        fmt::print("---------------------------------------------------------------------------------------------------------- \n");
        fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), a, b, mfa, mfb, "");

        double c = a;
        double mfc = mf(c);
        double mfs = std::numeric_limits<double>::max();
        double d;
        double s = std::numeric_limits<double>::max();

        bool bisection = true;
        while(fabs(mfb) > epsilon() && fabs(mfs) > epsilon() && fabs(b-a) > epsilon()) {
            if(mfa != mfc && mfb != mfc) {
                s = a*mfb*mfc/((mfa-mfb)*(mfa-mfc)) +
                    b*mfa*mfc/((mfb-mfa)*(mfb-mfc)) +
                    c*mfa*mfb/((mfc-mfa)*(mfc-mfb));
            }
            else {
                s = b - mfb*(b-a)/(mfb-mfa);
            }

            if(useBisection(bisection, a, b, c, d, s)) {
                s = 0.5*(a+b);
                bisection = true;
            }
            else {
                bisection = false;
            }

            mfs = mf(s);
            d = c;
            c = b;

            if(mfa*mfs < 0) {
                b = s;
            }
            else {
                a = s;
            }

            mfa = mf(a);
            mfb = mf(b);
            mfc = mf(c);
            if(fabs(mfa) < fabs(mfb)) {
                std::swap(a,b);
                std::swap(mfa,mfb);
            }

            fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), a, b, mfa, mfb, mfs);
        }

        fmt::print("\n");

        return mfb < mfs ? b : s;
    }

private:
    bool useBisection(bool bisection, double a, double b, double c, double d, double s) const {
        return (bisection && fabs(s-b) >= 0.5*fabs(b-c)) ||     //Bisection was used in last step but |s-b|>=|b-c|/2 <- Interpolation step would be to rough, so still use bisection
               (!bisection && fabs(s-b) >= 0.5*fabs(c-d));      //Interpolation was used in last step but |s-b|>=|c-d|/2 <- Interpolation step would be to small
    }

    const std::function<double (double)> &mf;
};

#endif