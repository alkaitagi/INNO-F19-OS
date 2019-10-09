#!/bin/bash
gcc ex2.c
./a.out &
vmstat 1
