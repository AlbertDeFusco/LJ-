#include <math.h>
#include <iostream>
#include <string>

#include "particle.h"

using namespace std;

void Particle::set_position(double a, double b, double c) {
    x = a;
    y = b;
    z = c;
}

double Particle::distance(Particle other) {
    double d2, dist;
    double dx, dy, dz;
    dx = other.get_x() - this->get_x();
    dy = other.get_y() - this->get_y();
    dz = other.get_z() - this->get_z();

    d2 = (dx*dx) + (dy*dy) + (dz*dz);

    dist = sqrt(d2);
    return dist;
}


