// might help someday
// <https://stackoverflow.com/questions/20153488/topological-sort-using-dfs-without-recursion>
// key is to remember to sort the adjacency list and visit the nodes in proper order

#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

int n, number;

void dfs(int cur, vector<int> graph[], int finish[]){
	if(finish[cur] != 0)
		return;
	for(int i=0; i<graph[cur].size(); ++i){
		dfs(graph[cur][i], graph, finish);
	}
	finish[cur] = ++number;
}

int main(){
	int m, temp, temp1, temp2; scanf("%d %d", &n, &m);

	vector<int> graph[n+1];
	for(int i=0; i<m; ++i){
		scanf("%d %d", &temp1, &temp2);
		for(int j=0; j<temp2; ++j){
			scanf("%d", &temp); graph[temp].pb(temp1);
		}
	}

	for(int i=1; i<=n; ++i){
		sort(graph[i].begin(), graph[i].end(), greater<int>());
	}

	number = 0;
	int finish[n+1] = {};
	int notdone = n;
	while(notdone != -1){
		if(finish[notdone] == 0){
			dfs(notdone, graph, finish);
		}
		--notdone;
	}

	int final[n+1];
	for(int i=1; i<=n; ++i){
		final[finish[i]] = i;
	}

	for(int i=n; i>=1; --i){
		printf("%d ", final[i]);
	}
	printf("\n");
	return 0;
}