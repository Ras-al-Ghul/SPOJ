// linear DP - O(n+m) solution

#include <iostream>

using namespace std;

int main(){
	long a, b;
	while(true){
		scanf("%ld", &a);
		if(a == 0)
			break;

		long arr1[a];
		for(long i=0; i<a; ++i)
			scanf("%ld", &arr1[i]);

		scanf("%ld", &b);
		long arr2[b];
		for(long i=0; i<b; ++i)
			scanf("%ld", &arr2[i]);

		long sumfirst = 0, sumsecond = 0, totalsum = 0;
		long secondind = 0;
		for(long i=0; i<a; ++i){
			sumfirst += arr1[i];
			while(arr2[secondind] < arr1[i] and secondind < b){
				sumsecond += arr2[secondind];
				++secondind;
			}
			if(arr1[i] == arr2[secondind] and secondind < b){
				sumsecond += arr2[secondind];
				++secondind;
				totalsum += max(sumfirst, sumsecond);
				sumfirst = 0;
				sumsecond = 0;
			}
		}
		while(secondind < b){
			sumsecond += arr2[secondind];
			++secondind;
		}
		totalsum += max(sumfirst, sumsecond);
		cout<<totalsum<<endl;
	}
	return 0;
}