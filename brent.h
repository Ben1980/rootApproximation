#ifndef BRENT_H
#define BRENT_H

#include "iteration.h"

class Brent : public Iteration {
public:
    Brent(double epsilon, const std::function<double (double)> &f) : Iteration(epsilon), mf(f) {}

    double solve(double a, double b) override {
        resetNumberOfIterations();

        double fa = mf(a);
        double fb = mf(b);

        checkAndFixAlgorithmCriteria(a, b, fa, fb);

        fmt::print("Brent -> [{:}, {:}]\n", a, b);
        fmt::print("{:<5}|{:<20}|{:<20}|{:<20}|{:<20}|{:<20}\n", "K", "a", "b", "f(a)", "f(b)", "f(s)");
        fmt::print("---------------------------------------------------------------------------------------------------------- \n");
        fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), a, b, fa, fb, "");

        double lastB = a; // b_{k-1}
        double lastFb = fa;
        double s = std::numeric_limits<double>::max();
        double fs = std::numeric_limits<double>::max();
        double penultimateB = a; // b_{k-2}

        bool bisection = true;
        while(fabs(fb) > epsilon() && fabs(fs) > epsilon() && fabs(b-a) > epsilon()) {
            if(useInverseQuadraticInterpolation(fa, fb, lastFb)) {
                s = calculateInverseQuadraticInterpolation(a, b, lastB, fa, fb, lastFb);
            }
            else {
                s = calculateSecant(a, b, fa, fb);
            }

            if(useBisection(bisection, a, b, lastB, penultimateB, s)) {
                s = calculateBisection(a, b);
                bisection = true;
            }
            else {
                bisection = false;
            }

            fs = mf(s);
            penultimateB = lastB;
            lastB = b;

            if(fa*fs < 0) {
                b = s;
            }
            else {
                a = s;
            }

            fa = mf(a);
            lastFb = fb;
            fb = mf(b);
            checkAndFixAlgorithmCriteria(a, b, fa, fb);

            fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), a, b, fa, fb, fs);
        }

        fmt::print("\n");

        return fb < fs ? b : s;
    }

private:
    static double calculateBisection(double a, double b) {
        return 0.5*(a+b);
    }

    static double calculateSecant(double a, double b, double fa, double fb) {
        //No need to check division by 0, in this case the method returns NAN which is taken care by useSecantMethod method
        return b-fb*(b-a)/(fb-fa);
    }

    static double calculateInverseQuadraticInterpolation(double a, double b, double lastB, double fa, double fb, double lastFb) {
        return a*fb*lastFb/((fa-fb)*(fa-lastFb)) +
               b*fa*lastFb/((fb-fa)*(fb-lastFb)) +
               lastB*fa*fb/((lastFb-fa)*(lastFb-fb));
    }

    static bool useInverseQuadraticInterpolation(double fa, double fb, double lastFb) {
        return fa != lastFb && fb != lastFb;
    }

    static void checkAndFixAlgorithmCriteria(double &a, double &b, double &fa, double &fb) {
        //Algorithm works in range [a,b] if criteria f(a)*f(b) < 0 and f(a) > f(b) is fulfilled
        assert(fa*fb < 0);
        if (fabs(fa) < fabs(fb)) {
            std::swap(a, b);
            std::swap(fa, fb);
        }
    }

    bool useBisection(bool bisection, double a, double b, double lastB, double penultimateB, double s) const {
        static const double DELTA = epsilon() + std::numeric_limits<double>::min();

        return (bisection && fabs(s-b) >= 0.5*fabs(b-lastB)) ||                 //Bisection was used in last step but |s-b|>=|b-lastB|/2 <- Interpolation step would be to rough, so still use bisection
               (!bisection && fabs(s-b) >= 0.5*fabs(lastB-penultimateB)) ||     //Interpolation was used in last step but |s-b|>=|lastB-penultimateB|/2 <- Interpolation step would be to small
               (bisection  && fabs(b-lastB) < DELTA) ||                         //If last iteration was using bisection and difference between b and lastB is < delta use bisection for next iteration
               (!bisection && fabs(lastB-penultimateB) < DELTA);                //If last iteration was using interpolation but difference between lastB ond penultimateB is < delta use biscetion for next iteration
    }

    const std::function<double (double)> &mf;
};

#endif