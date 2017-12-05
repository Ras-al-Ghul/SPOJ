// I'd remembered Djikstra wrong
// It is not shortest path from any vertex in current circle to other vertex outside circle
// It is shortest path from source vertex to other vertex outside circle
// Hence you've maintain a list/heap which contains tentative distance 'from source' to not visited points outside the circle
// Here choose max dist instead of min like in Djikstra - after initializing to 0

// also, in Djikstra, printing path means, store 'parent array'
// instead of trying to update priority_queue, add everything to pq, but ignore visited <https://stackoverflow.com/questions/9209323/easiest-way-of-using-min-priority-queue-with-key-update-in-c>

#include <iostream>
#include <set>
#include <queue>
#include <cmath>
#include <limits>

#define ll long long
#define pq priority_queue
#define pp pair<double, pair<ll, ll> >

using namespace std;

bool definitelyGreaterThan(float a, float b)
{
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * numeric_limits<float>::epsilon());
}

int main(){
	ll n, m;
	ll a,b,percent;
	while(true){
		scanf("%lld", &n);
		if(not n)
			break;
		scanf("%lld", &m);
		ll graph[n+1][n+1] = {};
		for(ll i=0; i<m; ++i){
			scanf("%lld %lld %lld", &a, &b, &percent);

			graph[a][b] = percent;
			graph[b][a] = percent;
		}

		set<ll> visited = {};
		visited.insert(1);

		pq <pp, vector<pp >, less<pp > > longest;
		ll parent[n+1] = {};
		double distances[n+1] = {};

		distances[1] = 1.0f;

		for(ll i=1; i<=n; ++i){
			if(graph[1][i])
				longest.push(pp(graph[1][i], pair<ll,ll>(1,i)));
		}
		
		while(visited.size() != n){
			auto it = longest.top();

			int source = it.second.first;
			int dest = it.second.second;
			double cost = it.first;

			longest.pop();

			if(visited.find(dest) == visited.end()){
				visited.insert(dest);
				parent[dest] = source;
				distances[dest] = cost;

				for(int i=1;i<=n;++i){
					if(graph[dest][i] and visited.find(i) == visited.end() and definitelyGreaterThan(cost*graph[dest][i], distances[i])/*(cost*graph[dest][i]) > distances[i]*/){
						distances[i] = (cost*(double)graph[dest][i])/100;
						longest.push(pp(distances[i],pair<ll,ll>(dest,i)));
					}
				}
				if(dest == n)
					break;
			}
		}

		printf("%0.6lf percent\n", distances[n]);
	}
	return 0;
}