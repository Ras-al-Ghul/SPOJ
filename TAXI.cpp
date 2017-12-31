// maximum bipartite matching - BPM - solved after reduction to maxflow
// can also solve using Hopcroft Karp algorithm, which is a faster than
// 'max flow' method to find maximum matchings in bipartite graphs
// <https://www.geeksforgeeks.org/hopcroft-karp-algorithm-for-maximum-matching-set-1-introduction/>
// Konig's theorem
// <https://en.wikipedia.org/wiki/K%C5%91nig%27s_theorem_(graph_theory)>
// (min) minimum vertex cover in bipartite graph
// = maximum bipartite matching
// = can be reduced to max flow
// <https://www.geeksforgeeks.org/maximum-bipartite-matching/>
// all trees are bipartite graphs

#include <iostream>
#include <climits>
#include <vector>
#include <list>
#include <queue>

using namespace std;

typedef struct Edge {
	int u; // Origin
	int v; // Destination
	int capacity; // Capacity
	int flux; // Current flux
}EDGE;

class Graph{
public:
	// maintain two adjacency lists instead of one adjacency matrix
	// adjacencyListFrom takes care of back edges which arise in residual graph
	vector<list<Edge *> > adjacencyList;
	vector<list<Edge *> > adjacencyListFrom;
	int numberOfVertices;
	int source, sink;
	Graph(int V) : source(-1), sink(-1){
		adjacencyList.resize(V+1);
		adjacencyListFrom.resize(V+1);
		numberOfVertices = V;
	}
	void addEdge(int u, int v, int c){
		EDGE * temp = new EDGE{u, v, c, 0};
		adjacencyList[u].push_back(temp);
		adjacencyListFrom[v].push_back(temp);
	}
	void setSource(int s){
		source = s;
	}
	void setSink(int s){
		sink = s;
	}
	int maximumFlow(){ // Edmonds–Karp
		while(true){
			// 'arr' keeps track of path which we've used to reach sink
			// in second index - 1 indicates reverse edge, 0 is forward
			pair<EDGE*, int> arr[numberOfVertices+1] = {};
			// capacity of path to node - used to find limiting flow
			// saves one more pass over augmenting path
			int M[numberOfVertices+1] = {}; M[source] = INT_MAX;
			queue<int> bfsQueue;
			bfsQueue.push(source);
			while(not bfsQueue.empty()){
				int u = bfsQueue.front(); bfsQueue.pop();
				// for each
				for(auto edge : adjacencyList[u]){
					if(edge->capacity - edge->flux > 0 and arr[edge->v].first == nullptr){
						// set as forward edge
						arr[edge->v].first = edge; arr[edge->v].second = 0;
						M[edge->v] = min(M[edge->u], edge->capacity - edge->flux);
						if(edge->v != sink){
							bfsQueue.push(edge->v);
						}
						else{
							auto parentEdge = arr[edge->v];
							while(parentEdge.first->u != source){
								// forwared edge
								if(parentEdge.second == 0){
									parentEdge.first->flux += M[sink];
									parentEdge = arr[parentEdge.first->u];
								}
								// back edge
								else{
									parentEdge.first->flux -= M[sink];
									parentEdge = arr[parentEdge.first->v];
								}
							}
							// take care of edges from source
							// because above loop breaks before it is taken care of
							if(parentEdge.second == 0){
								parentEdge.first->flux += M[sink];
								parentEdge = arr[parentEdge.first->u];
							}
							else{
								parentEdge.first->flux -= M[sink];
								parentEdge = arr[parentEdge.first->v];
							}
							break;
						}
					}
				}
				// there might be back edges in residual graphs
				// for each
				for(auto edge : adjacencyListFrom[u]){
					if(edge->flux > 0 and arr[edge->u].first == nullptr){
						// set as back edge
						arr[edge->u].first = edge; arr[edge->u].second = 1;
						M[edge->u] = min(M[edge->v], edge->flux);
						if(edge->u != sink){
							bfsQueue.push(edge->u);
						}
						else{
							// this part will never be reached
							auto parentEdge = arr[edge->u];
							while(parentEdge.first != nullptr){
								if(parentEdge.second == 0){
									parentEdge.first->flux += M[sink];
									parentEdge = arr[parentEdge.first->u];
								}
								else{
									parentEdge.first->flux -= M[sink];
									parentEdge = arr[parentEdge.first->v];
								}
							}
							break;
						}
					}
				}
			}
			// sum over flows of all links out of source
			if(arr[sink].first == nullptr){
				int sum = 0;
				for(auto edge : adjacencyList[source]){
					sum += edge->flux;
				}
				return sum;
			}
		}
	}
};

int main(){
	int k;
	scanf("%d", &k);
	while(k--){
		int p, t, s, c;
		scanf("%d %d %d %d", &p, &t, &s, &c);
		int personPosn[p+1][2];
		for(int i=1; i<=p; ++i){
			scanf("%d %d", &personPosn[i][0], &personPosn[i][1]);
		}
		int taxiPosn[t+1][2];
		for(int i=1; i<=t; ++i){
			scanf("%d %d", &taxiPosn[i][0], &taxiPosn[i][1]);
		}
		long maxdist = long(c) * long(s);
		// 1 is supersource
		// hence cab numbers added by 1
		// taxi numbers start after p+1 - i.e. from p+2
		Graph graph(p+t+2); long dist;
		for(int i=1; i<=p; ++i){
			for(int j=1; j<=t; ++j){
				dist = abs(long(personPosn[i][0])-long(taxiPosn[j][0]))
					   + abs(long(personPosn[i][1])-long(taxiPosn[j][1]));
				if((dist*200) <= maxdist){
					graph.addEdge(i+1,j+p+1,1);
				}
			}
		}
		// 1 is supersource
		for(int i=1; i<=p; ++i){
			graph.addEdge(1,i+1,1);
		}
		graph.setSource(1);
		// p+t+2 is supersink
		for(int i=1; i<=t; ++i){
			graph.addEdge(i+p+1,p+t+2,1);
		}
		graph.setSink(p+t+2);
		printf("%d\n", graph.maximumFlow());
	}
	return 0;
}