#!/bin/bash

# Extract all numbers and sort them
grep -oE '[0-9]+' collisions.txt | sort | uniq -d
