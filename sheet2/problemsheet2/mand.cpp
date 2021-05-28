#include <cstdio>
#include <iostream>

int const N = 100;

class point {
  double xpos, ypos;
public:
  point(double x, double y) {xpos=x; ypos=y;}
  point() {xpos=0.0; ypos=0.0;}
  double getX() {return xpos;}
  double getY() {return ypos;}
};

bool in_circle(point p) {
  // checks if a point is within the origin circle radius 2
  double x = p.getX();
  double y = p.getY();
  double r2 = x*x + y*y;
  return (r2 < 4);
}

point next_point(point initial, point current) {
  // returns the next iteration of the mandelbrot set
  // for given starting point and previous point
  double x = (current.getX() * current.getX()) - (current.getY() * current.getY()) + initial.getX();
  double y = (2 * current.getX() * current.getY()) + initial.getY();
  return point(x, y);
}

int iterations_before_leaving(point initial, point current=point(), int n=0) {
  point next = next_point(initial, current);
  if (n == N) {
    // max iteration count
    return n;
  }
  else if (!in_circle(current)) {
    // if the point isn't in the circle
    // return that iteration number
    return n;
  }
  else {
    // recurse
    return iterations_before_leaving(initial, next, n+1);
  }
}

void get_char(int n, char *c) {
  // inputs of an integer and a pointer to a character
  // if integer is the same as N, returns an 'o'
  // else returns a '-'
  if (n == N) {
    *c = 'o';
  }
  else {
    *c = '-';
  }
}

int main(int argc, char const *argv[]) {
  // output redirection to mandelbrot.txt
  freopen("mandelbrot.txt", "w", stdout);

  // iterate through points in the 2D plane
  for (double y = 1.2; y >= -1.2; y -= 0.02) {
    for (double x = -2.2; x <= 1.0; x += 0.02) {
      // calculate number of iterations before leaving the circle(x,y=0,0; r=2)
      int value = iterations_before_leaving(point(x,y));

      // obtain character to print to file
      char c[0];
      get_char(value, c);

      // print to file
      std::cout << *c;
    }
    // begin next line
    std::cout << '\n';
  }

  return 0;
}
