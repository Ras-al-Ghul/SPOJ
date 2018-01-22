#include <iostream>

using namespace std;

const int MAX = 64-1;

int main(){
	int p; scanf("%d", &p);
	long dp[11][MAX] = {};

	for(int i=1; i<=10; ++i)
		dp[i][0] = long(1);

	for(int i=1; i<MAX; ++i){
		for(int j=1; j<=10; ++j)
			dp[j][i] = dp[j][i-1] + dp[j-1][i];
	}

	while(p--){
		int count, n; scanf("%d %d", &count, &n);
		long ans = 0;

		if(n == 1){
			ans = long(10);
		}
		else{
			for(int i=1; i<=10; ++i)
				ans += (dp[i][n-2]*(10-i+1));
		}

		printf("%d %ld\n", count, ans);
	}

	return 0;
}