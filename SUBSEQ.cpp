#include <iostream>
#include <map>
#include <set>

#define mp make_pair

using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n); int ans = 0;
		map<int, set<int> > sums;
		int cumularr[n] = {}; int temp;
		scanf("%d", &cumularr[0]);sums[cumularr[0]].insert(0);
		sums[0].insert(-1);
		if(cumularr[0] == 47)
			++ans;
		for(int i=1; i<n; ++i){
			scanf("%d", &temp);
			cumularr[i] = cumularr[i-1] + temp;
			temp = cumularr[i] - 47;
			if(sums.find(temp) != sums.end())
				ans += sums[temp].size();
			// very important to do this after the counting
			sums[cumularr[i]].insert(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}