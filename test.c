#include "utilities.h"

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
