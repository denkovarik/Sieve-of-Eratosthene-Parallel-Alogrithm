# Makefile for program

main:
	gcc -g -Wall -fopenmp -o prime main.c utilities.c

test:
	gcc test.c -o runTest utilities.c

clean:
	rm prime runTest
