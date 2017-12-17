#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int count_set_bits(long n){
	int count = 0;
	while(n){
		count += (n & 1);
		n>>=1;
	}
	return count;
}

int main(){
	int c;
	scanf("%d", &c);
	while(c--){
		int n;
		scanf("%d", &n);
		long cost[n][n];
		for(long i=0; i<n; ++i){
			for(long j=0; j<n; ++j){
				scanf("%ld", &cost[i][j]);
			}
		}
		
		long dp[long(pow(2,n))+1][n+1];
		for(long i=0; i<pow(2,n); ++i)
			dp[i] = LONG_MAX;
		dp[0] = 0;
		
		long ans = 0;
		for(long i=0; i<pow(2,n); ++i){
			int x = count_set_bits(i);
			for(long j=0; j<n; ++j){
				if((i&(1<<j)) == 0){
					if(cost[x][j]){
						++ans;
						dp[i|(1<<j)] = min(dp[i|(1<<j)], dp[i]+cost[x][j]);
					}
				}
			}
		}
		printf("%ld\n", ans);
	}
	return 0;
}