// copied optimized prime factorization from AMR10C

// idea is to find number of positive divisors for each number using sieve technique
// then for each of those numbers, have to find if it is expressible as p*q where p and q are distinct primes
// this happens only if prime factorization contains exactly two distinct primes

#include <iostream>
#include <vector>

// Maximum number possible for which you need prime factorization
#define MAXN 250000

using namespace std;

int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
bool getFactorization(int x)
{
    int oldx;
    oldx = spf[x];
    x = x / spf[x];

    // we need x to become 1 after second step
    // i.e. prime factorization of x should consist of exactly two distinct primes
    // only then x = p*q

    // if x == 1 after 1 step of prime factorization, that means x is prime
    // cannot be expressed as x = p*q where p and q are primes - first condition
    // second condition ensures prime factorization will consist of exactly two primes
    // last condition checks distinctness
    if(x != 1 and x/spf[x] == 1 and spf[x] != oldx)
    	return true;
    return false;
}

int main(){
    sieve();
    
    // extension of sieve to find number of positive divisors
    int arr[1000001] = {};
	for(int i=1; i<=1000000; ++i)
		for(int j=1; j*i<=1000000; ++j)
			arr[j*i]+=1;

	int count = 0;
	for(int i=4; i<1000001; ++i){
		bool ans = getFactorization(arr[i]);
	    if(ans){
	    	++count;
	    	if(count == 9){
	    		printf("%d\n", i);
	    		count = 0;
	    	}
	    }
	}
	return 0;
}