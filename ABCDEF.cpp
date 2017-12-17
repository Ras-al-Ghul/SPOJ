// map is not always good - when multiple inserts - better to sort at once
// distance(it1, it2) from std::iterator gives number of elements between it1 and it2

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	long arr[n];
	for(int i=0; i<n; ++i){
		scanf("%ld", &arr[i]);
	}

	long rhs[n*n*n];
	long count = 0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			for(int k=0; k<n; ++k){
				if(arr[k] != 0){
					rhs[count++] = (arr[i]+arr[j])*arr[k];
				}
			}
		}
	}

	sort(rhs, rhs+count);
	long result = 0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			for(int k=0; k<n; ++k){
				auto it1 = lower_bound(rhs, rhs+count, arr[i]*arr[j] + arr[k]);
				auto it2 = upper_bound(rhs, rhs+count, arr[i]*arr[j] + arr[k]);
				result += (distance(it1, it2));
			}
		}
	}
	printf("%ld\n", result);

	return 0;
}