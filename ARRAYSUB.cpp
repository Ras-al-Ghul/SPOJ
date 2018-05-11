// given array n and window of size k, k<=n, for each sliding window (continguos subarray),
// output the maximum element in that window

// first solution was to use heaps, storing the indices, works fine, but O(nlogn)

// second solution using deque is O(n)
// remove redundant elements - every element is inserted or removed once
// and all the add and remove element happen from front or back (unlike heap, where insert takes log(n) time)
// at each point in time, front of queue will contain maximum element of that sliding window
// when you come across a new element, pop all elements in deque from back which are less than new element
// because they are now irrelevant
// pop all elements from front which are out of index (left border)

#include <iostream>
#include <queue>

#define pq priority_queue
#define mp make_pair

using namespace std;

int main(){
	int n, k, i; scanf("%d", &n);
	int arr[n];
	for(i=0; i<n; ++i)
		scanf("%d", &arr[i]);
	scanf("%d", &k);
	// pq <pair<int,int>, vector<pair<int,int> >, less<pair<int,int > > > ds;

	// for(i=0; i<k; ++i)
	// 	ds.push(mp(arr[i],i));
	// printf("%d ", ds.top().first);
	// int left = 1;
	// for(; i<n; ++i){
	// 	ds.push(mp(arr[i],i));
	// 	while(ds.top().second < left)
	// 		ds.pop();
	// 	printf("%d ", ds.top().first);
	// 	++left;
	// }
	// printf("\n");

	// using a deque is O(n)
	deque<pair<int,int> > ds;
	for(i=0; i<k; ++i){
		while((not ds.empty()) and ds.back().first <= arr[i])
			ds.pop_back();
		ds.push_back(mp(arr[i],i));
	}
	for(; i<n; ++i){
		printf("%d ", ds.front().first);
		while((not ds.empty()) and ds.back().first <= arr[i])
			ds.pop_back();
		ds.push_back(mp(arr[i],i));
		while((not ds.empty()) and ds.front().second < i+1-k)
			ds.pop_front();
	}
	if(i == n and n > 0)
		printf("%d\n", ds.front().first);

	return 0;
}