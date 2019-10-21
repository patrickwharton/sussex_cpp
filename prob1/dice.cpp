// #include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int two_dice();

int main(int argc, char *argv[]) {
  // initialise random seed
  srand(time(NULL));
  int total_rolls;
  if (argc == 2) {
    // obtain roll count from command line input
    total_rolls = atoi(argv[1]);

    // check input is valid
    if (!(total_rolls > 0)) {
      cout << "invalid input\n" << "please use inputs in the form \"./dice <integer>\"\n";
      return 1;
    }
  }
  else {
    cout << "invalid input\n" << "please use inputs in the form \"./dice <integer>\"\n";
    return 1;
  }

  // initialises a vector with all possible outputs of two_dice
  // includes two placeholders at the start, and starts the count at 0
  vector<int> score_count;
  for (size_t i = 0; i <= 12; i++) {
    score_count.push_back(0);
  }

  // initialises a vector and stores N random doubles between 0 and 1
  vector<int> scores;
  for (size_t i = 0; i < total_rolls; i++) {
    int score = two_dice();
    scores.push_back(score);
    score_count.at(score) += 1;
  }

  // creates filename
  string filename = string("dice_") + argv[1] + ".dat";
  // cout << filename << endl;

  // redirects output to filename
  freopen(filename.c_str(), "w", stdout);

  // outputs results
  for (size_t i = 2; i <= 12; i++) {
    cout << i << "\t" << score_count.at(i) << "\n";
  }

  // returns successfully
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
  return dice_roll;
}

int two_dice(void) {
  // returns the sum of two dice rolls
  int sum = dice() + dice();
  return sum;
}
