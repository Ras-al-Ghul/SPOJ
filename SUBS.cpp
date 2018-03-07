// strchr - finds first occurence of character in cstring

#include <iostream>
#include <cstring>
#include <vector>

#define pb push_back
#define mp make_pair

using namespace std;

const int MAX = 500015;

int main(){
	int n; scanf("%d", &n);
	while(n--){
		char x[MAX], y[MAX];
		scanf("%s", x); scanf("%s", y);
		int xsize = strlen(x), ysize = strlen(y);

		// first is int(char), second is number of times
		vector<pair<char, int> > arrx;
		int count;
		for(int i=0; i<xsize; ){
			char c = x[i]; count = 0;
			while(x[i] == c){
				++i; ++count;
			}
			arrx.pb(mp(c, count));
		}

		int low = 0, high = 1, mid;
		while((xsize*high) <= ysize)
			++high;
		--high;
		
		int xs = arrx.size();
		while(low < high){
			mid = low + (high-low)/2;
			if(mid == low)
				++mid;
			bool flag = true; int ind = 0;
			char c; int cur; char * cp;
			for(int i=0; i<xs; ++i){
				c = arrx[i].first;
				cur = arrx[i].second * mid;
				for(int j=0; j<cur; ++j){
					cp = strchr(y+ind, c);
					if(cp == nullptr){
						flag = false; break;
					}
					ind = (cp-y)+1;
				}
				if(not flag)
					break;
			}
			if(flag){
				low = mid;
			}
			else{
				high = mid-1;
			}
		}
		printf("%d\n", low);
	}
	return 0;
}