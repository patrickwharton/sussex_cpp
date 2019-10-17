#!/usr/bin/env bash
rm dice_rolls.txt
for i in {1..10}
do
  ./dice >> dice_rolls.txt
  echo "Rolled $1"
  sleep 1
done
