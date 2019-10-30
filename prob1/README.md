# Intro to C++, Problem Sheet 1
Week 5, 2019
Patrick Wharton

Most results and comments will be outputted to the console (stdout), except where explicitly noted.

## Question 1
To see my attempt at question1 (random number gen), please execute this command in a bash terminal:
  ./question1.sh
(may require "chmod +x question1.sh")

This will invoke my C++ script (random.cpp) which was compiled to an executable file called "random", and this outputs the number of random numbers generated, the variance, and the mean of those numbers into a csv file (question1.csv). It then invokes a python script to graph the results (question1.py)

When recompiling, please ensure the output is called "random", i.e. "g++ random.cpp -o random", if using question1.sh

To use separately, the correct syntax for the random executable is:
  ./random <integer>
where <integer> is the number of random numbers to generate (and then calculate the mean and variance from)
while the correct syntax for question1.py is:
  python3 question1.py
when in the same directory as the outputs from random.cpp


## Question 2
To see my attempt at question2 (sum of two dice rolls), please execute this command in a bash terminal:
  ./question2.sh
(may require "chmod +x question2.sh")

This will invoke my C++ script (dice.cpp) which was compiled to an executable file called "dice", and this outputs the frequency of the sum of 2 dice rolls to files called dice_N.dat, where N is the number of dice rolls. This then invokes a python script to plot the results.

When recompiling, please ensure the output is called "dice", i.e. "g++ dice.cpp -o dice", if using question2.sh

To use separately, the correct syntax for the dice executable is:
  ./dice <integer>
where <integer> is the number of trials (in this case: 100, 500, 1000, 10000, 50000)
while the correct syntax for question2.py is:
  python3 question2.py
when in the same directory as the outputs from dice.cpp (will only work for values of <integer> required by the problem sheet)


## Question 3
