#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]) {
  // initialise random number seed
  srand(time(NULL));

  // ask how many random number are needed if not stated in command line
  int N;
  if (argc == 2) {
    N = atoi(argv[1]);
    // add error handler for non int input
  }
  else {
    N;
    cout << "How many random numbers would you like to generate?" << '\n';
    cin >> N;
    cout << N << "\n";
  }
  // generate N random numbers and store in array called random_number
  double random_number[N];
  for (int i = 0; i < N; i++) {
    random_number[i] = rand() / (double)RAND_MAX;
    cout << random_number[i] << "\n";
  }


  return 0;
}
