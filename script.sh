#!/usr/bin/bash

fold=$(ls | wc -l)
let "suf = $fold - 2"
mkdir day$suf
mkdir day$suf/puzzle1
mkdir day$suf/puzzle2
cp Makefile day$suf/puzzle1/Makefile
cp Makefile day$suf/puzzle2/Makefile
acod > input.txt
cp input.txt day$suf/puzzle1/input.txt
cp input.txt day$suf/puzzle2/input.txt
echo "solution" >> day$suf/puzzle1/.gitignore
