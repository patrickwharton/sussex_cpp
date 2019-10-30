#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>


using namespace std;

int main(int argc, char const *argv[]) {
  // initialise random number seed
  srand(time(NULL));

  // ask how many random number are needed if not stated in command line
  int N;
  if (argc == 2) {
    N = atoi(argv[1]);
    if (!(N > 0)) {
      cout << "invalid input\n";
      return 1;
    }
  }
  else {
    cout << "How many random numbers would you like to generate?" << '\n';
    cin >> N;
  }

  // initialises a vector and stores N random doubles between 0 and 1
  vector<double> random_numbers;
  for (size_t i = 0; i < N; i++) {
    double number_to_add = rand() / (double)RAND_MAX;
    random_numbers.push_back(number_to_add);
  }

  // calculates sum of randomly generated numbers
  double sum = 0;
  for (auto i = random_numbers.begin(); i != random_numbers.end(); i++) {
    sum += *i;
  }

  // calculate mean of random_numbers
  double mean = sum / N;

  // calculates sum of the squared differences
  // before divided to get the variance outside the loop
  double variance;
  for (auto i = random_numbers.begin(); i != random_numbers.end(); i++) {
    variance += pow((*i - mean), 2);
  }
  variance /= N;

  cout << N << "," << variance << "," << mean << endl;

  return 0;
}
