/**************************************************************************//**
* @file utilities.h
*
* Author: Dennis Kovarik
* Date: 9/19/2020
* Class Assignment: CSC 510 Program 1
*
* @brief Header file for the utility functions.
*
******************************************************************************/
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
