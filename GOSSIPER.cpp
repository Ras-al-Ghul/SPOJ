// can try bitwise OR, instead of Set union, will be much faster
// was almost a second faster

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <bitset>

#define mp make_pair

using namespace std;

int main(){
	int N, M, fir, sec; string n1, n2;
	while(scanf("%d %d", &N, &M) == 2){
		if(N==0)
			break;
		map<string, int> pairs;
		// set<int> g[N];
		bitset<2100> bits[N] = {};
		for(int i=0; i<N; ++i){
			cin>>n1;
			pairs.insert(mp(n1,i));
			// g[i].insert(i);
			bits[i][i] = 1;
		}
		for(int i=0; i<M; ++i){
			cin>>n1>>n2;
			fir = pairs.find(n1)->second;
			sec = pairs.find(n2)->second;
			// for(auto it=g[fir].begin(); it != g[fir].end(); ++it)
			// 	g[sec].insert(*it);
			// for(auto it=g[sec].begin(); it != g[sec].end(); ++it)
			// 	g[fir].insert(*it);
			bits[fir] |= bits[sec];
			bits[sec] |= bits[fir];
		}
		bool flag = true;
		for(int i=0; i<N; ++i){
			// if(g[i].size() != N){
			// 	flag = false; break;
			// }
			if(bits[i].count() != N){
				flag = false; break;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}