// dp[vertices][time] stores cost(tolls)
// dp[j][i] = min(dp[j][i], dp[k][i-time[k][j]] + tolls[k][j])
// similarities to:
// Floyd-Warshall - there, outermostloop i is over 1 to n - shortest path
// including vertices 1 to i in iteration i - and in each iteration,
// iterate over all possible pairs - here too we do iterate over all possible
// pairs, but outermostloop is over all times
// Subset Sum - there inner loop is for all possible sums upto desired sum,
// outerloop over all indices of array - store number of ways sum can be
// constructed in dp
// Knapsack - there inner loop is over all weights, outerloop over indices
// of array, store maximum reward in dp
// contrast with RENT - job scheduling
// very important assumption is that we won't get from point a to point b
// in 0 time, it will always be positive, else this approach won't work
// From the assumption before {i!=j => distance[i][j] !=0} the subproblem
// size is guaranteed to be less than the original problem size, giving a
// finite recursion

// other approach - DFS with backtracking and branch and bound - may time out
// other approach - Djikstra inspired
// <https://stackoverflow.com/questions/10640983/ideas-for-a-spoj-fisher>
// <https://ideone.com/H8UUMf> - can also see Brian Bi - T3nsor's code
// go through ROADS
// priority_queue will hold pair<tolluptillnow, <node i, timetovisiti>>
// distance will be 2D - dist[node i][time t]
// for all neighbours of i will be replaced by all other nodes except i
// if((time to visit i) + (i to j time) < maxtime)
// 	  if(cost to visit j from i + cost to visit i)
// 		  change dist and add this to priority_queue

#include <iostream>
#include <climits>

using namespace std;

int main(){
	int n, t;
	while(true){
		scanf("%d %d", &n, &t);
		if(n==0 and t==0)
			break;
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
			// to prevent overflow to the subtract
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

		printf("%d %d\n", dp[n-1][mintime], mintime);
	}

	return 0;
}