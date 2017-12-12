// modified Djikstra - no need to try to construct graph, instead directly use Djikstra on vertices
// can also use BFS

#include <iostream>
#include <queue>
#include <string>

#define pq priority_queue
#define pp pair<int, pair<int, int> >

using namespace std;

int main(){
	int a, b;
	string row;
	while(true){
		scanf("%d %d", &b, &a);
		if(a == 0 and b == 0)
			break;
		
		char graph[a][b] = {};
		int srcindex = -1, destindex = -1;

		for(int i=0; i<a; ++i){
			cin>>row;
			for(int j=0; j<b; ++j){
				graph[i][j] = row[j];
				if(graph[i][j] == 'S')
					srcindex = (i*b) + j;
				else if(graph[i][j] == 'D'){
					destindex = (i*b) + j;
					graph[i][j] = ' ';
				}
			}
		}

		if(srcindex == -1 or destindex == -1){
			cout<<0<<endl;
			continue;
		}

		bool visited[a][b] = {};
		int dist[a][b] = {};

		// mark source as visited
		visited[srcindex/b][srcindex%b] = 1;

		pq<pp, vector<pp >, greater<pp > > heap;
		// add everything around src to pq
		// top
		if((srcindex/b) - 1 >= 0 and graph[(srcindex/b)-1][srcindex%b] != 'X'){
			heap.push(pp(int(graph[(srcindex/b)-1][srcindex%b]) - 48,pair<int, int>((srcindex/b)-1,srcindex%b)));
		}
		// bottom
		if((srcindex/b) + 1 < a and graph[(srcindex/b)+1][srcindex%b] != 'X'){
			heap.push(pp(int(graph[(srcindex/b)+1][srcindex%b]) - 48,pair<int, int>((srcindex/b)+1,srcindex%b)));
		}
		// left
		if((srcindex%b) - 1 >= 0 and graph[srcindex/b][(srcindex%b)-1] != 'X'){
			heap.push(pp(int(graph[srcindex/b][(srcindex%b)-1]) - 48,pair<int, int>(srcindex/b,(srcindex%b)-1)));
		}
		// right
		if((srcindex%b) + 1 < b and graph[srcindex/b][(srcindex%b)+1] != 'X'){
			heap.push(pp(int(graph[srcindex/b][(srcindex%b)+1]) - 48,pair<int, int>(srcindex/b,(srcindex%b)+1)));
		}

		int val = 0;
		while(true){
			auto it = heap.top();
			val = it.first; int i = it.second.first, j = it.second.second;
			heap.pop();

			if(not visited[i][j]){
				if((i*b) + j == destindex)
					break;
				visited[i][j] = 1;

				dist[i][j] = val;

				// add everything around src to pq
				// top
				if(i - 1 >= 0 and graph[i-1][j] != 'X' and visited[i-1][j] == 0){
					heap.push(pp(val + int(graph[i-1][j]) - 48,pair<int, int>(i-1,j)));
				}
				// bottom
				if(i + 1 < a and graph[i+1][j] != 'X' and visited[i+1][j] == 0){
					heap.push(pp(val + int(graph[i+1][j]) - 48,pair<int, int>(i+1,j)));
				}
				// left
				if(j - 1 >= 0 and graph[i][j-1] != 'X' and visited[i][j-1] == 0){
					heap.push(pp(val + int(graph[i][j-1]) - 48,pair<int, int>(i,j-1)));
				}
				// right
				if(j + 1 < b and graph[i][j+1] != 'X' and visited[i][j+1] == 0){
					heap.push(pp(val + int(graph[i][j+1]) - 48,pair<int, int>(i,j+1)));
				}
			}
		}

		cout<<val + 16<<endl;
		
	}

	return 0;
}