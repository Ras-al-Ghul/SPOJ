#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n, a, b, temp; scanf("%d", &n);

		vector<pair<int, int> > graph[n+1];
		for(int i=0; i<n-1; ++i){
			scanf("%d %d %d", &a, &b, &temp);
			graph[a].push_back(make_pair(b,temp));
			graph[b].push_back(make_pair(a,temp));
		}

		int dist[n+1] = {};
		bool visited[n+1] = {};
		stack<int> dfsstack; dfsstack.push(1);
		int max = 0, maxindex = -1;
		while(not dfsstack.empty()){
			int cur = dfsstack.top(); dfsstack.pop();
			if(visited[cur] == 1)
				continue;
			visited[cur] = 1;
			if(dist[cur] > max){
				max = dist[cur], maxindex = cur;
			}
			for(int i=0; i<graph[cur].size(); ++i){
				dfsstack.push(graph[cur][i].first);
				dist[graph[cur][i].first] = dist[cur] + graph[cur][i].second;
			}
		}
		
		memset(dist, 0, sizeof(dist)); memset(visited, 0, sizeof(visited));
	
		dfsstack.push(maxindex);
		max = 0;
		while(not dfsstack.empty()){
			int cur = dfsstack.top(); dfsstack.pop();
			if(visited[cur] == 1)
				continue;
			visited[cur] = 1;
			if(dist[cur] > max){
				max = dist[cur], maxindex = cur;
			}
			for(int i=0; i<graph[cur].size(); ++i){
				dfsstack.push(graph[cur][i].first);
				dist[graph[cur][i].first] = dist[cur] + graph[cur][i].second;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}