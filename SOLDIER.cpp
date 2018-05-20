// notice that somehow an umbrella man kinda for each rupee spent
// what is the best possible buy kinda approach is possible - bottom up
// but then you have 6 items, one of each kind, how to go about all possible
// combinations of these - the trick is to realize that ordering doesn't
// matter - so do for 1 item in first iteration, do for 2 items in second,
// do for 3 items in third,.. - for 3 items in third, you already know
// best possible for given price for 2 items, so consider each third item
// at given price point and subtract its price - find best from 2 items given
// this subtracted price - so bottom-up
// to make it more efficient, no need to do for each item at every price point
// - sort by price and do a[i] = a[i-1] i.e. copy previous best to current,
// then see if current improves - take care because higher price may not mean
// higher quality - to handle this keep track of best quality seen so far at
// previous iterations (at lower price in other words) - and apply that item
// too to see if it improves total quality

#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

int main(){
	int n, t, i, j, k, l, m; scanf("%d %d", &n, &t);
	vector<vector<pair<int,int> > > e(6);
	for(i=0; i<n; ++i){
		scanf("%d %d %d", &j, &k, &l); e[j-1].pb(mp(k,l));
	}
	for(i=0; i<6; ++i)
		sort(e[i].begin(), e[i].end());

	l=6; int arr[l][t+1] = {};
	// do separately for item at index 0
	if(e[0].size()==0 or e[1].size()==0 or e[2].size()==0 or e[3].size()==0 or e[4].size()==0 or e[5].size()==0){
		printf("0\n"); return 0;
	}
	l = 0;
	for(j=1; j<=t; ++j){
		arr[0][j] = arr[0][j-1];
		while(e[0][l].first <= j){
			arr[0][j] = max(arr[0][j], e[0][l].second);
			if(l+1 == e[0].size()) break;
			else ++l;
		}
	}
	// for(i=0; i<=t; ++i){
	// 	cout<<i<<" "<<arr[0][i]<<endl;
	// }
	for(i=1; i<6; ++i){
		l = 0; int b = e[i][0].second, bp = e[i][0].first;
		for(j=1; j<=t; ++j){
			arr[i][j] = arr[i][j-1];
			while(e[i][l].first < j){
				k = arr[i-1][j-e[i][l].first];
				k = min(k, e[i][l].second);
				arr[i][j] = max(arr[i][j], k);
				if(e[i][l].second <= b){
					m = min(b, arr[i-1][j-bp]);
					arr[i][j] = max(arr[i][j],m);
				}
				else{
					b = e[i][l].second; bp = e[i][l].first;
				}
				if(l+1 == e[i].size()) break;
				else if(k!=0) ++l;
				else break;
			}
		}
		// if(i==2){
		// 	for(l=0; l<=t; ++l){
		// 		cout<<l<<" "<<arr[2][l]<<endl;
		// 	}
		// }
	}
	printf("%d\n", arr[5][t]);
	return 0;
}