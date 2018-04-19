// found out how to delete just one item if multiple are present in multiset
// find that element's iterator and erase(iter)

// time complexities of these kind of schedule questions are generally O(nlogn)
// which is the complexity of sorting

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define pq priority_queue
#define mp make_pair

using namespace std;

int main(){
	int t, n, a, b; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		pq <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > entries;
		multiset<int> alreadydone;
		vector<pair<int, int> > times(2*n);
		vector<pair<int, int> > beginsorted(n);
		for(int i=0; i<n; ++i){
			scanf("%d %d", &a, &b);
			times[2*i].first = a; times[2*i].second = 1; // start comes first
			times[2*i+1].first = b; times[2*i+1].second = 2; // end comes later
			beginsorted[i].first = a; beginsorted[i].second = b;
		}
		sort(times.begin(), times.end());
		sort(beginsorted.begin(), beginsorted.end());
		int bscount = 0, ans = 0;
		for(int i=0; i<2*n; ++i){
			if(times[i].second == 2){
				if(alreadydone.find(times[i].first)!=alreadydone.end()){
					auto itr = alreadydone.find(times[i].first);
					if(itr!=alreadydone.end())
						alreadydone.erase(itr);
				}
				else{
					while(not entries.empty() and entries.top().first<=times[i].first){
						alreadydone.insert(entries.top().second);
						entries.pop();
					}
					auto itr = alreadydone.find(times[i].first);
					if(itr!=alreadydone.end())
						alreadydone.erase(itr);
					++ans;
				}
			}
			else{
				entries.push(mp(beginsorted[bscount].first,beginsorted[bscount].second));
				++bscount;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}