#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n, f; scanf("%d %d", &n, &f);
		int arr[n];
		for(int i=0; i<n; ++i){
			scanf("%d", &arr[i]);
			arr[i] *= arr[i];
		}

		sort(arr, arr+n);
		double low = 0.0, high = 4e8;
	
		for(int it=0; it<43; ++it){
			double mid = low + (high-low)/2;
			int counter = 0;
			for(int i=n-1; i>=0 and counter<(f+1); --i)
				counter+=int(floor(M_PI*arr[i]/mid));
			if(counter >= f+1)
				low = mid;
			else
				high = mid;
		}
		printf("%.4lf\n", low);
	}
	return 0;
}