#!/bin/bash 
#PBS -N getstart
#PBS -q bigmemtest
#PBS -l nodes=1:ppn=4:bigmemtest

cd /remote/bigmem11/daverio/getstart

mpirun -np 4 getStart -n 2 -m 2
