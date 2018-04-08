// Beautiful Problem
// the analysis - what question to ask and what to query and what DS to use is beautiful

// one of the biggest mistakes I was making was: A is an excellent contestant
// if no other contestant is better than HIM
// that means a contestant B maybe better than C in all three contests
// but if A is not better than C in all three and A is better than B
// in even one of them, then he can still be an excellent candidate -
// he's not ruled out just because B is better than C in all three and
// A is not better than C in all three

// excellent answer by Eugene Yarovoi - must read
// <https://www.quora.com/What-are-the-advantage-of-binary-indexed-tree-BIT-or-fenwick-tree-over-segment-tree>
// 'min' is not invertible in general like '+', we will not know original values, if min
// values are stored at BIT indices, hence BIT cannot be used for min
// but in this case, we will never query actual values, we will only need min value,
// hence we can actually store min value at the BIT indices - no need of segment tree here

// BIT tute
// <https://theoryofprogramming.wordpress.com/2014/12/24/binary-indexed-tree-or-fenwick-tree/>

// treat ai, bi, ci asymmetrically. We use ci as values and bi as keys in the BIT minval
// queries. Idea is to sort ai's, then for ai highest rank candidate (rank 1) to lowest,
// i.e. sorted order - sorting helps to know all of the higher rank candidates
// do the following: query for the smallest value of cj (possibly infinity - initialize BIT to this)
// for bj in the range [1,bi] and aj < ai (notice how keys and values of BIT allow this)
// We have cj < ci iff contestant i is not an excellent candidate, else he is	
// and finally update bi index with ci
// TLDR: basically, for all aj and bj above i in contest 1 and 2, see if any one of them is above
// i in contest 3 also - if he is, then i is not excellent, else he is

// SET based solution by MISOF - another beautiful approach
// <https://apps.topcoder.com/forums/?module=Thread&threadID=575041&start=0>
// imagine the contestants as points in 3D space. Now fix one of the axis i.e. of the contests
// go from 0 to highest - i.e. from 1st rank to last rank on that axis (i.e. do a sweep)
// when you encounter a candidate, you would have encountered everyone else better than him at
// that axis (contest) - these are the possible candidates who can make this currently being
// considered candidate to be non-excellent - consider - the other two axes of the current candidate
// and see whether he lies within the set or outside - if he lies within the set, it means that his rank
// in other two contests is worse (higher) than atleast one of the already considered candidates (and also
// in the first contest, because he is processed now instead of before) so ignore, else if he lies outside
// the set, he may change the boundary, so update the boundary by going through the relevant set elements
// and then inserting/removing them
// keep the coastline (boundary) as vertices stored in a set, to process a new point, find
// corresponding part of coastline (could be many points - NlogN), check whether it is eliminated, and if not, erase the points it covers
// and add it to the set

// can be done using only one set - set of <x,y> tuples will sort by x first and then y
// go from lowest x to highest x or lowest y to highest y - i.e. in increasing direction (this is important),
// reverse won't work - so, given a new tuple, do a lower bound - it will give first non greater
// tuple, from that tuple move higher, check using other cordinate (i.e. if primary cordinate is x, check using
// y now) - i.e. so in this case, while x cordinate increases, i.e. sweeping right, check if points already in set have
// y cordinate greater than or lesser than y of current candidate - if greater than, remove, if less than, keep
// - can stop once last candidate is removed, no need to continue search further - i.e. break after first
// cordinate you don't remove. if no one removed, no need to add current tuple

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define mp make_pair
#define pb push_back

using namespace std;

bool comparesort(const pair<int,int> & fir, const pair<int,int> & sec){
	return fir.second < sec.second;
}


// took these from INVCNT
bool compare(int i, int j){
	return i < j;
}

// index, value, fenwick tree, size of fenwick tree
void update(int i, int v, int a[], int alen) {
	// instead of sum, update min
    while (i < alen){
    	a[i] = min(a[i],v);
    	i |= i + 1;
    }
}
// index, fenwick tree
int prefixsum(int n, int a[]){
	// instead of sum, calculate min
    int minele = INT_MAX;
    while (n > 0){
    	minele = min(minele,a[n - 1]);
    	n &= n - 1;
    }
    return minele;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int N; scanf("%d", &N);
		vector<pair<int,int> > arr1(N), arr2(N), arr3(N);
		for(int i=0; i<N; ++i){
			arr1[i].first = i; scanf("%d", &arr1[i].second);
			arr2[i].first = i; scanf("%d", &arr2[i].second);
			arr3[i].first = i; scanf("%d", &arr3[i].second);
		}
		sort(arr1.begin(), arr1.end(), comparesort);
		
		int fenwick[N]; // initialize to max value
		for(int i=0; i<N; ++i)
			fenwick[i] = INT_MAX;
		
		// indices fit in very nicely
		int count = 0;
		for(int i=0; i<N; ++i){
			int ranksec = arr2[arr1[i].first].second;
			int minval = prefixsum(ranksec,fenwick);
			if(minval>arr3[arr1[i].first].second)
				++count;
			update(arr2[arr1[i].first].second,arr3[arr1[i].first].second,fenwick,N);
		}
		printf("%d\n", count);
	}
	return 0;
}