#!/usr/bin/env bash
rm question1.csv
echo "n,alpha,mean" | tee -a question1.csv
for i in {1..10000..2}
do
  # echo -n "Rolled "
  ./random $i | cat | tee -a question1.csv
  #sleep 1
done
echo "Preparing Graph..."
python3 question1.py
echo "Done!"
echo "Please proceed to question2 by typing ./question2.sh"
