#include <fmt/format.h>
#include <cmath>
#include "iteration.h"
#include "brent.h"
#include "newton.h"
#include "bisection.h"
#include "secant.h"

int main() {
    auto f = [](double x){
        return std::cos(x)*std::cosh(x)+1;
    };

    auto fPrime = [](double x) {
        return std::cos(x)*std::sinh(x) - std::sin(x)*std::cosh(x);
    };

    Iteration *bisection = new Bisection(f);
    Iteration *secant1 = new Secant(f);
    Iteration *secant2 = new Secant(f);
    Iteration *newton = new Newton(f, fPrime);
    Iteration *brent = new Brent(f);

    fmt::print("Solving f(x)=0 for PI * acos(1.0/cosh(x)) with Fixed-point, Bisection, Secant, Newton and Brent Method\n\n");

    const double bisectionResults = bisection->solve(0, 3);
    const double secantResults1 = secant1->solve(1.5, 3);
    const double secantResults2 = secant2->solve(0, 3);
    const double newtonResults = newton->solve(1.5);
    const double brentResults = brent->solve(0, 1.5, 3);

    fmt::print("\n");
    fmt::print("Comparison of effort\n");
    fmt::print("{:<20}|{:<15}|{:<15}|{:<10}\n", "Method", "Start/Range", "No. of Steps", "Approximated Root");
    fmt::print("----------------------------------------------------------------- \n");
    fmt::print("{:<20}|{:<15}|{:<15}|{:<10.15f}\n", "Bisection", "[0, 3]", bisection->numberOfSteps(), bisectionResults);
    fmt::print("{:<20}|{:<15}|{:<15}|{:<10.15f}\n", "Secant Method", "[1.5, 3]", secant1->numberOfSteps(), secantResults1);
    fmt::print("{:<20}|{:<15}|{:<15}|{:<10.15f}\n", "Secant Method", "[0, 3]", secant2->numberOfSteps(), secantResults2);
    fmt::print("{:<20}|{:<15}|{:<15}|{:<10.15f}\n", "Newton Method", "[x^0=1.5]", newton->numberOfSteps(), newtonResults);
    fmt::print("{:<20}|{:<15}|{:<15}|{:<10.15f}\n", "Brent", "[0, 1.5, 3]", brent->numberOfSteps(), brentResults);
}