// Kruskal's
// Be careful in getparent - at the end, in line 44 - you have to change set of parent, not set of current
// can also reset parents of all indices during traversal to actual parent, speeds up further getparents

// Prim's
// For Prim's, maintain visited list/set and cost list - both over vertices
// cost list maintains cost of all edges in the cut - choose min of that
// i.e. cost of reaching vertices part of cut, but outside visited, from vertices part of cut, but already visited
// initialize cost list to infinity, and on adding an edge to visited, update cost of all vertices which become a part of the cut

#include <iostream>
#include <queue>

#define ll long long
#define pq priority_queue
#define pp pair<int, pair<int, int> >

using namespace std;

int getparent(int index, int arr[]){
	while(arr[index] != index)
		index = arr[index];
	return index;
}

int main(){
	int ncases;
	scanf("%d", &ncases);
	while(ncases--){
		long long price; int numv, nume;
		scanf("%lld %d %d", &price, &numv, &nume);
		
		int vertices[numv+1];
		for(int i=1; i<=numv; ++i)
			vertices[i] = i;

		int sets = numv;
		pq <pp, vector<pp >, greater<pp > > edges;
		int a, b, len;
		for(int i=1; i<=nume; ++i){
			scanf("%d %d %d", &a, &b, &len);
			edges.push(pp(len, pair<int, int>(a,b)));
		}
		long long result = 0;
		while(sets != 1){
			auto it = edges.top();
			a = it.second.first; b = it.second.second; len = it.first;
			int pa = getparent(a, vertices); int pb = getparent(b, vertices);
			if(pa != pb){
				vertices[pa] = vertices[pb];
				result += (long long)len;
				--sets;
			}
			edges.pop();
		}
		printf("%lld\n", result*price);
	}
	return 0;
}