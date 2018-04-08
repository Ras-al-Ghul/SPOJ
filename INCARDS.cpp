// the key is  "You can also assume it is always possible to get from any stop to any other stop."
// which means you can run simple Djikstra instead of also looking for unvisited vertices
// double Djikstra - one on outgoing edges - to find shortest path to all other vertices from source 1
// one on incoming edges - to find shortest path to 1 from all other incoming vertices
// notice that there is Central Station - node 1 which hints at Djikstra

#include <iostream>
#include <vector>
#include <queue>

#define pb push_back
#define mp make_pair
#define pq priority_queue

using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n, e, a, b, c; scanf("%d %d", &n, &e);
		vector<pair<int,int> > incoming[n+1], outgoing[n+1];
		for(int i=0; i<e; ++i){
			scanf("%d %d %d", &a, &b, &c);
			outgoing[a].pb(mp(b,c));
			incoming[b].pb(mp(a,c));
		}
		pq<int, vector<pair<int,int> >, greater<pair<int,int> > > q;
		int dist[n+1] = {}; bool visited[n+1] = {};
		q.push(mp(0,1));
		int visitc = 0;
		while(visitc != n){
			int d = q.top().first, v = q.top().second;
			q.pop();
			if(not visited[v]){
				++visitc; visited[v] = true; dist[v] = d;
				for(int i=0; i<outgoing[v].size(); ++i){
					if(not visited[outgoing[v][i].first]){
						q.push(mp(outgoing[v][i].second+d,outgoing[v][i].first));
					}
				}
			}
		}
		int outc = 0;
		for(int i=1; i<=n; ++i)
			outc += (dist[i]);

		pq<int, vector<pair<int,int> >, greater<pair<int,int> > > qq;
		int dists[n+1] = {}; bool visiteds[n+1] = {};
		qq.push(mp(0,1));
		visitc = 0;
		while(visitc != n){
			int d = qq.top().first, v = qq.top().second;
			qq.pop();
			if(not visiteds[v]){
				++visitc; visiteds[v] = true; dists[v] = d;
				for(int i=0; i<incoming[v].size(); ++i){
					if(not visiteds[incoming[v][i].first]){
						qq.push(mp(incoming[v][i].second+d,incoming[v][i].first));
					}
				}
			}
		}
		int inc = 0;
		for(int i=1; i<=n; ++i)
			inc += (dists[i]);

		printf("%d\n", inc+outc);

	}
	return 0;
}