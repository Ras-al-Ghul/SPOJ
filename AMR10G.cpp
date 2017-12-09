// simple sort and maintain best so far

#include <iostream>
#include <algorithm>

#define ul unsigned long

using namespace std;

int main(){
	int ncases;
	scanf("%d", &ncases);
	while(ncases--){
		ul n, k;
		scanf("%lu %lu", &n, &k);
		ul arr[n];
		for(int i=0; i<n; ++i)
			scanf("%lu", &arr[i]);
		sort(arr, arr+n);
		
		if(k == 1){
			printf("0\n");
			continue;
		}

		ul diff[n-1];
		ul minim = 1000000001;
		ul index = 0;
		ul sum = 0;
		for(int i=0; i<k-2; ++i){
			diff[i] = (arr[i+1] - arr[i]);
			sum += diff[i];
		}

		for(int i=k-2; i<n-1; ++i){
			diff[i] = (arr[i+1] - arr[i]);
			sum += diff[i];

			if(sum < minim){
				minim = sum;
				index = i+1;
			}

			sum -= diff[i-k+2];
		}
		printf("%lu\n", arr[index]-arr[index-k+1]);
	}
	return 0;
}