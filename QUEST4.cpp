// A smallest edge cover can be found in polynomial time by finding a maximum matching and extending it greedily so that all vertices are covered.

// now there are a set of cordinates given - think of each of them as a vertex
// the greedy method of take each square - place plank at that cordinate horizontally or vertically
// do this till all squares are covered won't work
// simple example is (0,0) (0,1) (0,2) (0,3) (1,0) (2,1) (3,2) (4,3)
// the greedy answer says we need 5 planks
// but we need only 4

// think of each vertex and connect by edge to another vertex which will
// get covered if a board will be placed on this vertex
// this forms a graph
// what we want is to use minimal number of boards
// this means cover all vertices using less edges - min vertex cover
// now this can be found using max matching

// if it is a general graph, it will be tough
// this is a bipartite graph, draw examples to see how it is naturally bipartite
// also time constraints indicate it is bipartite - also matching problems are generally on bipartite graphs

// now problem is to separate into two sets
// graph 2 coloring approach followed by maximum matching through max flow
// graph 2 coloring uses BFS - parents - children - color with opposite color
// this times out - this is main1

// so how to make bipartition faster?
// think of all points on a row to be a vertex - 120 possible - this is one set
// all points on a column to be a vertex - 120 possible - this is the other set
// for each cordinate (a,b), make edge from a to b
// this is equivalent to above - 2 coloring
// min vertex cover would mean you would choose either placing along row or placing along column for that cordinate
// row means you will choose a as vertex, column means you will choose b as vertex
// and it is done optimally
// whenever such a situation occurs - like how to find partition - think of using grid indices - x and y cordinates as identities - in this case as vertices

// now find maximum bipartite matching

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>

#define mp make_pair

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

// int main1(){
// 	int t;
// 	scanf("%d", &t);
// 	while(t--){
// 		int n; scanf("%d", &n);
// 		vector<pair<int,int> > arr1(n+1);
// 		vector<pair<int,int> > arr2(n+1);
// 		map<pair<int, int>, int> mapping;
// 		for(int i=1; i<=n; ++i){
// 			scanf("%d %d", &arr1[i].first, &arr1[i].second);
// 			arr2[i].first = arr1[i].second; arr2[i].second = arr1[i].first;
// 			mapping[mp(arr1[i].first, arr1[i].second)] = i;
// 		}
// 		sort(arr1.begin(), arr1.end()); sort(arr2.begin(), arr2.end());
		
// 		vector<int> edgeGraph[n+1];

// 		vector<pair<int,int> > edges;
// 		// i < n is important, not i <= n
// 		for(int i=1; i<n; ++i){
// 			if(arr1[i].first == arr1[i+1].first){
// 				int ind1 = mapping.find(mp(arr1[i].first,arr1[i].second))->second;
// 				int ind2 = mapping.find(mp(arr1[i+1].first,arr1[i+1].second))->second;
// 				edges.push_back(mp(ind1, ind2));
// 				edgeGraph[ind1].push_back(ind2); edgeGraph[ind2].push_back(ind1);
// 			}
// 			if(arr2[i].first == arr2[i+1].first){
// 				int ind1 = mapping.find(mp(arr2[i].second,arr2[i].first))->second;
// 				int ind2 = mapping.find(mp(arr2[i+1].second,arr2[i+1].first))->second;
// 				edges.push_back(mp(ind1, ind2));
// 				edgeGraph[ind1].push_back(ind2); edgeGraph[ind2].push_back(ind1);
// 			}
// 		}

// 		// do a two coloring on edges graph - using BFS
// 		bool colors[n+1] = {};
// 		int visited[n+1] = {}, nvis = n;
// 		int parent[n+1] = {};
// 		queue<int> bfs; bfs.push(1);
// 		while(nvis){
// 			int temp = bfs.front(); bfs.pop();
// 			if(not visited[temp]){
// 				--nvis;
// 				visited[temp] = 1; colors[temp] = !colors[parent[temp]];
// 				for(int i=0; i<edgeGraph[temp].size(); ++i){
// 					if(not visited[edgeGraph[temp][i]]){
// 						bfs.push(edgeGraph[temp][i]); parent[edgeGraph[temp][i]] = temp;
// 					}
// 				}
// 			}
// 			if(nvis and bfs.empty()){
// 				for(int i=1; i<=n; ++i)
// 					if(not visited[i]){
// 						bfs.push(i);
// 						break;
// 					}
// 			}
// 		}

// 		set<int> all;
// 		for(int i=1; i<=n; ++i)
// 			all.insert(i);

// 		// 1 is super source, n+2 is super sink
// 		// so right shift above indices in 'mapping' by one
// 		Graph graph(n+2);

// 		for(int i=0; i<edges.size(); ++i){
// 			int ind1 = edges[i].first, ind2 = edges[i].second;
// 			if(colors[ind1] == 0 and colors[ind2] == 1)
// 				graph.addEdge(ind1+1, ind2+1, 1);
// 			else
// 				graph.addEdge(ind2+1, ind1+1, 1);
// 			all.erase(ind1); all.erase(ind2);
// 		}

// 		for(int i=1; i<=n; ++i){
// 			if(colors[i] == 0)
// 				graph.addEdge(1, i+1, 1);
// 			else
// 				graph.addEdge(i+1, n+2, 1);
// 		}

// 		graph.setSource(1); graph.setSink(n+2);
// 		printf("%d\n", graph.maximumFlow()+(int)(all.size()));
// 	}
// 	return 0;
// }

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, a, b; scanf("%d", &n);

		Graph graph(250+2);

		int A[130] = {}, B[130] = {};
		for(int i=1; i<=n; ++i){
			scanf("%d %d", &a, &b);
			// shift by two because 0 is part of input, 1 is source
			// hence 0 needs to become 2
			graph.addEdge(a+2, 123+b+2, 1);
			if(not A[a]){
				graph.addEdge(1, a+2, 1);
				A[a] = 1;
			}
			if(not B[b]){
				graph.addEdge(123+b+2, 250+2, 1);
				B[b] = 1;
			}
		}
		
		graph.setSource(1); graph.setSink(250+2);
		printf("%d\n", graph.maximumFlow());
	}
	return 0;
}