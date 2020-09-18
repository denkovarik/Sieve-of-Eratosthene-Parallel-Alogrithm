/**************************************************************************//**
* @file test.c
*
* @brief Source file for utility functions
*
******************************************************************************/
#include "utilities.h"


/**************************************************************************//**
* @author Dennis Kovarik
*
* @par Description:
* This is the main function which is the start of the test program. This 
* program test the functin findAllPrimes() on its ability to find all primes 
* less than n. This will then be compared against the file primes-to-100k.txt
* which contains prime numbers less than 1000000. 
*
* @returns 0 if the program executed correctly.
******************************************************************************/
int main()
{
    int num, nextPrime, n = 1000000;
    bool *primeList;
    FILE *fptr;
    int testPassed = 1;

    // Open file
    if ((fptr = fopen("primes-to-100k.txt","r")) == NULL){
        printf("Error! opening file\n");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    // Allocate space for prime list
    primeList = (bool *) malloc ((n)*sizeof(bool));

    // Init prime list to true
    for(int i = 0; i < n; i++)
    {
        primeList[i] = true;
    }

    findPrimes(n, primeList); 

    int j = 2;

    for(int i = 0; i < 9592; i++)
    {
        fscanf(fptr,"%d", &num);

        while(j < n && !primeList[j])
            j += 1;

        if(num != j)
        {
            printf("%d not equal to %d\n", num, j);
            testPassed = 0;
        }

        j += 1;
    }

    if(testPassed == 1)
        printf("All Tests Passed :)\n");
    else
        printf("Error in function findPrimes()\n");
   
    fclose(fptr); 
    free(primeList);
  
   return 0;
}
