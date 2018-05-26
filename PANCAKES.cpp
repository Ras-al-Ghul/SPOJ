#include <iostream>
#include <climits>

using namespace std;

int main(){
	int n, r, avail, ip, i, j, maxs, maxind;
	while(scanf("%d %d", &n, &r)==2){
		if(n==0)
			break;
		int arr[r], availarr[n];
		for(i=0; i<r; ++i)
			arr[i] = INT_MAX;
		for(i=0; i<n; ++i){
			scanf("%d", &availarr[i]);
			availarr[i] *= 10;
			// otherwise you'll just do 
			// arr[i] = min(arr[i], (availarr[j]/ip)*10);
			// not a big difference
		}
		maxind = 0; maxs = 0;
		for(i=0; i<r; ++i){
			for(j=0; j<n; ++j){
				scanf("%d", &ip);
				if(ip)
					arr[i] = min(arr[i], availarr[j]/ip);
			}
			// otherwise you can make infinite pancakes
			if(arr[i]==INT_MAX)
				continue;
			if(maxs<arr[i]){
				maxs = arr[i]; maxind = i;
			}				
		}
		printf("%d %d\n", maxind+1, maxs);
	}
	return 0;
}