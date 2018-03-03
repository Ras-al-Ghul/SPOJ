// beautiful, must do problem
// we want is path with least difference between its highest and lowest elevations
// constraint that 0<=any elevation<=110 is not used at all - no information in question is useless
// binary search over elevation difference + dfs

// another thing is that min possible max height diff = abs(arr[0][0]-arr[n-1][n-1])
// so maxmins = arr[0][0]<arr[n-1][n-1]? arr[0][0]:arr[n-1][n-1];

#include <iostream>
#include <stack>

#define mp make_pair

using namespace std;

const int MAX = 100;
int arr[MAX][MAX] = {};
int n, mins, maxs;

bool findpath(int mid){
	// dfs makes sense
	bool visited[n][n] = {};
	bool flag = false;
	stack<pair<int, int> > dfs;
	if(arr[0][0] >= mins and arr[0][0] <= maxs)
		dfs.push(mp(0,0));
	else
		return flag;
	int cr, cc;
	while(not dfs.empty()){
		cr = dfs.top().first; cc = dfs.top().second;
		dfs.pop();
		if(not visited[cr][cc]){
			visited[cr][cc] = true;
			if(cr == n-1 and cc == n-1){
				flag = true; break;
			}
			// add all neighbours to stack
			// up
			if(cr-1>=0 and (not visited[cr-1][cc]) and (arr[cr-1][cc] >= mins and arr[cr-1][cc] <= maxs))
				dfs.push(mp(cr-1,cc));
			// down
			if(cr+1<n and (not visited[cr+1][cc]) and (arr[cr+1][cc] >= mins and arr[cr+1][cc] <= maxs))
				dfs.push(mp(cr+1,cc));
			// left
			if(cc-1>=0 and (not visited[cr][cc-1]) and (arr[cr][cc-1] >= mins and arr[cr][cc-1] <= maxs))
				dfs.push(mp(cr,cc-1));
			// right
			if(cc+1<n and (not visited[cr][cc+1]) and (arr[cr][cc+1] >= mins and arr[cr][cc+1] <= maxs))
				dfs.push(mp(cr,cc+1));
		}
	}
	return flag;
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			scanf("%d", &arr[i][j]);

	int low, high = 110, mid;
	low = abs(arr[0][0]-arr[n-1][n-1]);

	int maxmins = arr[0][0] < arr[n-1][n-1]? arr[0][0]:arr[n-1][n-1];
	bool ans;
	while(low < high){
		mid = low + (high-low)/2;
		// look for path with max height diff = mid

		// now problem is we know what difference of height we can look for
		// but what is the lowest value/highest value - because difference is given by
		// highest val in arr - lowest val in arr which can be anything and
		// not just with maxmins as the lowest val - i.e. cannot do
		// arr[cr-1][cc] - maxmins <= mid
		// maxmins in fact gives upper bound on lowest val - hence
		// look for all such in range 0 to maxmins
		// hence do (arr[cr-1][cc] >= mins and arr[cr-1][cc] <= maxs)
		// set mins = i, maxs = i+mid
		// can even do from i = minval in arr instead of i = 0 as initial
		for(int i=0; i<=maxmins; ++i){
			mins = i; maxs = i+mid;
			ans = findpath(i);
			if(ans)
				break;
		}
		if(ans)
			high = mid;
		else
			low = mid+1;
	}
	printf("%d\n", high);
	return 0;
}
// the code below solves a slightly different problem
// what it looks for is the minimum max difference between two adjacent box heights given the grid
// when you look at ans[n-1][n-1], it will give min max difference in all paths from 0,0 to n-1,n-1
// source is hence initialized to 0
// a path from 0,0 to n-1,n-1 will exist which will have given difference as maximum between any two adjacent boxes
// the principle is similar to all pairs shortest path Floyd Warshall algorithm - O(n^3)

// but we want is path with least difference between its highest and lowest elevations

// that unfortunately cannot be solved using the Floyd Warshall principle
// what will you store? min max difference so far and lowest and highest encountered so far?
// say you have low 4-6 high diff 2 and 2-5 diff 3, if you store 4-6 diff 2
// and in next you get 1, now it will become 1-6 diff 5 whereas 1-5 diff 4 is better

// also constraint that 0<=any elevation<=110 is not used at all - no information in question is useless
// that hints at binary search over possible elevation differences

// #include <iostream>
// #include <cstring>
// #include <climits>

// using namespace std;

// int main(){
// 	int n; scanf("%d", &n);
// 	int arr[n][n];
// 	for(int i=0; i<n; ++i)
// 		for(int j=0; j<n; ++j)
// 			scanf("%d", &arr[i][j]);

// 	int ans[n][n];

// 	memset(ans, 'z', sizeof(ans[0][0])*n*n);

// 	ans[0][0] = 0;

// 	int cr, cl;
// 	// through first node, second node, etc. all nodes O(n)
// 	for(int i=0; i<n*n; ++i){
// 		// for each node O(n^2)
// 		for(int j=0; j<n*n; ++j){
// 			cr = j/n; cl = j%n;
// 			// coming from up
// 			if(cr>0){
// 				ans[cr][cl] = min(ans[cr][cl],max(ans[cr-1][cl],abs(arr[cr-1][cl]-arr[cr][cl])));
// 			}
// 			// down
// 			if(cr<n-1){
// 				ans[cr][cl] = min(ans[cr][cl],max(ans[cr+1][cl],abs(arr[cr+1][cl]-arr[cr][cl])));
// 			}
// 			// left
// 			if(cl>0){
// 				ans[cr][cl] = min(ans[cr][cl],max(ans[cr][cl-1],abs(arr[cr][cl-1]-arr[cr][cl])));
// 			}
// 			// right
// 			if(cl<n-1){
// 				ans[cr][cl] = min(ans[cr][cl],max(ans[cr][cl+1],abs(arr[cr][cl+1]-arr[cr][cl])));
// 			}
// 		}
// 	}

// 	for(int i=0; i<n; ++i){
// 		for(int j=0; j<n; ++j)
// 			printf("%d ", ans[i][j]);
// 		printf("\n");
// 	}
// 	printf("%d\n", ans[n-1][n-1]);
// 	return 0;
// }