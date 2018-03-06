#pragma once

#include "particle.h"

class LennardJones
{
    private:
        double sigma, epsilon;
        double potential(double);
    public:
        LennardJones() : sigma(3.40), epsilon(0.238) {}
        LennardJones(double s, double e): sigma(s), epsilon(e) {}

        double total_energy(Particle[], int);
        void print_params();
};
