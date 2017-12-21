// borrowed template from earlier Kruskal's code
// changed getparent to point to which set it belongs to using recursion
// optimized for dist a-b = dist b-a, hence ignore later edges

#include <iostream>
#include <queue>
#include <string>

#define ll long long
#define pq priority_queue
#define pp pair<int, pair<int, int> >

using namespace std;

int getparent(int index, int arr[]){
	if(arr[index] != index)
		arr[index] = getparent(arr[index], arr);
	return arr[index];
}

int main(){
	int ncases;
	scanf("%d", &ncases);
	while(ncases--){
		int numv, nume;
		scanf("%d", &numv);
		
		int vertices[numv+1];
		for(int i=1; i<=numv; ++i)
			vertices[i] = i;

		int sets = numv;
		string cityname;
		pq <pp, vector<pp >, greater<pp > > edges;
		int temp, len;
		for(int j=1; j<=numv; ++j){
			cin>>cityname;
			scanf("%d", &nume);
			for(int i=1; i<=nume; ++i){
				scanf("%d %d", &temp, &len);
				if(temp<j)
					continue;
				edges.push(pp(len, pair<int, int>(j,temp)));
			}
		}

		long long result = 0;
		int a, b;
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
		printf("%lld\n", result);
	}
	return 0;
}