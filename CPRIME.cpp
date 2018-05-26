#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>

#define pb push_back

using namespace std;

// MAXPRIME value up to which you need primes
const int MAXN = 100000005;

int main(){
	vector<int> primes; primes.pb(2);
	// set to zero
	bitset <MAXN/2+1> sieve;
	int i, j, ip;
	// outer loop till square root of MAXPRIME value you want
	for(i=3; i<=(sqrt(MAXN)); i+=2){
		// no even numbers, so 1 will be 3, 2 will be 5, 3 will be 7
		// i.e. 3/2, 5/2, 7/2...
		if(not sieve[i/2]){
			primes.pb(i);
			// start from square of number, and we want j, j+3i, j+5i
			// because no even numbers
			for(j=i*i; j<MAXN; j+=(2*i))
				sieve[j/2] = 1;
		}
	}
	// outer loop till MAXPRIME value
	for(; i<MAXN; i+=2)
		// see relevant index
		if(not sieve[i/2])
			primes.pb(i);
	
	while(scanf("%d", &ip)==1){
		if(ip==0)
			break;
		// <=, hence upper_bound
		int ans = upper_bound(primes.begin(), primes.end(), ip) - primes.begin();
		double num = (abs(ans - (ip/log(ip))) * 100)/ans;
		printf("%.1lf\n", num);
	}
	return 0;
}