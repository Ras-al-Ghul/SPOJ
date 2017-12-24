// exploit sorted order
// be careful on how to handle duplicate keys, if they occur - very important
// that is why so many inserts in 'keys' dict below

// <https://www.geeksforgeeks.org/longest-increasing-subsequence/>
// <http://code.cloudkaksha.org/algorithm/dynamic-programming/box-stacking-problem>

#include <iostream>
#include <map>
#include <algorithm>
#include <climits>

#define pii pair<int, int>

using namespace std;

int solve(map<pii, int>& maps, map<pii, int>& keys, pii cur){
	auto keyed = maps.find(cur);
	if(keyed->second != -1){
		return keyed->second;
	}

	int best = 0;
	auto it = maps.begin();
	while(it != keyed){
		if(it->first.first<keyed->first.first and it->first.second<keyed->first.second)
			best = max(best, solve(maps, keys, pii(it->first.first, it->first.second)));
		++it;
	}
	// have to add cur height for both cases, hence handled together instead
	// of this commented out code
	// if(best == 0)
	// 	best = keys.find(cur);

	keyed->second = best + keys.find(cur)->second;
	return keyed->second;
}

int main(){
	int n, temp[3];
	while(true){
		scanf("%d", &n);
		if(n==0)
			break;

		int n_comb = 3*n;
		map<pii, int> maps;
		map<pii, int> keys;

		int count = 0;
		for(int i=0; i<n; ++i){
			scanf("%d %d %d", &temp[0], &temp[1], &temp[2]);
			sort(temp, temp+3);
			
			maps.insert(pair<pii, int>(pii(temp[0],temp[1]), -1));
			if(keys.find(pii(temp[0],temp[1])) != keys.end() and keys.find(pii(temp[0],temp[1]))->second<temp[2])
				keys.find(pii(temp[0],temp[1]))->second = temp[2];
			else if(keys.find(pii(temp[0],temp[1])) == keys.end())
				keys.insert(pair<pii,int>(pii(temp[0],temp[1]),temp[2]));
			
			maps.insert(pair<pii, int>(pii(temp[1],temp[2]), -1));
			if(keys.find(pii(temp[1],temp[2])) != keys.end() and keys.find(pii(temp[0],temp[1]))->second<temp[0])
				keys.find(pii(temp[1],temp[2]))->second = temp[0];
			else if(keys.find(pii(temp[1],temp[2])) == keys.end())
				keys.insert(pair<pii,int>(pii(temp[1],temp[2]),temp[0]));

			maps.insert(pair<pii, int>(pii(temp[0],temp[2]), -1));
			if(keys.find(pii(temp[0],temp[2])) != keys.end() and keys.find(pii(temp[0],temp[2]))->second<temp[1])
				keys.find(pii(temp[0],temp[2]))->second = temp[1];
			else if(keys.find(pii(temp[0],temp[2])) == keys.end())
				keys.insert(pair<pii,int>(pii(temp[0],temp[2]),temp[1]));
		}

		maps.insert(pair<pii, int>(pii(INT_MAX,INT_MAX),-1));
		keys.insert(pair<pii, int>(pii(INT_MAX,INT_MAX),0));
		
		solve(maps, keys, pii(INT_MAX,INT_MAX));
		printf("%d\n", maps.find(pii(INT_MAX,INT_MAX))->second);
	}
	return 0;
}