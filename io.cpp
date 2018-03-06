#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

#include "particle.h"

using namespace std;

int read_cluster(Particle * &particles, string inputfile) {
    ifstream inFile;
    inFile.open(inputfile);

    int n_atoms;

    if (inFile.is_open()) {
        string comment, line;

        getline(inFile, line);
        n_atoms = stoi(line);
        particles = new Particle[n_atoms];

        getline(inFile, comment);
        int i = 0;
        while (getline(inFile, line)) {
            istringstream splitted(line);
            string name, x, y, z;
            splitted >> name >> x >> y >> z;

            particles[i].set_position(stod(x), stod(y), stod(z));
            i++;
        }
        if (i != n_atoms) {
            cerr << "Wrong number of atoms in file." << endl;
            exit(1);
        }
    }
    else {
        cerr << "Unable to open " << inputfile;
        cerr << endl;
        exit(1);
    }

    return n_atoms;

}
