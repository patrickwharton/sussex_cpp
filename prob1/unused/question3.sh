#!/usr/bin/env bash
for i in 10000
do
  ./craps $i > craps.csv
done
echo "Preparing graphs..."
python3 question3.py
echo "Done!"
