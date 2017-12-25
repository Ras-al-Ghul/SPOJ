// lot of unnecssary variables used below
// a bit of DFS with parent tracking and bipartite matching/graph coloring with two colors
// first thought is that a cycle detection using DFS should be enough
// but no, cycle is also fine if number of edges in cycles is even number of edges away
// eg: 1-2-3-4-1
// 1 M, 2 F, 3 M, 4 F - hence cycle is fine

#include <cstring>
#include <iostream>
#include <stack>
#include <set>

using namespace std;

int main(){
	int ncases;
	scanf("%d", &ncases);
	int count = 1;
	while(count<=ncases){
		int vertices, edges, a, b, cur;
		scanf("%d %d", &vertices, &edges);

		int graph[vertices+1][vertices+1] = {};
		for(int i=0; i<edges; ++i){
			scanf("%d %d", &a, &b);
			graph[a][b] = 1;
			graph[b][a] = 1;
		}

		int visited[vertices+1] = {};
		int visitedcount = 0;
		// parent who adds to dfsstack
		int parent[vertices+1] = {};
		// if in this set, then not visited yet
		set<int> visitedset;
		for(int i=1; i<=vertices; ++i)
			visitedset.insert(i);
		// to create bipartition
		int boolset[vertices+1];
		memset(boolset, -1, sizeof(boolset));
		boolset[1] = 0;

		stack<int> dfsstack;
		dfsstack.push(1);
		bool flag = false;

		while((not dfsstack.empty()) or (visitedcount < vertices)){
			if(not dfsstack.empty()){
				cur = dfsstack.top();
				if(visited[cur] == 1 and boolset[parent[cur]] == boolset[cur]){
					flag = true;
					break;
				}
				else{
					dfsstack.pop();
					if(visited[cur] == 0){
						visited[cur] = 1;
						visitedset.erase(cur);
						visitedcount++;
						for(int i=1; i<=vertices; ++i){
							if(graph[cur][i] and i != parent[cur]){
								if(boolset[i] == boolset[cur]){
									flag = true;
									break;
								}
								boolset[i] = (boolset[cur] + 1)%2;
								parent[i] = cur;
								dfsstack.push(i);
							}
						}
					}
				}
			}
			else{
				cur = (*visitedset.begin());
				boolset[cur] = 0;
				dfsstack.push(cur);
			}
			if(flag == true)
				break;
		}
		if(flag)
			printf("Scenario #%d:\nSuspicious bugs found!\n", count);
		else
			printf("Scenario #%d:\nNo suspicious bugs found!\n", count);
		count++;
	}

	return 0;
}