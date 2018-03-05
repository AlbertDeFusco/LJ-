#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Particle
{
    private:
      double x;
      double y;
      double z;
    public:
      void set_position(double, double, double c);
      double get_x() {return x;}
      double get_y() {return y;}
      double get_z() {return z;}

};

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


    string inputfile;
    inputfile = "dimer.xyz";
    ifstream inFile;

    string n_atoms;
    string comment;
    string line;

    Particle * particles;

    inFile.open("./dimer.xyz");
    if (inFile.is_open()) {
        getline(inFile, n_atoms);

        particles = new Particle[stoi(n_atoms)];

        getline(inFile, comment);
        int i = 0;
        while (getline(inFile, line)) {
            istringstream splitted(line);
            string name, x, y, z;
            splitted >> name >> x >> y >> z;

            particles[i].set_position(stod(x), stod(y), stod(z));
            i++;
        }
        if (i != stoi(n_atoms)) {
            cerr << "Wrong number of atoms in file." << endl;
            exit(1);
        }
    }
    else {
        cerr << "Unable to open " << inputfile;
        cerr << endl;
        exit(1);
    }

    cout << n_atoms << endl;
    cout << particles[1].get_z() << endl;


    return 0;
}
