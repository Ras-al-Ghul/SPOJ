// DP approach is quite similar to FISHER
// dp[n][cost] - i,j - 'from source' to node i, min dist path possible within j cost
// cost j-1 to be filled before j for all i

#include <iostream>
#include <vector>
#include <climits>

#define mp make_pair
#define pb push_back

using namespace std;

// int main(){
// 	int t; scanf("%d", &t);
// 	while(t--){
// 		int k, n, r; scanf("%d %d %d", &k, &n, &r);
// 		vector<pair<int, pair<int, int> > > incoming[n+1];
		
// 		int from, to, len, toll, i, j, l;
// 		for(int i=0; i<r; ++i){
// 			scanf("%d %d %d %d", &from, &to, &len, &toll);
// 			incoming[to].pb(mp(from, mp(len, toll)));
// 		}

// 		int dp[n+1][k+1];

// 		for(i=0; i<=n; ++i){
// 			dp[i][0] = INT_MAX;
// 		}

// 		dp[1][0] = 0;

// 		// notice i=0 is the starting as there can be 0 cost paths
// 		for(i=0; i<=k; ++i){
// 			// this is again a very important step
// 			// before every iteration, copy previous iteration's value for all nodes
// 			// do it at once, cannot do it inside loop j - that will mix up cases
// 			// for instance i-toll = i (if toll = 0), now if that 'from node'
// 			// is yet to be covered, then it will be INT_MAX,
// 			// so it will give wrong answer
// 			if(i>0)
// 				for(l=1; l<=n; ++l)
// 					dp[l][i] = dp[l][i-1];
// 			for(j=1; j<=n; ++j){
// 				for(l=0; l<incoming[j].size(); ++l){
// 					from = incoming[j][l].first;
// 					len = incoming[j][l].second.first;
// 					toll = incoming[j][l].second.second;
// 					if(toll > i)
// 						continue;
// 					// if dp[from][i-toll] has been set before
// 					if(dp[from][i-toll] != INT_MAX)
// 						dp[j][i] = min(dp[j][i], dp[from][i-toll] + len);
// 				}
// 			}
// 		}
// 		// for(i=0; i<=n; ++i){
// 		// 	for(j=0; j<=k; ++j){
// 		// 		cout<<dp[i][j]<<" ";
// 		// 	}
// 		// 	cout<<endl;
// 		// }
// 		if(dp[n][k] != INT_MAX)
// 			printf("%d\n", dp[n][k]);
// 		else
// 			printf("-1\n");
// 	}
// 	return 0;
// }

// converting to another graph technique
// The better solution is using Dijkstra algorithm by modeling vertices
// as representing states state[vertex, total cost already incurred]
// We can have the similar table D(n,c) representing the shortest distance
// required to travel from state[1, 0] to state[n, c]
// Implementation using STL priority_queue is blazingly fast but take
// note that we need to terminate the algorithm once we have vertex N
// on top of our priority_queue since the corresponding distance is
// indeed the shortest distance within the permitted cost bounds

#include <queue>

#define pipii pair<int, pair<int, int> >

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int k, n, r; scanf("%d %d %d", &k, &n, &r);
		vector<pair<int, pair<int, int> > > outgoing[n+1];
		
		int from, to, len, toll, i, j, l;
		for(int i=0; i<r; ++i){
			scanf("%d %d %d %d", &from, &to, &len, &toll);
			outgoing[from].pb(mp(to, mp(len, toll)));
		}

		int visited[n+1][k+1];
		for(i=0; i<=n; ++i){
			for(int j=0; j<=k; ++j)
				visited[i][j] = INT_MAX;
		}
		// visited source with cost 0, dist 0
		visited[1][0] = 0;

		int dist, vertex, cost, newd, newv, newc;
		// dist, <vertex, cost>
		priority_queue<pipii, vector<pipii >, greater<pipii > > pq;
		pq.push(mp(0, mp(1, 0)));
		while(not pq.empty()){
			dist = pq.top().first;
			vertex = pq.top().second.first;
			cost = pq.top().second.second;
			pq.pop();
			
			// rendered irrelevant
			if(visited[vertex][cost] < dist)
				continue;

			if(vertex == n)
				break;
			
			// else
			for(i=0; i<outgoing[vertex].size(); ++i){
				newv = outgoing[vertex][i].first;
				newd = dist + outgoing[vertex][i].second.first;
				newc = cost + outgoing[vertex][i].second.second;
				if(newc <= k and visited[newv][newc] > newd){
					visited[newv][newc] = newd;
					pq.push(mp(newd,mp(newv,newc)));
				}
			}
		}

		// vertex != n means queue became empty
		if(vertex != n)
			printf("-1\n");
		else
			printf("%d\n", dist);
	}
	return 0;
}