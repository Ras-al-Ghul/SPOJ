// BPM approach
// tree is a bipartite graph, so the minimum vertex cover is
// equivalent to the maximum flow (König's theorem). first run a DFS
// to determine the color of each node, then add 2 extra nodes
// (the source and the sink), connect the source to all black nodes,
// the sink to all white nodes and set all edges' capacities to 1.
// Finally, perform a maximum flow algorithm and you're done.

// <https://cs.stackexchange.com/questions/2208/reducing-minimum-vertex-cover-in-a-bipartite-graph-to-maximum-flow>
// <https://en.wikipedia.org/wiki/K%C5%91nig%27s_theorem_(graph_theory)>
// <https://www.quora.com/How-do-I-show-that-every-tree-is-a-bipartite-graph>
// <https://stackoverflow.com/questions/12449554/find-minimum-vertex-cover-for-bipartite-graph-given-the-maximum-matching>

// DP approach is similar to greedy approach
// dp[i][1] = answer of problem rooted at node i if node i is included in set
// dp[i][0] = answer of problem rooted at node i if node i is not included in set

// dp[i][1] = 1 + (sum(min(dp[v][0], dp[v][1]))) where v is children of i
// dp[i][0] = sum(dp[v][1]) where v is children of i
// in first case no need to select all children, hence take min,
// in second case have to select all children
// final answer is min(dp[1][0], dp[1][1])
// <https://discuss.codechef.com/questions/85420/minimum-vertex-cover>

// pretty awesome greedy approach - two steps:
// 1) for all leaves, include parents in min vertexcover
// (this holds because in min vertexcover which includes leaves,
// replace leaves with parents, cardinatlity of min vertexcover remains same)
// 2) for all internal nodes, if any child is not included in min vertexcover,
// include this node in it - use DFS approach to visit all children before taking
// decision for current node - why this works? after step 1), remove all edges and
// vertices covered by min vertexcover of step 1, now reapply same argument of step 1)
// - basically, induction from bottom of the tree
// <https://cs.stackexchange.com/questions/12177/correctness-proof-of-a-greedy-algorithm-for-minimum-vertex-cover-of-a-tree>

#include <iostream>
#include <vector>

#define MAX 100000

using namespace std;

typedef struct node{
	int val;
	struct node *next;
}NODE;

bool visited[MAX+1] = {};
bool vertexcover[MAX+1] = {};
vector<int> arr[MAX+1];

int vcount = 0;

void dfs(int cur, int parent){
	if(visited[cur])
		return;
	bool flag = false;
	visited[cur] = 1;

	for(int i=0; i<arr[cur].size(); ++i){
		if(not visited[arr[cur][i]])
			dfs(arr[cur][i], cur);
		if(vertexcover[arr[cur][i]] == 0 and arr[cur][i] != parent)
			flag = true;
	}
	if(arr[cur][0] == parent and arr[cur].size() == 1){
		vertexcover[arr[cur][0]] = 1;
		return;
	}

	if(flag == true){
		vertexcover[cur] = 1;
		++vcount;
	}
	return;
}

int main(){
	int n;
	scanf("%d", &n);
	int a, b;

	for(int i=0; i<n-1; ++i){
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(1, 0);

	printf("%d\n", vcount);
	return 0;
}