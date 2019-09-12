#!/bin/bash
gcc ex2.c
./a.out &

pstree $!
sleep 1
pstree $!
sleep 1
pstree $!

rm ./a.out
