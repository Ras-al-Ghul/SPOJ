#include <iostream>
#include <algorithm>

using namespace std;

int nck(int n, int k){
	if(k == 0)
		return 1;
	return (n*nck(n-1,k-1))/k;
}

int main(){
	int n, k;
	while(scanf("%d %d", &n, &k) ==2){
		int arr[k];
		for(int i=0; i<k; ++i)
			scanf("%d", &arr[i]);
		sort(arr, arr+k);
		int ans = 1, remaining = n;
		for(int i=k-1; i>=0; --i){
			if(arr[i] == 0)
				break;
			ans *= nck(remaining,arr[i]);
			remaining -= arr[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}