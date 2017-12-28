#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int ncases;
	scanf("%d", &ncases);
	int n; string name;
	float val;
	while(ncases--){
		scanf("%d", &n);
		float arr[n];
		float diff = 0.0f;
		for(int i=0; i<n; ++i){
			cin>>name; scanf("%f", &arr[i]);
		}
		sort(arr, arr+n);
		float maxi = 360.0f - arr[n-1] + arr[0];
		for(int i=1; i<n; ++i){
			maxi = max(maxi, arr[i]-arr[i-1]);
		}
		printf("%d\n", int(ceil((360.0f - maxi) * 12.0f)));
	}

	return 0;
}