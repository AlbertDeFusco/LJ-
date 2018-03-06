#include <math.h>
#include <iostream>

#include "particle.h"
#include "lennard-jones.h"

using namespace std;

double LennardJones::potential(double r) {
    double sr6 = pow(this->sigma/r, 6);
    double sr12 = sr6 * sr6;
    double lj = 4. * this->epsilon * (sr12 - sr6);
    return lj;
}

double LennardJones::total_energy(Particle particles[], int n_atoms) {
    double e = 0.0;
    double r;
    for (int i=0; i<n_atoms - 1; i++) {
        for (int j=i+1; j<n_atoms; j++) {
            r = particles[j].distance(particles[i]);
            e += potential(r);
        }
    }

    return e;
}

void LennardJones::print_params() {
    cout << this->epsilon << ',' << this->sigma << endl;
}
