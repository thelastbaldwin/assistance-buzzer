#!/bin/bash
# logs the date whenever a key is pressed.
# blocks other processes
# author: Steve Minor
# date: 12/18/15
echo "Press a or b to capture the date. Press any other key to quit";

while :
do
    # TASK 1
    read  -n 1 key
    timestamp=$(date +"%m/%d/%y %H:%M:%S")
    if [ "$key" = 'a' ]; then
        echo "on $timestamp" >> /media/PI/output.txt
    elif [ "$key" = 'b' ]; then
        echo "off $timestamp" >> /media/PI/output.txt
    else
        break
    fi
done
