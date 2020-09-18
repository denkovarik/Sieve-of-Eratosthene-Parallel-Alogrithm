/*-----------------------------------------------------------------------------
 * File:    main.c
 *
 * Author: Dennis Kovarik
 * Date: 9/19/2020
 * Class Assignment: CSC 510 Program 1
 * 
 * Purpose: Parallel program to find the consecutive prime numbers
 * less than n using the sieve of Eratosthenes algorithm. 
 *
 * Compile: gcc -g -Wall -fopenmp -o prime main.c utilities.c
 *   
 * Run:     ./prime
 *          ./prime <n>
 *              n: range for finding the prime numbers
 *
 *
 * Input:   none
 * Output:  all prime numbers less than n
 *
 * Notes:
 * 1.  This program can be run with 0, or 1 command line arguments
 * 2.  The first command line argument specifies n
 *
 *---------------------------------------------------------------------------*/
#include "utilities.h"


/**************************************************************************//**
* @author Dennis Kovarik
*
* @par Description:
* This is the main function which is the start of the program. It will run the
* sieve of Eratosthenes algorithm to find all prime numbers less than n. This 
* program can be run with 0, or 1 additional command line arguments. If no 
* arguments are passed in, then the program will default to finding all prime 
* numbers less than 1000. The 1st argument passed in specifies n, which is the 
* upperbound on range of numbers.
*
* @param[in] n - Int of the upper bound of all integers to find the consecutive 
*                prime numbers for.
*
* @returns 0 if the program executed correctly.
******************************************************************************/
int main(int argc, char **argv)
{
    int n = 1000;
    bool *primeList;
    double tot_time = 0.0, t0, t1;

    // Read command line arguments
    if(argc > 1)
    {
        n = strtol(argv[1], NULL, 10);
    }

    primeList = (bool *) malloc ((n)*sizeof(bool));

    // Init prime list to true
    for(int i = 0; i < n; i++)
    {
        primeList[i] = true;
    }

    t0 = omp_get_wtime();
    findPrimes(n, primeList);
    t1 = omp_get_wtime();
    tot_time = t1 - t0;

    printList(primeList, n);

    printf("Elapsed time = %f ms\n", tot_time);

    free(primeList);
}
