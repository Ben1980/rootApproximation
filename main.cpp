#include <fmt/format.h>
#include <cmath>
#include "iteration.h"
#include "brent.h"
#include "dekker.h"
#include "newton.h"
#include "bisection.h"
#include "secant.h"

int main() {
    auto f = [](double x){
        return x*x*x-x*x-x-1;
    };

    auto fPrime = [](double x) {
        return 3*x*x-2*x-1;
    };

    const double epsilon = 1e-10;

    Iteration *bisection = new Bisection(epsilon, f);
    Iteration *secant1 = new Secant(epsilon, f);
    Iteration *secant2 = new Secant(epsilon, f);
    Iteration *newton = new Newton(epsilon, f, fPrime);
    Iteration *dekker1 = new Dekker(epsilon, f);
    Iteration *dekker2 = new Dekker(epsilon, f);
    Iteration *brent1 = new Brent(epsilon, f);
    Iteration *brent2 = new Brent(epsilon, f);

    fmt::print("Solving f(x)=0 for x^3-x^2-x-1 with Bisection, Secant, Newton, Dekker and Brent Method\n\n");

    const double bisectionResults = bisection->solve(0, 2);
    const double secantResults1 = secant1->solve(1.5, 2);
    const double secantResults2 = secant2->solve(0, 2);
    const double newtonResults = newton->solve(1.5);
    const double dekkerResults1 = dekker1->solve(1.5, 2);
    const double dekkerResults2 = dekker2->solve(0, 2);
    const double brentResults1 = brent1->solve(1.5, 2);
    const double brentResults2 = brent2->solve(0, 2);

    fmt::print("\n");
    fmt::print("Comparison of Effort\n");
    fmt::print("{:<20}|{:<15}|{:<20}|{:<10}\n", "Method", "Start/Range", "No. of Iterations", "Approximated Root");
    fmt::print("--------------------------------------------------------------------------\n");
    fmt::print("{:<20}|{:<15}|{:<20}|{:<10.15f}\n", "Bisection", "[0, 2]", bisection->numberOfSteps(), bisectionResults);
    fmt::print("{:<20}|{:<15}|{:<20}|{:<10.15f}\n", "Secant Method", "[1.5, 2]", secant1->numberOfSteps(), secantResults1);
    fmt::print("{:<20}|{:<15}|{:<20}|{:<10.15f}\n", "Secant Method", "[0, 2]", secant2->numberOfSteps(), secantResults2);
    fmt::print("{:<20}|{:<15}|{:<20}|{:<10.15f}\n", "Newton Method", "[x^0=1.5]", newton->numberOfSteps(), newtonResults);
    fmt::print("{:<20}|{:<15}|{:<20}|{:<10.15f}\n", "Dekker Method", "[1.5, 2]", dekker1->numberOfSteps(), dekkerResults1);
    fmt::print("{:<20}|{:<15}|{:<20}|{:<10.15f}\n", "Dekker Method", "[0, 2]", dekker2->numberOfSteps(), dekkerResults2);
    fmt::print("{:<20}|{:<15}|{:<20}|{:<10.15f}\n", "Brent Method", "[1.5, 2]", brent1->numberOfSteps(), brentResults1);
    fmt::print("{:<20}|{:<15}|{:<20}|{:<10.15f}\n", "Brent Method", "[0, 2]", brent2->numberOfSteps(), brentResults2);
}