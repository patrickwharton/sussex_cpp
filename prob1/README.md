# Intro to C++, Problem Sheet 1
Week 5, 2019

More detail, including the scripts and python files used to generate the data used in the report can be found in the unused subdirectory, with an appropriately more in depth README

## Question 1
To recompile please run,

```bash
g++ random.cpp -o random
```

To use, the correct syntax for the random executable is:

```bash
  ./random <integer>
```

where <integer> is the number of random numbers to generate (and then calculate the mean and variance from)


## Question 2
To recompile, please run

```bash
 g++ dice.cpp -o dice
```

To use, the correct syntax for the dice executable is:

```bash
  ./dice <integer>
```

where <integer> is the number of trials (in this case, the 5 values used were: 100, 500, 1000, 10000, 50000)


## Question 3
To recompile, please run

```bash
g++ craps.cpp -o craps
```

To use, the correct syntax for the craps executable is:

```bash
  ./craps <integer>
```

where <integer> is the number of trials (in this case, 10000)
To save the data outputted, please pipe to a .csv file (or similar) by

```bash
./craps <integer> > <filename>
```

where <filename> in this case could be

```bash
craps.csv
```
