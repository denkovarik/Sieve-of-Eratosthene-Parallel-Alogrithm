/**************************************************************************//**
* @file utilities.c
*
* @brief Source file for utility functions
*
******************************************************************************/
#include "utilities.h"


/**************************************************************************//**
* @author Dennis Kovarik
*
* @par Description:
* This function determines the number of digits in an integer. 
*
* @param[in] num - An int to determine the number of digits in.
*
* @returns the number of digits in the number as an int.
******************************************************************************/
int countDigits(int num)
{
    int count = 0;
    while (num != 0) 
    {
        num /= 10;
        ++count;
    }
    
    return count;
}


/**************************************************************************//**
* @author Dennis Kovarik
*
* @par Description:
* This function runs the sieve of Eratosthenes method to find all primes less
* than n. 
*
* @param[in] n - Int of the upper bound on the range of all integers to find
*                prime numbers for.
* @param[in,out] primeList - Array of boolean values of size n for marking each 
*                            number as prime or not.
*
* @returns none
******************************************************************************/
void findPrimes(int n, bool *primeList)
{
    int p = 2;

    while(p < n)
    {

#       pragma omp parallel for num_threads(8) default(none) \
            shared(primeList, n, p) schedule(static)
        for(int i = 2; i <= n / p; i++)
        {
            primeList[i*p] = false;
        }  
        
        // Find the first prime larger than p
        p++;
        while(p < n && !primeList[p]) 
            p++;
    }
}


/**************************************************************************//**
* @author Dennis Kovarik
*
* @par Description:
* This function prints the prime numbers less than n to the screen.
*
* @param[in] n - Int of the upper bound on the range of all integers to find
*                prime numbers for.
* @param[in] primeList - Array of boolean values of size n for marking each 
*                        each number as prime or not.
*
* @returns none
******************************************************************************/
void printList(bool *primeList, int n)
{
    int numDigitsN = 0;
    int numDigitsP = 0;
    int counter = 0;
    int numPrimes = 0;

    for(int i = 2; i < n; i++)
    {
        if(primeList[i])
            numPrimes += 1;
    }

    if(numPrimes > 0)
        numPrimes -= 1;

    printf("num primes: %d\n", numPrimes);

    numDigitsN = countDigits(numPrimes);

    // Display Primes
    counter = 0;
    for(int i = 2; i < n; i++)
    {
        if(primeList[i])
        {
            if(counter % 10 == 0)
            {
                numDigitsP = 1;

                if(counter > 0)
                {
                    numDigitsP = countDigits(counter);
                    printf("\n");
                }

                for(int i = 0; i < numDigitsN - numDigitsP; i++)
                    printf(" ");
                printf("%d: ", counter); 
            }

            printf("%d ", i);

            counter++; 
        }
    }
    printf("\n");
}
