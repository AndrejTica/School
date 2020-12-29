#!/bin/bash
e=5
phi=72
for d in {1..100}
do
	
	if [ $(( ($d * $e) % $phi )) -eq 1 ] 
	then
		echo -n "$d "
	fi
#	echo $remainder
done 

