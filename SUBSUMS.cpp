// cannot use the technique of MAIN72 because range of A and B
// is frickin huge -500000000 <= A <= B <= 500000000
// cannot maintain array that huge

// works for non distinct elements also
// pretty much a literal implementation of meet in the middle
// <https://www.geeksforgeeks.org/meet-in-the-middle/>
// divide arr into two halves, calculate sum for all possible subsets of each
// then for each in all subsets of first half, query range in all subsets of second half
// notice what lower_bound and upper_bound returns, hence if, else condition necessary - arr2.end()

// <http://www.cplusplus.com/reference/algorithm/lower_bound/>
// <http://www.cplusplus.com/reference/algorithm/upper_bound/>

// iterating over subsets code
// <https://stackoverflow.com/questions/1683241/iterating-over-subsets-of-any-size>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main(){
	int n, a, b; scanf("%d %d %d", &n, &a, &b);
	int arr[n];
	for(int i=0; i<n; ++i)
		scanf("%d", &arr[i]);
	
	// all possible subsets of size n/2
	int mid = n/2;
	int s1 = 1<<mid, s2 = 1<<(n-mid);
	vector<int> arr1(s1,0), arr2(s2,0);
	
	for(int i = 0; i < s1; i++){
		for(int j = 0; j < mid; j++){
			if(i & 1<<j) 
				arr1[i] += arr[j];
		}
	}
	// for(int i=0; i<s1; ++i)
	// 	printf("%d ", arr1[i]);
	// cout<<endl;

	for(int i=0; i < s2; i++){
		for(int j=0; j < (n-mid); j++){
			if(i & 1<<j)
				arr2[i] += arr[j+mid];
		}
	}
	sort(arr2.begin(), arr2.end());
	// for(int i=0; i<s2; ++i)
	// 	printf("%d ", arr2[i]);
	// cout<<endl;

	long long int count = 0;
	for(int i=0; i<s2; ++i)
		if(arr2[i]>=a and arr2[i]<=b)
			++count;
	// cout<<count<<endl;
	for(int i=1; i<s1; ++i){
		auto it1 = lower_bound(arr2.begin(),arr2.end(),a-arr1[i]);
		auto it2 = upper_bound(arr2.begin(),arr2.end(),b-arr1[i]);
		// cout<<arr1[i]<<" "<<(*it1)<<" "<<(*it2)<<" "<<(it2-it1)<<endl;
		// this if else is needed because of what lower_bound and upper_bound return
		if(it1 != arr2.end()){
			if(it2 == arr2.end()){
				if((*prev(it2)) <= b-arr1[i])
					count += (long long int)(it2-it1);
			}
			else
				count += (long long int)(it2-it1);
		}
	}
	printf("%lld\n", count);
	return 0;
}