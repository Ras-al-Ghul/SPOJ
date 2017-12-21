// some tricky edge cases
// here we want lowest index occuring key with binary search

#include <iostream>
#include <algorithm>

using namespace std;

int binsearch(int arr[], int low, int high, int key){
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid] == key){
			int i = mid;
			while(arr[i-1] == key){
				i--;
			}
			return i;
		}
		else
			if(arr[mid] > key)
				high = mid-1;
			else
				low = mid + 1;
	}
	int i = low;
	while(arr[i] < key and i < high){
		i++;
	}
	return i;
}

int main(){
	int n;
	while(true){
		scanf("%d", &n);
		if(n == 0)
			break;
		int arr[n];
		for(int i=0; i<n; ++i)
			scanf("%d", &arr[i]);
		
		sort(arr, arr+n, less<int>());

		long count = 0;

		for(int i=0; i<n-1; ++i){
			for(int j=i+1; j<n; ++j){
				int sum = arr[i] + arr[j];
				int index = binsearch(arr, j+1, n-1, sum+1);
				count += (n-index);
				if((n-index) == 0)
					break;
			}
		}
		cout<<count<<endl;
	}

	return 0;
}