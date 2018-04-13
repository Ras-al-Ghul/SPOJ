#include <iostream>
#include <vector>
#include <cmath>

#define pb push_back

using namespace std;

const int MAXP = 7994;

int main(){
	vector<int> primes; primes.pb(1);
	// sieve
	bool arr[MAXP] = {}; arr[1] = 1;
	for(int i=2; i<MAXP; ++i){
		if(not arr[i]){
			for(int j=2; i*j < MAXP; ++j)
				arr[i*j] = 1;
		}
	}
	// checking sum of perfect squares
	// test till square root of that prime
	int temp;
	for(int i=2; i<MAXP; ++i){
		if(not arr[i]){
			for(int j=1; j<=int(sqrt(i)); ++j){
				temp = i - (j*j); temp = int(sqrt(temp)); temp *= temp;
				if((j*j) + temp == i){
					primes.pb(i); break;
				}
			}
		}
	}

	// 7993 is largest such prime
	// 0 is 1 as largest number 1 is 2 and 2 is 3
	int dp[MAXP][3] = {}, k;
	// include same number, previous biggest also
	dp[1][0] = 1; dp[1][1] = 1; dp[1][2] = 1;
	dp[2][0] = 1; dp[2][1] = 2; dp[2][2] = 2;
	dp[3][0] = 1; dp[3][1] = 2; dp[3][2] = 3;
	for(int i=4; i<MAXP; ++i){
		dp[i][0] = 1;
		for(int j=1; j<3; ++j){
			for(k=i-(j+1); k>0; k-=(j+1)){
				dp[i][j] += dp[k][j-1];
			}
			// if it is 0, then one way where everything is (j+1)
			if(k == 0)
				dp[i][j] += 1;
			// include same number, previous biggest also
			// eg (5,3) += (5,2) note that it also includes (5,1) as (5,2) includes it
			dp[i][j] += dp[i][j-1];
		}
	}
	int t; scanf("%d", &t);
	while(t--){
		int a, b; scanf("%d %d", &a, &b);
		printf("%d\n", dp[primes[a]][b-1]);
	}
	return 0;
}