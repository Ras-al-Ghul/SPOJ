// the thing to notice here is that each consecutive two towers along
// length will influence all other consecutive two towers along
// breadth and vice versa
// so find max consecutive two along length, same along breadth,
// product is the answer

#include <iostream>
#include <algorithm>
#include <vector>

#define pb push_back

using namespace std;

int main(){
	int t, w, h, n, a, b, i, j; scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &w, &h, &n);
		vector<int> horz, vert;
		for(i=0; i<n; ++i){
			scanf("%d %d", &a, &b); horz.pb(a); vert.pb(b);
		}
		horz.pb(0); horz.pb(w+1);
		vert.pb(0); vert.pb(h+1);
		sort(horz.begin(), horz.end());
		sort(vert.begin(), vert.end());
		a = 0;
		for(i=0; i<horz.size()-1; ++i){
			a = max(a, horz[i+1]-horz[i]-1);
		}
		b = 0;
		for(j=0; j<vert.size()-1; ++j){
			b = max(b, vert[j+1]-vert[j]-1);
		}
		printf("%d\n", a*b);
	}
	return 0;
}