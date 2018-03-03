// sorting + two pointer
// this code (method?) doesn't work for arrays with duplicate elements
// binary search method would be - sort, with every element as key, binary search for k-(key)
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int arr[n];
	for(int i=0; i<n; ++i)
		scanf("%d", &arr[i]);
	
	sort(arr, arr+n);
	int count = 0;
	int first = 0, second = 1;
	while(second != n){
		if(arr[second]-arr[first] == k){
			++count;
			++second;
		}
		else if(arr[second]-arr[first] > k and (first+1 != second)){
			++first;
		}
		else{
			++second;
		}
	}
	printf("%d\n", count);
	return 0;
}