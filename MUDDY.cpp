// node numbering starts from 1

// remember the theory that there's a reduction from min vertex cover
// to max flow from Konig's theorem in Bipartite graphs
// if you have something that looks like min vertex cover/min set cover,
// try to look out for this - i.e. problem statements like minimum 
// number of edges/boards/whatever given a graph/2D grid 
// then look at how given graph can be converted to Bipartite graph whose
// minimum vertex cover helps solve the problem
// instead of directly trying to apply maxflow

// this problem didn't look like it can be done by dp, greedy might be possible
// but didn't look to disprove that greedy was not possible
// saw maxflow tag, came so far as to deduce maximal length vertical
// and horizontal bars, but didn't know how to use that

// then see min set cover problem, min number of subsets to form a set
// but that's np complete, hence look at min vertex cover. But not on a generic graph,
// but on a bipartite graph, since only then reduction to max flow is possible

// if you see maximal vertical and horizontal length rods and play around, you'll
// get the idea, given that we're trying to minimize the number of rods we need
// to use - for each muddy spot, we'll either select a horizontal rod or a vertical
// rod - since it's either, those are the two partitions of the graph
// connect source to all vertical rods and sink to all horizontal rods
// and find max flow - this will find min vertex cover - which in turn means
// minimum number of vertices (horizontal or vertical rods) which cover all the
// edges (edges are muddy spots here)

#include <iostream>
#include <climits>
#include <vector>
#include <list>
#include <queue>
#include <string>

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
	int t; scanf("%d", &t);
	while(t--){
		int i, j, r, c, longest, nbars; scanf("%d %d", &r, &c);
		string temp;
		bool arr[r][c] = {};
		for(i=0; i<r; ++i){
			cin>>temp;
			for(j=0; j<temp.length(); ++j)
				arr[i][j] = temp[j]=='*'?1:0;
		}

		// stores which longest vertical[0] or horizontal[1] bar the
		// muddy patch belongs to and (0,0) if not muddy patch
		// nodes numbered from 0 to (r*c)-1 row wise
		int mapping[r*c][2] = {};

		// longest vertical bars
		longest = 0;
		for(j=0; j<c; ++j){
			int temparr[r] = {};
			for(i=0; i<r; ++i){
				if(arr[i][j] == 1){
					if(i>0 and temparr[i-1] != 0){
						temparr[i] = temparr[i-1]; mapping[(i*c)+j][0] = temparr[i];
					}
					else{
						++longest; temparr[i] = longest; mapping[(i*c)+j][0] = temparr[i];
					}
				}
			}
		}
		// to help with source and sink connections later
		nbars = longest;
		// longest horizontal bars
		for(i=0; i<r; ++i){
			int temparr[c] = {};
			for(j=0; j<c; ++j){
				if(arr[i][j] == 1){
					if(j>0 and temparr[j-1] != 0){
						temparr[j] = temparr[j-1]; mapping[(i*c)+j][1] = temparr[j];
					}
					else{
						++longest; temparr[j] = longest; mapping[(i*c)+j][1] = temparr[j];
					}
				}
			}
		}

		// create graph and connect each muddy patch to respective nodes
		// nodes are longest horizontal bars or longest vertical bars
		// bipartite graph
		Graph graph(longest+2);
		// supersource
		graph.setSource(1);
		for(i=0; i<(r*c); ++i)
			if(mapping[i][0] != 0)
				// add edge from vertical bar to horizontal bar for that muddy patch
				graph.addEdge(mapping[i][0]+1,mapping[i][1]+1,1);
		// supersink
		graph.setSink(longest+2);
		for(i=1; i<=nbars; ++i)
			graph.addEdge(1,i+1,1);
		for(i=nbars+1; i<=longest; ++i)
			graph.addEdge(i+1,longest+2,1);

		printf("%d\n", graph.maximumFlow());
	}
	return 0;
}