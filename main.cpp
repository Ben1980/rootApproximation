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

    auto fprime = [](double x) {
        return std::cos(x)*std::sinh(x) - std::sin(x)*std::cosh(x);
    };

    Iteration *bisection = new Bisection(f);
    Iteration *secant = new Secant(f);
    Iteration *newton = new Newton(f, fprime);
    Iteration *brent = new Brent(f);

    fmt::print("Solving f(x)=0 for PI * acos(1.0/cosh(x)) with Fixed-point, Bisection, Secant, Newton and Brent Method\n\n");

    const double bisectionResults = bisection->solve(0, 3);
    const double secantResults1 = secant->solve(1.5, 3);
    const double secantResults2 = secant->solve(0, 3);
    const double newtonResults = newton->solve(1.5);
    const double brentResults = brent->solve(0, 1.5, 3);

    fmt::print("\n");
    fmt::print("Comparison of effort\n");
    fmt::print("{:<20}|{:<10}|{:<10}|{:<10}\n", "Method", "Start", "No. of Steps", "No. of f-Evaluations");
    fmt::print("----------------------------------------------------------------- \n");
    fmt::print("{:<20}|{:<10}|{:<10}|{:<10}\n", "Bisection", "[0, 3]", bisection->numberOfSteps(), bisection->numberOfEvaluations());
    fmt::print("{:<20}|{:<10}|{:<10}|{:<10}\n", "Secant Method", "[1.5, 3]", secant->numberOfSteps(), secant->numberOfEvaluations());
    fmt::print("{:<20}|{:<10}|{:<10}|{:<10}\n", "Secant Method", "[0, 3]", secant->numberOfSteps(), secant->numberOfEvaluations());
    fmt::print("{:<20}|{:<10}|{:<10}|{:<10}\n", "Newton Method", "[x^0=1.5]", newton->numberOfSteps(), newton->numberOfEvaluations());
    fmt::print("{:<20}|{:<10}|{:<10}|{:<10}\n", "Brent", "[0, 1.5, 3]", brent->numberOfSteps(), brent->numberOfEvaluations());
}