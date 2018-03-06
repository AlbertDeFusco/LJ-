#pragma once

class Particle
{
    private:
      double x;
      double y;
      double z;
    public:
      void set_position(double, double, double c);
      double distance(Particle other);
      double get_x() {return x;}
      double get_y() {return y;}
      double get_z() {return z;}

};
