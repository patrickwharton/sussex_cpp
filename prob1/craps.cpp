

int number_of_games = atoi(argv[1]);

for (i = 0; i < number_of_games; i++){
  int score = 0;
  int number_of_dice_rolls = 0;
  size_t win = 0;
  size_t loss = 0;
  int point = 0;
  do {
    score = two_dice();
    number_of_dice_rolls++;
    if (number_of_dice_rolls == 1) {
      if (score == 2 || score == 3 || score == 12) {
        loss = 1;
      }
      else if (score == 7 || score == 11) {
        win = 1;
      }
      else {
        point = score;
      }
    }
    else {
      if (score == point) {
        win = 1;
      }
      else if (score == 7) {
        loss = 1;
      }
    }
  } while ((win == 0) && (loss == 0));
}

// use a vector to store wins / losses, and two more vectors
// to store number of throws before winning/losing respectively
