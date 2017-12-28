// kinda like inverse of Djikstra
// like, given dest, from what sources can you visit dest
// also in Djikstra, remember, when you push to queue, you have to 
// add distances up to the parent node, because it is 'single source'
// shortest path algo - you can't just push arr[i][j], do distances[i] + arr[i][j]

#include <iostream>
#include <queue>
#include <climits>

#define pq priority_queue
#define pp pair<int, pair<int, int> >

using namespace std;

int main(){
	int n, dest, time, nedges;
	scanf("%d %d %d %d", &n, &dest, &time, &nedges);

	// n is 100, so adj matrix
	int arr[n+1][n+1] = {};
	int a, b, times;
	for(int i=0; i<nedges; ++i){
		scanf("%d %d %d", &a, &b, &times);
		arr[a][b] = times;
	}

	int visited[n+1] = {};
	int distances[n+1];
	for(int i=1; i<=n; ++i)
		distances[i] = INT_MAX;
	distances[dest] = 0;

	pq <pp, vector<pp >, greater<pp > > shortest;

	visited[dest] = 1;
	for(int i=1; i<=n; ++i){
		if(arr[i][dest] != 0)
			shortest.push(pp(arr[i][dest], pair<int, int>(i, dest)));
	}

	while(not shortest.empty()){
		int curval = shortest.top().first;
		a = shortest.top().second.first; b = shortest.top().second.second;
		shortest.pop();
		if(visited[a] == 0){
			distances[a] = distances[b] + arr[a][b];
			if(distances[a] > time)
				break;
			visited[a] = 1; 
			for(int i=1; i<=n; ++i){
				if(arr[i][a] != 0 and (not visited[i]))
					shortest.push(pp(distances[a] + arr[i][a], pair<int, int>(i, a)));
			}
		}
	}
	times = 0;
	for(int i=1; i<=n; ++i)
		if(visited[i])
			++times;

	printf("%d\n", times);
	return 0;
}