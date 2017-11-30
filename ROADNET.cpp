// O(N^3) is better than Djikstra's maybe, but I just wanted to try out Djikstra

// For using Djikstra algo is as follows
// from each vertex do a Djikstra run - you'll get shortest paths to all vertices
// if the shortest path is reached in 0 (source vertex itself) or 1 hops, it means you're using direct path
// check this for pairs with ONLY greater than current vertex, because we would've checked for pairs with less than
// when the less than was start vertex
// at the same time, we have to find shortest paths from current source to ALL vertices, cannot eliminate less than vertices
// because of the way Djikstra works

// this is because the input graph is not distance between A and B graph,
// it is shortest distance between A and B graph - hence it will be connected

// connected graph assumed because
// The table of distances is written in the following n lines. In the (i+1)-th line,
// 1 <= i <= n, there are n non-negative integers not greater than 200, separated by single spaces

// maintaining hops count is pretty tricky. in case of an update, it is 'hops to current vertex + 1'

#include <iostream>
#include <climits>

using namespace std;

int minDist(int dist[][2], bool visited[], int vertices){
	int min = INT_MAX, min_index;
	for(int i=0;i<vertices;++i){
		if((!visited[i]) and (dist[i][0] < min))
			min = dist[i][0], min_index = i;
	}
	return min_index;
}

int main(){
	int ncases, vertices, i, j, k, temp, startv;
	scanf("%d", &ncases);
	while(ncases--){
		scanf("%d", &vertices);
		int arr[vertices][vertices] = {};
		for(i=0;i<vertices;++i){
			for(j=0;j<vertices;++j){
				scanf("%d", &arr[i][j]);
			}
		}

		for(j=0;j<vertices;++j){
			startv = j;
			// 0 is distance, 1 is hops
			int dist[vertices][2];
			bool visited[vertices] = {};
			for(i=0;i<vertices;++i){
				dist[i][0] = INT_MAX;
				dist[i][1] = 0;
			}
			// distance to start vertex is 0
			dist[startv][0] = 0;

			for(i=0;i<vertices;++i){
				// find out minDist from vertices not yet visited
				k = minDist(dist, visited, vertices);
				// mark as visited
				// note that we don't treat start vertex specially, it is also visited
				visited[k] = 1;

				for(temp = 0;temp<vertices;++temp){
					// you've to do <= because 
					// towns A and B are neighbouring towns if there is NO TOWN C such that the length of the shortest way
					// from A to B 'equals' the sum of the lengths of the shortest ways from A to C and C to B
					// even if equality holds, then it is still shorter path kind of idea
					// plain Djikstra is <

					// also Djikstra's updates only for neighbours, here you're doing it for all nodes

					// since you've made it <= here for dist[k][0]+arr[k][temp] <= dist[temp][0]
					// therefore you've to do dist[i][1] < 2 and not dist[i][1] != 2 in the print

					// arr[k][temp] and dist[k][0] != INT_MAX is important, else may lead to overflow
					// the above comment doesn't seem to hold as in the first iteration of i, the source is visited
					// this will change all dist[temp][0] to something less than INT_MAX, hence no overflow
					if(!visited[temp] /*and arr[k][temp] and dist[k][0] != INT_MAX*/ and dist[k][0]+arr[k][temp] <= dist[temp][0]){
						dist[temp][0] = dist[k][0] + arr[k][temp];
						// increment hops carefully
						dist[temp][1] = dist[k][1] + 1;
					}
				}
			}

			// only with greater than as mentioned at the top
			for(i=startv+1;i<vertices;++i){
				if(dist[i][1] < 2)
					cout<<startv+1<<" "<<i+1<<endl;
			}
		}
		if(ncases)
			cout<<endl;
	}
	return 0;
}