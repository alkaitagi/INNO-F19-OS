#!/bin/bash
gcc ex1.c 
seq 10 | xargs -Iz ./a.out

rm ./a.out
