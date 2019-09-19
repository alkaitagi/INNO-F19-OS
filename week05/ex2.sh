#!/bin/bash
touch ex2

while true
do
    if ! ln ex2 ex2.lock
    then
        sleep 0.1
    else
        for i in {1..10}
        do
            NUM=$(tail -n 1 ex2)
            ((NUM++))

            echo $NUM >> ex2
        done
        
        rm ex2.lock
        break
    fi
done
