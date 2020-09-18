#include "utilities.h"


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
