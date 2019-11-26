#ifndef CIRCLE_CLASS_H
#define CIRCLE_CLASS_H

#include <cmath>

double const PI = 3.14159265;

class Circle {
    // to make these accessible from outside the class object, swap the next 2 lines
    double xpos, ypos, radius;
  public:
    // constructors
    Circle(double x, double y, double r) {xpos=x; ypos=y; radius=r;}
    Circle() {xpos=0.0; ypos=0.0; radius=0.0;}

    // public functions
    // getters
    double getRadius() {return radius;}
    double getX() {return xpos;}
    double getY() {return ypos;}
    double getArea() {return radius*radius*PI;}

    // operator overides
    Circle operator+(Circle c) {
      Circle a((xpos+c.xpos)*0.5, (ypos+c.ypos)*0.5, sqrt(radius*radius+c.radius*c.radius));
      return a;
    }
    bool operator>(Circle c) {
      if (radius > c.radius) {
        return true;
      }
      else {
        return false;
      }
    }
    // friends
    friend std::ostream& operator<<(std::ostream& os, const Circle c) {
      os << "radius = " << c.radius << " at (x,y) = (" << c.xpos << "," << c.ypos << ")";
      return os;
    }

};

#endif // CIRCLE_CLASS_H
