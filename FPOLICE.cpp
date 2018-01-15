#include <iostream>
#include <climits>

using namespace std;

int main(){
	int ncases;
	scanf("%d", &ncases);
	int n, t;
	while(ncases--){
		scanf("%d %d", &n, &t);
		int time[n][n], tolls[n][n];
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				scanf("%d", &time[i][j]);
			}
		}
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				scanf("%d", &tolls[i][j]);
			}
		}

		// source vertex also set with this
		int dp[n][t+1] = {};

		for(int i=1; i<n; ++i){
			dp[i][0] = INT_MAX - 2000;
		}

		int mintime = 0;
		for(int i=1; i<=t; ++i){
			for(int j=1; j<n; ++j){
				dp[j][i] = dp[j][i-1];
				for(int k=0; k<n; ++k){
					if(time[k][j] > i or k==j)
						continue;

					dp[j][i] = min(dp[j][i], dp[k][i-time[k][j]] + tolls[k][j]);
				}
				// for(int x=0;x<n;++x){
				// 	for(int y=0;y<=t;++y){
				// 		printf("%d ", dp[x][y]);
				// 	}
				// 	printf("\n");
				// }
				// printf("\n");
			}
			
			if(dp[n-1][i] != dp[n-1][i-1])
				mintime = max(i,mintime);
		}
		if(mintime != 0)
			printf("%d %d\n", dp[n-1][mintime], mintime);
		else
			printf("-1\n");
	}

	return 0;
}