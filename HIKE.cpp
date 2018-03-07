// this was based on a wrong hypothesis
// the first step of the hypothesis is that - the last node on which all three pieces end up
// has atleast one edge to another node which is of the same color as the self edge
// this is because once two pieces are on this node, the third node has to travel on an edge
// with color of edge between the two pieces - hence one outgoing same color edge has to exist

// then I followed it up with wrongful induction by trial and error which seemed to indicate that
// all the pieces ultimately end up at some node by 'only' travelling through edges which have the same color
// as the self edge color of that node - so if self edge color is red, the three pieces only travel
// through red edges - I did this bfs for all nodes

// wrongful because, a case like this:
// 4 1 3 4
// r r b b
// r b r r
// b r d r 
// b r r d
// 0
// has a solution 3 - all three end up on 1 using three moves
// but this code gives answer 4 which is wrong

// so the pieces can traverse on edges other than the self reference edge of the node they end up on
// hence need some kind of incremental update procedure like the Djikstra algo
// only those edges added to boundary in Djikstra which are neighbours of current edge
// something similar here in the new code
// Floyd Warshall update distances logic also - see below

#include <iostream>
#include <climits>
#include <queue>
#include <cstring>

using namespace std;

int main1(){
	int n, a, b, c;
	while(true){
		cin>>n; if(not n) break;
		cin>>a>>b>>c;
		--a; --b; --c;
		char arr[n][n];
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				cin>>arr[i][j];
		int ans = INT_MAX;
		// have to do BFS for each vertex
		for(int i=0; i<n; ++i){
			// color of self referential edge
			char cc = arr[i][i];
			bool avis = false, bvis = false, cvis = false;
			bool visited[n] = {};
			int steps[n] = {};
			steps[i] = -1;
			int parent[n] = {};
			parent[i] = i;
			queue<int> bfs; bfs.push(i);
			while(not bfs.empty()){
				int temp = bfs.front(); bfs.pop();
				if(not visited[temp]){
					visited[temp] = true;
					steps[temp] = steps[parent[temp]] + 1;
					if(temp == a or temp == b or temp == c){
						if(temp == a and (not avis))
							avis = true;
						if(temp == b and (not bvis))
							bvis = true;
						if(temp == c and (not cvis))
							cvis = true;
						if(avis and bvis and cvis)
							break;
					}
					for(int j=0; j<n; ++j){
						// check only for cc color which is wrong
						if(not visited[j] and arr[temp][j] == cc){
							bfs.push(j);
							if(not parent[j])
								parent[j] = temp;
						}
					}
				}
			}
			if(avis and bvis and cvis){
				ans = min(ans, (steps[a]+steps[b]+steps[c]));
			}
		}
		if(ans != INT_MAX)
			printf("%d\n", ans);
		else
			printf("impossible\n");
	}
	return 0;
}

// code from Zobayer
// check using Djikstra principle and Floyd Warshall update distances
// also 1<=n<=50 constraint, hence can afford to do such a incremental update
int main(){
	int n, a, b, c, i, j;
	while(scanf("%d", &n)==1 && n) {
		scanf("%d%d%d", &a, &b, &c);
		--a, --b, --c;
		char arr[n][n][2];
		int distances[n][n][n]; // numero de movimentos
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				scanf("%s", arr[i][j]);
		queue<int> bfs;
		// push three at a time
		bfs.push(a), bfs.push(b), bfs.push(c);
		// maxvalue
		memset(distances, 0x7f, sizeof distances);
		// number of moves to starting position is 0
		distances[a][b][c] = 0;
		while(not bfs.empty()){
			// all operations are done three at a time
			a = bfs.front(); bfs.pop();
			b = bfs.front(); bfs.pop();
			c = bfs.front(); bfs.pop();
			// check all possible affected nodes
			// 1<=n<=50 hence can be done
			// also have to check since it is fully connected graph
			for(i=0; i<n; i++){
				// change a, b, c one at a time and check - move one piece at a time as given in question

				// if color constraint met and current known distance is > distance due to
				// element removed from queue, then update current known distance
				if(arr[a][i][0]==arr[b][c][0] && distances[i][b][c] > distances[a][b][c] + 1) {
					// the neighbours of (i,b,c) may be affected - Djikstra algo principle
					// hence push (i,b,c) in queue and check in upcoming iterations
					bfs.push(i), bfs.push(b), bfs.push(c);
					// +1 number of moves
					distances[i][b][c] = distances[a][b][c] + 1;
				}
				if(arr[b][i][0]==arr[c][a][0] && distances[a][i][c] > distances[a][b][c] + 1) {
					bfs.push(a), bfs.push(i), bfs.push(c);
					distances[a][i][c] = distances[a][b][c] + 1;
				}
				if(arr[c][i][0]==arr[a][b][0] && distances[a][b][i] > distances[a][b][c] + 1) {
					bfs.push(a), bfs.push(b), bfs.push(i);
					distances[a][b][i] = distances[a][b][c] + 1;
				}
			}
		}
		// find the position at which a,b,c end up on if they actually do
		for(i=0, j=0x7f7f7f7f; i<n; i++) j = min(j, distances[i][i][i]);
		if(j==0x7f7f7f7f) printf("impossible\n");
		else printf("%d\n", j);
	}
	return 0;
}