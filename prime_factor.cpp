#include<iostream>
#include<cstdio>
#include<math.h>
#define SIZE 100001
using namespace std;
long pvalues[SIZE], pflags[SIZE], input;
long List[SIZE];  // saves the List
long listSize;   // saves the size of List
bool isNegative;

void prime(void)
{
  long i,j;
  pflags[0]=1;
  pflags[1]=1;
  for(i=2;i<=sqrt(SIZE);i++)  // prime generate part
    if(pflags[i]==0)
      for(j=2;j*i<SIZE;j++)
        pflags[i*j]=1;
  j=0;
  for(i=0; i<SIZE; i++) {
    if(pflags[i]==0) pvalues[j++]=i;
  }     
}

void primeFactorize( long n )
{
    listSize = 0;   // Initially the List is empty, we denote that size = 0
    long sqrtN = long( sqrt(n) ); // find the sqrt of the number
	for( long i = 0; i <= sqrtN; i++ ) { // we check up to the sqrt
		if(pflags[i]==0)
			if( n % i == 0 ) { // n is multiple of prime[i]
            // So, we continue dividing n by prime[i] as long as possible
				while( n % i == 0 ) {
					n /= i; // we have divided n by prime[i]
					List[listSize] = i; // added the ith prime in the list
                listSize++; // added a prime, so, size should be increased
            }
            // we can add some optimization by updating sqrtN here, since n
            // is decreased. think why it's important and how it can be added
        }
    }
    if( n > 1 )
    {
        // n is greater than 1, so we are sure that this n is a prime
        List[listSize] = n; // added n (the prime) in the list
        listSize++; // increased the size of the list
    }
}


/*void primeFactorize( long n )
{
    listSize = 0;   // Initially the List is empty, we denote that size = 0
    long sqrtN = long( sqrt(n) ); // find the sqrt of the number
    for( long i = 0; pvalues[i] <= sqrtN; i++ ) { // we check up to the sqrt
        if( n % pvalues[i] == 0 ) { // n is multiple of prime[i]
            // So, we continue dividing n by prime[i] as long as possible
            while( n % pvalues[i] == 0 ) {
                n /= pvalues[i]; // we have divided n by prime[i]
                List[listSize] = pvalues[i]; // added the ith prime in the list
                listSize++; // added a prime, so, size should be increased
            }
            // we can add some optimization by updating sqrtN here, since n
            // is decreased. think why it's important and how it can be added
        }
    }
    if( n > 1 )
    {
        // n is greater than 1, so we are sure that this n is a prime
        List[listSize] = n; // added n (the prime) in the list
        listSize++; // increased the size of the list
    }
}*/

int main(void)
{
    prime();    
    printf("\nEnter number to factorize: ");
    while(scanf_s("%ld",&input),input)
    {
		  isNegative = false;
          if(input == 1)
             printf("1 = 1\n");
          else if(input == -1)
             printf("\r-1 = -1 x 1\n");
          else
            {
                if(input < 0)
                {
                   isNegative = true;
                   input = abs(input);
                }
				primeFactorize( input );
                printf("The number %ld has the following factors: ", input);
                  for( long i = 0; i < listSize; i++ ) // traverse the List array
                  {
			              if(i==0)
                        {
                            if(isNegative)
                                printf("-%ld", List[i]);
                            else
                                printf("%ld", List[i]);
                        }
                       else
                            printf(" x %ld", List[i]);
	              }
			}
    printf("\nEnter number to factorize: ");
	}
    return 0;
}