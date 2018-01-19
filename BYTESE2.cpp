#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		pair<int,int> arr[n*2];
		for(int i=0; i<2*n; i+=2){
			scanf("%d %d", &arr[i].first, &arr[i+1].first);
			arr[i].second = 0; arr[i+1].second = 1;
		}
		sort(arr, arr+(2*n));
		int maxi = 0, counter = 0;
		for(int i=0; i<(2*n); ++i)
			if(arr[i].second == 0)
				counter++, maxi = max(maxi, counter);
			else
				counter--;
		printf("%d\n", maxi);
	}
	return 0;
}