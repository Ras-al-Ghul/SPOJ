// can be solved using MST too
// here it is done using Djikstra

#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define pb push_back
#define mp make_pair

using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n, m, a, b, c, d, tim; scanf("%d %d %d %d", &n, &m, &a, &b);
		a--; b--;
		vector<pii > adj[n] = {};
		for(int i=0; i<m; ++i){
			scanf("%d %d %d", &c, &d, &tim);
			adj[c-1].pb(mp(d-1, tim));
			adj[d-1].pb(mp(c-1, tim));
		}

		bool visited[n] = {};
		priority_queue<pii, vector<pii>, greater<pii> > dji;
		dji.push(mp(0, a));
		int curtim = 0, curind = 0;
		while(not dji.empty()){
			curtim = dji.top().first;
			curind = dji.top().second;
			dji.pop();
			if(not visited[curind]){
				visited[curind] = 1;
				if(curind == b)
					break;
				if(adj[curind].size() == 0)
					break;
				for(int i=0; i<adj[curind].size(); ++i){
					if(not visited[adj[curind][i].first])
						dji.push(mp(curtim + adj[curind][i].second, adj[curind][i].first));
				}
			}
		}
		if(not visited[b])
			printf("NONE\n");
		else
			printf("%d\n", curtim);
	}
	return 0;
}