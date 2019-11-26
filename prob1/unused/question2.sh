#!/usr/bin/env bash
for i in 100 500 1000 10000 50000
do
  ./dice $i
done
echo "Preparing graphs..."
python3 question2.py
echo "Done!"
echo "Please proceed to question3 by typing ./question3.sh"
