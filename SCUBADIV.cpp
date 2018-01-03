// initially thought that weight was part of dp state
// that was a very silly thing to do
// turns out index is part of the dp state
// which is logical
// sometimes if you just cross size limit of 3D array, it gives segfault

#include <iostream>
#include <cstring>
#include <climits>

#define tmax 25
#define amax 80
#define nmax 1001

const int INF = 0x3f3f3f3f;

using namespace std;

int t, a;
int n;

int recurse(int arr[][3], int oxy, int nitro, int cur, int dp[][amax][nmax]){
	if(oxy<=0 and nitro<=0){
		return 0;
	}
	if(cur == n){
		return INF;
	}
	if(oxy<0)
		oxy = 0;
	if(nitro<0)
		nitro = 0;
	if(dp[oxy][nitro][cur] != 0)
		return dp[oxy][nitro][cur];
	int ans = min(recurse(arr,oxy-arr[cur][0],nitro-arr[cur][1],cur+1,dp)+arr[cur][2],
				  recurse(arr,oxy,nitro,cur+1,dp));
	return (dp[oxy][nitro][cur] = ans);
}

int main(){
	int c;
	scanf("%d", &c);
	while(c--){
		scanf("%d %d", &t, &a);
		scanf("%d", &n);
		int arr[n][3];
		int dp[tmax][amax][nmax] = {};
		for(int i=0; i<n; ++i){
			scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
		}
		printf("%d\n", recurse(arr, t, a, 0, dp));
	}
	return 0;
}