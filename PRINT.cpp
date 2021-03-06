// double sieve of eratosthenes
// one is within 0 to sqrt(max possible)
// other is lower to upper
// check edge cases - lower bound, upper bound
// here (upper bound - lower bound) was small hence storing an entire sieve was possible
// check last line \n needed or not
// prime numbers sqrt bounds
// manage indexes properly, here lower bound was 2 instead of 1

// c++ can only fill array with {0}, otherwise have to use other syntax - if to be filled by other values

// seems that associative array (dict) is faster in python than large bool array

// time complexity - largest number in first sieve ~ 32000
// for all primes in first sieve, we eliminate numbers in the second sieve
// max numbers in the second sieve = (upper - lower) = 100001
// so time complexity - O(100001 * ( (1/2) + (1/3).. + (1/32000) ) ) ~ O(260000)

// what i've done - start by first multiple of prime > lower bound
// this is called segmented sieve

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

#define ll long long
#define UB 2147483647

using namespace std;

int main(){
	int numoftestcases;
	ll low, high;

	ll size = sqrt(UB);
	size += 1;
	bool sieve[size] = {0};

	for(ll i=2; i < sqrt(size) + 1; i++){
		if(sieve[i-2] == 0){
			for(ll j = 2; j*i < size+2; j++){
				sieve[(j*i) - 2] = 1;
			}
		}
	}

	scanf("%d", &numoftestcases);
	while(numoftestcases--){
		scanf("%lld %lld", &low, &high);
		
		bool boundedsieve[high - low + 1] = {0};

		ll i=0;
		ll upper = sqrt(high)+1;

		while(i+2 <= upper){
			if(sieve[i] == 0){
				ll val = i+2;
				ll j=1;
				if(val < low){
					j = low/val;
					if((low%val) != 0){
						j += 1;
					}
				}
				else{
					j += 1;
				}
				for(; val*j <= high; j++){
					boundedsieve[(val*j) - low] = 1;
				}
			}
			i++;
		}
		for(i=0; i<high-low+1; i++){
			if(boundedsieve[i] == 0)
				printf("%lld\n", i+low);
		}
	}
	return 0;
}