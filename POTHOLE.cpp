// node numbering starts from 1
// adjacency list used, hence no duplicates in input

// lot of learning - both algo and C++
// code adapted from:
// <https://en.wikibooks.org/wiki/Algorithm_Implementation/Graphs/Maximum_flow/Edmonds-Karp>
// C++ adapted from:
// <http://marcodiiga.github.io/maximum-flow-bipartite-matching>
// adjacencyListFrom adapted from:
// <https://www.quora.com/ACM-ICPC-How-do-you-implement-Edmonds-Karp-Algorithm-for-sparse-graphs-using-adjacency-lists>

// Edmond Karp is better when number of edges is less O(VE^2)
// Dinic is better when number of edges is more O(V^2E)
// for sparseness, we use adjacency list
// back edges in residual graph need to be taken care of in a clever way
// we can tradeoff space or time

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
	int t;
	scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		Graph graph(n);
		int u, v, outDeg;
		// other in between edges
		for(int j=1; j<=n-1; ++j){
			u = j; scanf("%d", &outDeg);
			for(int i=0; i<outDeg; ++i){
				scanf("%d", &v);
				// source vertex is source or if destination vertex is sink
				if(u == 1 or v == n)
					graph.addEdge(u, v, 1);
				else	// unlimited capacity
					graph.addEdge(u, v, INT_MAX);
			}
		}
		graph.setSource(1); graph.setSink(n);
		printf("%d\n", graph.maximumFlow());
	}
	return 0;
}