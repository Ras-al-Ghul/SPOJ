// sieve, graph of primes, BFS

#include <iostream>
#include <map>
#include <iterator>
#include <queue>

using namespace std;

int main(){
	bool arr[10000] = {}; arr[0] = 1; arr[1] = 1;
	for(int i=2; i<101; ++i){
		if(not arr[i]){
			for(int j=2; i*j<10000; ++j){
				arr[i*j] = 1;
			}
		}
	}

	map<int, int> primes;
	int count = 1;
	// 1009 is indexed with 1
	for(int i=1009; i<10000; ++i){
		if(not arr[i])
			primes.insert(pair<int, int>(i,count++));
	}

	int primesize = primes.size();
	bool graph[primesize+1][primesize+1] = {};
	
	for(auto it=primes.begin(); it!=primes.end(); ++it){
		int cur = it->first, curindex = it->second;
		for(auto itafter = next(it); itafter != primes.end(); ++itafter){
			int curafter = itafter->first, curafterindex = itafter->second;

			int num = 0, tempnum1 = cur, tempnum2 = curafter;
			while(tempnum1 != 0){
				if(tempnum1%10 == tempnum2%10)
					++num;
				tempnum1/=10, tempnum2/=10;
			}
			if(num == 3){
				graph[curindex][curafterindex] = 1, graph[curafterindex][curindex] = 1;
			}
		}
	}

	int ncases;
	scanf("%d", &ncases);
	while(ncases--){
		int start, end, cur = 0;
		scanf("%d %d", &start, &end);
		start = primes.find(start)->second, end = primes.find(end)->second;
		int visited[primesize+1] = {};
		queue<int> bfs;
		
		bfs.push(start);
		visited[start] = start;

		while(bfs.size()){
			cur = bfs.front();
			bfs.pop();
			if(cur == end)
				break;
			for(int i=1; i<=primesize; ++i){
				if(graph[cur][i] and (not visited[i])){
					visited[i] = cur;
					bfs.push(i);
				}
			}
		}

		if(cur == end){
			int cost = 0, ind = end;
			while(visited[ind] != start or ind != start){
				ind = visited[ind]; ++cost;
			}
			printf("%d\n", cost);
		}
		else
			printf("Impossible\n");
	}

	return 0;
}