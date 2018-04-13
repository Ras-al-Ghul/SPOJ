// <http://code.cloudkaksha.org/algorithm/bit-magic/bitwise-sieve-of-eratosthenes>
// <http://zobayer.blogspot.in/2009/09/segmented-sieve.html>

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back

const int MAX = 86028121 + 5; // 5 as simple buffer
const int LIM = 86028121 + 1; // +1 because <LIM below, not <=

// MAX/(32*2) integer is 32 bits, skipping even numbers, so space needed is reduced
int flagArr[MAX>>6];

// check if bit is set
// (x>>1)&31 --> divide number by two and 'and' with 31
// 'and' with 31 is mod 32 - works for b^1,2,3.. for numbers expressed in base b
// get that bit --> shift 1 left that many times
#define ifComp(x) (flagArr[x>>6]&(1<<((x>>1)&31)))
// set bit
#define isComp(x) (flagArr[x>>6]|=(1<<((x>>1)&31)))

vector<int> primes;

int main(){
	primes.pb(0); // to force 1 based indexing
	primes.pb(2);
	for(int i=3; i<LIM; i+=2){
		if(!ifComp(i)){
			primes.pb(i);
			if(i>9276) // root of 86028121
				continue;
			// increment by 2*i - because i+i = 2i which is even, we need 3i, 5i, etc.
			// start from i*i because, up to i*(i-1) covered by previous numbers
			for(int j=i*i, k=i<<1; j<MAX; j+=k)
				isComp(j);
		}
	}
	int t, temp; scanf("%d", &t);
	while(t--){
		scanf("%d", &temp);
		printf("%d\n", primes[temp]);
	}
	return 0;
}