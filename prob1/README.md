# Intro to C++, Problem Sheet 1
Week 5, 2019

Patrick Wharton

## List of Files
Report.pdf

README.md

### Question 1
random.cpp

random

question1.sh

question1.py

random.csv

### Question 2
dice.cpp

dice

question2.sh

question2.py

dice_100.dat

dice_500.dat

dice_1000.dat

dice_10000.dat

dice_50000.dat

### Question 3
craps.cpp

craps

question3.sh

question3.py

craps.csv


## Question 1
To run my attempt at question1 from start to finish (random number gen), please execute this command in a bash terminal:

  ./question1.sh

(may require "chmod +x question1.sh")

This will invoke my C++ script (random.cpp), which was compiled to an executable file called "random", 5000 times and outputs the number of random numbers generated, the variance, and the mean of those numbers into a csv file (random.csv). It then invokes a python script to graph the results (question1.py)

If using question1.sh, when recompiling, please ensure the output is called "random", i.e. "g++ random.cpp -o random"

To use separately, the correct syntax for the random executable is:

  ./random <integer>

where <integer> is the number of random numbers to generate (and then calculate the mean and variance from)
while the correct syntax for question1.py is:
  python3 question1.py
when in the same directory as the outputs from random.cpp


## Question 2
To run my attempt at question2 from start to finish (sum of two dice rolls), please execute this command in a bash terminal:

  ./question2.sh

(may require "chmod +x question2.sh")

This will invoke my C++ script (dice.cpp) which was compiled to an executable file called "dice", and this outputs the frequency of the sum of 2 dice rolls to files called dice_N.dat, where N is the number of dice rolls. This then invokes a python script to plot the results.

If using question2.sh when recompiling, please ensure the output is called "dice", i.e. "g++ dice.cpp -o dice"

To use separately, the correct syntax for the dice executable is:

  ./dice <integer>

where <integer> is the number of trials (in this case: 100, 500, 1000, 10000, 50000)
while the correct syntax for question2.py is:
  python3 question2.py
when in the same directory as the outputs from dice.cpp (will only work for values of <integer> required by the problem sheet)


## Question 3
To run my attempt at question3 from start to finish (multiple craps games simulator), please execute this command in a bash terminal:

  ./question3.sh

(may require "chmod +x question3.sh")

This will invoke my C++ script (craps.cpp) using an input parameter of 10000, compiled into an executable file, "craps", which outputs the results of a number of games of craps, in this case 10000. This then invokes a python script plotting the results to answer the questions at the tail end of the problem sheet.

If using question3.sh when recompiling, please ensure the output is called "dice", i.e. "g++ craps.cpp -o craps"

To use separately, the correct syntax for the dice executable is:
  ./craps <integer> > craps.csv
where <integer> is the number of trials (in this case, 10000)
while the correct syntax for question3.py is:
  python3 question3.py
when in the same directory as the outputs from craps.cpp
