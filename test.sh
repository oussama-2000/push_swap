#!/bin/bash

# Clear the file first
> txt.txt

# You can change 100 to a smaller number like 20 if you want it to finish faster
for i in {1..500}; do
  # Generates 500 unique random numbers between 0 and 5000
  ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-1023, 60000), 100))))")
  
  # Run push_swap and count moves
  MOVES=$(./push_swap $ARG | wc -l)
  
  echo "Run $i: $MOVES moves"
  echo $MOVES >> txt.txt
done

# Calculate the average and find the Max/Min
echo "----------------"
awk '{ 
    total += $1; 
    count++; 
    if(max=="" || $1>max) max=$1; 
    if(min=="" || $1<min) min=$1; 
} END { 
    if (count > 0) 
        print "Average: " total/count "\nMax: " max "\nMin: " min; 
    else 
        print "No data"; 
}' txt.txt