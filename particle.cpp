#include <math.h>
#include <iostream>
#include <string>

#include "particle.h"
#include "io.h"

using namespace std;

void Particle::set_position(double a, double b, double c) {
    x = a;
    y = b;
    z = c;
}

double distance(Particle p1, Particle p2) {
    double d2, dist;
    d2 = pow(p2.get_x() - p1.get_x(), 2)
       + pow(p2.get_y() - p1.get_y(), 2)
       + pow(p2.get_z() - p1.get_z(), 2);
    dist = sqrt(d2);
    return dist;
}

int main()
{

    /*Particle * particles;
    particles = new Particle[2];

    particles[0].set_position(0., 0.);
    particles[1].set_position(2., 1.);
    double d;
    d = distance(particles[0], particles[1]);
    cout << d << endl;*/

    string inputfile = "dimer.xyz";
    Particle *particles = NULL;
    int n_atoms = read_cluster(particles, inputfile);

    cout << n_atoms << endl;
    cout << particles[1].get_z() << endl;

    return 0;
}
