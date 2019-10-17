#!/usr/bin/env bash
while read line; do
  ./dice_test.sh $line >> dice.txt
done < $1
