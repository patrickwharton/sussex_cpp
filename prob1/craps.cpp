#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int two_dice();

int main(int argc, char const *argv[]) {
  // collect number of games to simulate from command line input
  int number_of_games;
  if (argc == 2) {
    // obtain roll count from command line input
    number_of_games = atoi(argv[1]);

    // check input is valid
    if (!(number_of_games > 0)) {
      cout << "invalid input\n" << "please use inputs in the form \"./craps <integer>\"\n";
      return 1;
    }
  }
  else {
    cout << "invalid input\n" << "please use inputs in the form \"./craps <integer>\"\n";
    return 1;
  }

  // initialise win/loss totals
  int total_wins = 0;
  int total_losses = 0;

  // initialise random seed
  srand(time(NULL));

  // initialise win/loss vectors to count rolls before result
  vector<int> win_rolls;
  vector<int> loss_rolls;

  // play craps
  for (size_t i = 0; i < number_of_games; i++){
    // initialise per-game variables
    int score = 0;
    int number_of_dice_rolls = 0;
    size_t win = 0;
    size_t loss = 0;
    int point = 0;

    // roll two_dice until win or loss
    do {
      score = two_dice();
      number_of_dice_rolls++;
      if (number_of_dice_rolls == 1) {
        // first roll loss cases
        if (score == 2 || score == 3 || score == 12) {
          loss = 1;
        }
        // first roll win cases
        else if (score == 7 || score == 11) {
          win = 1;
        }
        // first role
        else {
          point = score;
        }
      }
      else {
        // future roll win case
        if (score == point) {
          win = 1;
        }
        // future roll loss case
        else if (score == 7) {
          loss = 1;
        }
      }
    } while ((win == 0) && (loss == 0));

    // game finished
    // add total to win/loss counts
    if (win == 1) {
      total_wins++;
      // add number of dice rolls to win_rolls vector
      if (win_rolls.size() > number_of_dice_rolls) {
        // if the vector is big enough already just increment
        win_rolls.at(number_of_dice_rolls) += 1;
      }
      else {
        // else add the appropriate number of extra elements to the vector
        // before then incrementing
        for (size_t j = win_rolls.size(); j <= number_of_dice_rolls; j++) {
          win_rolls.push_back(0);
        }
        win_rolls.at(number_of_dice_rolls) += 1;
      }
    }
    else if (loss == 1) {
      total_losses++;
      // add number of dice rolls to loss_rolls vector
      if (loss_rolls.size() > number_of_dice_rolls) {
        // if the vector is big enough already just increment
        loss_rolls.at(number_of_dice_rolls) += 1;
      }
      else {
        // else add the appropriate number of extra elements to the vector
        // before then incrementing
        for (size_t j = loss_rolls.size(); j <= number_of_dice_rolls; j++) {
          loss_rolls.push_back(0);
        }
        loss_rolls.at(number_of_dice_rolls) += 1;
      }
    }
    else {
      cout << "how tf did you get here\n";
      return 1;
    }
  }
  // csv output with headers
  cout << "count,dice_rolls,Result\n";
  for (int i = 1; i < win_rolls.size(); i++) {
    cout << win_rolls.at(i) << "," << i << ",Win\n";
  }
  for (int i = 1; i < loss_rolls.size(); i++) {
    cout << loss_rolls.at(i) << "," << i << ",Loss\n";
  }
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
  return dice_roll;
}

int two_dice(void) {
  // returns the sum of two dice rolls
  int sum = dice() + dice();
  return sum;
}
