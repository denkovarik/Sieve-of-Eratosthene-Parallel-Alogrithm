#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

int countDigits(int num);
void findPrimes(int n, bool *primeList);
void printList(bool *primeList, int n);
