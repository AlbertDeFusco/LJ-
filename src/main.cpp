#include <iostream>
#include <string>

#include "particle.h"
#include "io.h"
#include "lennard-jones.h"

int main(int argc, char* argv[])
{


    if (argc<2) {
        cerr << "Please specify the filename to read" << endl;
        return 1;
    }

    string inputfile(argv[1]);
    Particle *particles = NULL;
    int n_atoms = read_cluster(particles, inputfile);

    cout << "Cluster of " << n_atoms << " atoms" << endl;

    LennardJones lj;
    double energy = lj.total_energy(particles, n_atoms);
    cout << "Total Lennard-Jones potential energy " << energy << endl;

    return 0;
}
