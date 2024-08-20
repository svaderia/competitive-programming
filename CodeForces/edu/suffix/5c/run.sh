#!/bin/bash

# Initialize counter
counter=0
max_c=100

# Loop until the outputs differ or counter reaches 1000
while [ $counter -lt $max_c ]; do
    # Increment the counter
    ((counter++))

    # Generate a test case
    ./generate_test $counter > test

    # Run the solution and correct programs
    ./solution < test > t1
    ./correct < test > t2

    # Check if outputs differ
    if ! diff t1 t2 > /dev/null; then
        echo "Mismatch found on iteration $counter"
        echo "Test case saved in 'test'"
        exit 1
    fi
done

echo "No differences found after 1000 iterations"

