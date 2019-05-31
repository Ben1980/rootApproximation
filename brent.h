#ifndef BRENT_H
#define BRENT_H

#include "iteration.h"

class Brent : public Iteration {
public:
    explicit Brent(const std::function<double (double)> &f) : mf(f) {}

    double solve(double a, double my, double b) override {
        return {};
    }

private:
    const std::function<double (double)> &mf;
};

#endif