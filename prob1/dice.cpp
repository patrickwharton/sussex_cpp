#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int dice();
int main(int argc, char const *argv[]) {
  srand(time(NULL));

  int dice_roll = dice();
  cout << dice_roll << endl;
  return 0;
}

double rnd(void) {
  // returns a random double between 0 and 1, uniformally distributed
  double number = rand() / (double)RAND_MAX;
  return number;
}

int dice(void) {
  // returns an int between 1 and 6, simulating a classic dice roll
  int dice_roll = 1 + rnd() * 6;
  // cout << dice_roll << endl;
}
