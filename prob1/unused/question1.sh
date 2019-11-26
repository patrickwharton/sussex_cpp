#!/usr/bin/env bash
echo "Running..."
echo "n,alpha,mean" > random.csv
for i in {1..10000..2}
do
  # echo -n "Rolled "
  ./random $i >> random.csv
  #sleep 1
done
echo "Preparing Graph..."
python3 question1.py
echo "Done!"
echo "Please proceed to question2 by typing ./question2.sh"
