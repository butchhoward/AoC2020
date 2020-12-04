#!/usr/bin/env bash

if [ ! -x "./solve" ]; then
    echo "Build first, then solve."
    exit 1
fi

for d in 0{1..9} {1..2}{1..5} 
do 
    f="./data/day${d}_data.txt"
    if [ -r "${f}" ]; then
        ./solve "${d}" "${f}"
    fi
done
