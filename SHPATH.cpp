// textbook Djikstra - stop as soon as you hit dest node

#include <iostream>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <queue>

#define pq priority_queue
#define pp pair<long, pair<int, int> >

using namespace std;

typedef struct Node{
	int city;
	long dist;
}NODE;

int main(){
	int ncases;
	scanf("%d", &ncases);
	while(ncases--){
		int ncities;
		scanf("%d", &ncities);
		map<string, int> indexing;
		NODE *cities[ncities + 1];
		for(int i=1; i<=ncities; ++i){
			string cityname; cin>>cityname;
			indexing[cityname] = i;

			int neighbours;
			scanf("%d", &neighbours);

			cities[i] = new NODE[neighbours+1];
			// first entry stores number of neighbours instead of dist
			cities[i][0].city = i;
			cities[i][0].dist = neighbours;

			for(int j=1; j<=neighbours; ++j)
				scanf("%d %ld", &(cities[i][j].city), &(cities[i][j].dist));
		}

		// for(int i=1;i<=ncities;++i){
		// 	for(int j=1; j<=cities[i][0].dist; ++j){
		// 		cout<<cities[i][j].city<<" "<<cities[i][j].dist<<endl;
		// 	}
		// 	cout<<endl;
		// }

		int ndist;
		scanf("%d", &ndist);
		while(ndist--){
			string c1, c2; cin>>c1>>c2;
			int cone = indexing[c1], ctwo = indexing[c2];
			// to find shortest path from cone to ctwo

			int visited[ncities+1] = {};
			visited[cone] = 1;

			long distarr[ncities+1];
			for(int i=1;i<=ncities;++i)
				distarr[i] = LONG_MAX;
			distarr[cone] = 0;

			pq<pp, vector<pp >, greater<pp > > heap;
			for(int i=1; i<=cities[cone][0].dist; ++i){
				heap.push(pp(cities[cone][i].dist, pair<int,int>(cone,cities[cone][i].city)));
			}

			int counter = 0;
			while(counter != ncities){
				auto it = heap.top();

				int source = it.second.first;
				int dest = it.second.second;
				long cost = it.first;

				heap.pop();
				if(not visited[dest]){
					visited[dest] = 1;
					distarr[dest] = cost;

					if(dest == ctwo)
						break;

					for(int i=1; i<=cities[dest][0].dist; ++i){
						if((not visited[cities[dest][i].city]) and (cost+cities[dest][i].dist)<distarr[cities[dest][i].city]){
							distarr[cities[dest][i].city] = cost+cities[dest][i].dist;
							heap.push(pp(distarr[cities[dest][i].city],pair<int,int>(dest,cities[dest][i].city)));
						}
					}
					
				}
			}
			printf("%ld\n", distarr[ctwo]);
		}
	}
	return 0;
}