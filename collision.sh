#!/bin/bash

date > "collisions.txt"

while IFS= read -r x
do
    echo "$x" | ./main | tee -a "collisions.txt"
done < word-list-extra-large.txt
