// Fenwick 0.1s Merge 0.06s

// Merge is pretty standard

// Fenwick tree - both update and prefix sum are O(logn)
// using no additional space - that is the best part

// simplest and most beautiful explanation - read update and prefixsum from there
// <https://notes.tweakblogs.net/blog/9835/fenwick-trees-demystified.html>
// no need of extra '0' node in Fenwick tree as per above

// now inversion count using Fenwick tree
// first step is to normalize data to 0 to n-1 where n is number of elements
// this can be done as follows:
// 2 3 8 6 1 (1 2 3 4 5)
// sort --> 1 2 3 6 8 (5 1 2 3 4)--i {1 2 3 4 5}--j
// at index i, put j, so at 5, put 1 --> 2 3 5 4 1 - normalized

// next process from end of arr to front
// calc prefixsum(1) in Fenwick tree, add to inversions_count
// nothing in tree, no inversions, next update by adding 1 at index 1
// calc prefixsum(4) in Fenwick tree - 
// when you calculate prefix sum, you'll add 1 from 1 - hence 1 inversion
// next update by adding 1 at index 4
// calc prefixsum(5) in Fenwick tree - 1 from 1, 1 from 4
// update by adding 1 at index 5
// calc prefixsum(3) - 1 inversion - from 1 at 1
// update by adding 1 at index 3
// calc prefixsum(2) - 1 inversion - from 1 at 1
// update by adding 1 at index 2
// total of 5 inversions

// since one of the tags was bitmask, I read about it too
// TSP using bitmask <https://codingblocks.com/resources/travelling-salesman/>
// better than Held Karp which uses Map for memoization
// more general DP and bitmasking
// <https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/>
// bitmask used to generate all possible subsets - check which bits are set to determine which subset
// set enumeration problems
// if 4 cities
// for TSP - int dp[16][4] - 2^4 subsets - of which only 8 are relevant - because we always start with 1
// so ---1 where - can be 0 or 1
// 4 elements in each row - each will hold cost of best path through that city
// out of all possible unvisited cities, do ans = min(ans, newans)
// N persons, N tasks can also be done using bit-masking
// state: k represents persons 0 to k-1 have been assigned, mask - ith task assigned or not
// answer(k+1,mask|(1<<i))=min(answer(k+1,mask|(1<<i)),answer(k,mask)+cost[k][i])
// answer(mask|(1<<i))=min(answer(mask|(1<<i)),answer(mask)+cost[x][i])
// RHS is so because we will iterate through all i
// notice that in both TSP and assignment problem, you do ans = min(ans, curans)

#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>

#define ll long long

using namespace std;

// ll merge(ll arr[], ll larr[], ll rarr[], ll left, ll right, ll mid){
// 	ll inv = 0;
// 	ll index = left;
// 	ll lindex = 0, rindex = 0;
// 	while(lindex < mid and rindex < right-mid){
// 		if(larr[lindex] < rarr[rindex]){
// 			arr[index++] = larr[lindex++];
// 		}
// 		else{
// 			arr[index++] = rarr[rindex++];
// 			inv += (mid-lindex);
// 		}
// 	}
// 	if(lindex == mid)
// 		while(rindex < right-mid){
// 			arr[index++] = rarr[rindex++];
// 		}
// 	else
// 		while(lindex < mid){
// 			arr[index++] = larr[lindex++];
// 		}
// 	return inv;
// }

// ll invcnt(ll arr[], ll left, ll right){
// 	if(right-left<=1)
// 		return 0;

// 	ll mid = (left+right)/2;
	
// 	ll larr[mid];
// 	for(ll i=0; i<mid; ++i)
// 		larr[i] = arr[i];
	
// 	ll rarr[right-mid];
// 	for(ll i=mid; i<right; ++i)
// 		rarr[i-mid] = arr[i];

// 	ll inv = 0;
// 	inv += invcnt(larr, 0, mid);
// 	inv += invcnt(rarr, 0, right-mid);
// 	inv += merge(arr, larr, rarr, left, right, mid);
// 	return inv;
// }

bool compare(ll i, ll j){
	return i < j;
}

// index, value, fenwick tree, size of fenwick tree
void update(ll i, ll v, ll a[], ll alen) {
    while (i < alen){
    	a[i] += v;
    	i |= i + 1;
    }
}
// index, fenwick tree
ll prefixsum(ll n, ll a[]){
    ll sum = 0;
    while (n > 0){
    	sum += a[n - 1];
    	n &= n - 1;
    }
    return sum;
}

int main()
{
	ll ncases;
	scanf("%lld", &ncases);
	while(ncases--){
		ll n;
		scanf("%lld", &n);
		
		// // merge based solution
		// ll arr[n];
		// for(ll i=0; i<n; ++i)
		// 	scanf("%lld", &arr[i]);
		
		// printf("%lld\n", invcnt(arr, 0, n));

		ll arr[n]; ll temp[n];
		for(ll i=0; i<n; ++i){
			scanf("%lld", &arr[i]);
			temp[i] = arr[i];
		}
		
		// for compression
		sort(temp, temp + n, compare);
		
		for(ll i=0; i<n; ++i)
			// lower_bound returns pointer, hence subtract from start of list pointer
			arr[i] = lower_bound(temp, temp+n, arr[i], compare) - temp + 1;

		// for(ll i=0; i<n; ++i)
		// 	cout<<arr[i]<<" ";
		// cout<<endl;

		ll invcnt = 0;
		ll fenwick[n] = {};
		for(ll i=n-1; i>=0; --i){
			invcnt += prefixsum(arr[i], fenwick);
			update(arr[i], 1, fenwick, n);
		}
		// for(ll i=0; i<=n; ++i)
		// 	cout<<fenwick[i]<<" ";
		// cout<<endl;
		printf("%lld\n", invcnt);
	}
	return 0;
}

