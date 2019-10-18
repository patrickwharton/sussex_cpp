#!/usr/bin/env bash
rm dice_rolls.txt
for i in {1..600}
do
  echo -n "Rolled "
  ./dice | cat | tee -a dice_rolls.txt
  sleep 1
done
