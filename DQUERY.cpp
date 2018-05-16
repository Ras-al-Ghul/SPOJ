// Beautiful Problem: Offline processing:

// converts range query [a,b] to a form where prefix sum [1,b]
// can be used albeit maintaining the correct information in the tree
// and updating at appropriate times 
// can use MO's algorithm which is square root decomposition, but that
// is done in another problem
// can also use Persistent Segment trees with Online querying
// <https://www.quora.com/Is-there-any-way-to-solve-the-dquery-problem-on-SPOJ-using-persistent-segment-trees-an-online-solution>
// again done in another problem
// both topics are on Anudeep's blog

// The result of a query [a, b] is number of integers whose last occurrence in [1, b] is >= a.

// Let's have two kinds of events: QueryEvent and NumberEvent.
// First we read whole input and sort all events,
// the key for QueryEvents are their end (i.e. b for query [a, b]),
// and for NumberEvents the key is their position in array.

// We also have a segment tree which answers the queries of kind:
// how many elements (1s) are at position range [x, y]. Initially the tree is empty.

// Then we process events in order:
//   + When we meet a NumberEvent:
//     1. If number has occurred before at position p, we remove p from segment tree - point update.
//     2. We add position of number to the segment tree - point update.
//   + When we meet a QueryEvent:
//     - Query the segment tree in the given range, and find the answer.

// The overall time complexity of algorithm is O( (n + q) log n + (n + q) log (n + q) )

#include <iostream>
#include <algorithm>
#include <vector>

#define mp make_pair
#define pb push_back

using namespace std;

const int MAXN = 30001;
const int QUERIES = 200001;

typedef struct node{
	int key, val, type, queryind = -1;
	// queryind is to help with reordering the queries as per order in question
}NODE;

NODE arr[MAXN+QUERIES];
int lastoccur[1000001] = {};

bool compare(const NODE a, const NODE b){
	// important that the NumberEvent occurs before the QueryEvent
	// hence type of NumberEvent is 0 and type of QueryEvent is 1
	if(a.key != b.key)
		return a.key < b.key;
	else
		return a.type < b.type;
}

// index, value, fenwick tree, size of fenwick tree
void update(int i, int v, int a[], int alen) {
    while (i < alen){
    	a[i] += v;
    	i |= i + 1;
    }
}
// index, fenwick tree
int prefixsum(int n, int a[]){
    int sum = 0;
    while (n > 0){
    	sum += a[n - 1];
    	n &= n - 1;
    }
    return sum;
}

int main(){
	int n, i, j, q;
	scanf("%d", &n);
	
	for(i=0; i<n; ++i){
		scanf("%d", &arr[i].val); arr[i].key = i; arr[i].type = 0;
	}
	scanf("%d", &q);
	for(i=n; i<n+q; ++i){
		scanf("%d %d", &arr[i].val, &arr[i].key);
		--arr[i].val; --arr[i].key; arr[i].queryind = i-n;
		arr[i].type = 1;
	}
	sort(arr, arr+n+q, compare);

	int fenwick[n] = {};
	vector<pair<int, int> > queryinorder;
	for(i=0; i<n+q; ++i){
		if(arr[i].type == 0){
			if(lastoccur[arr[i].val] != 0){
				// -1 in lastoccur[arr[i].val]-1 is imp
				// this makes it easier to check the above if condition
				// else have to memset lastoccur to -1
				update(lastoccur[arr[i].val]-1, -1, fenwick, n);
			}
			lastoccur[arr[i].val] = arr[i].key+1;
			update(lastoccur[arr[i].val]-1, 1, fenwick, n);
		}
		else{
			j = prefixsum(arr[i].key+1, fenwick) - prefixsum(arr[i].val, fenwick);
			queryinorder.pb(mp(arr[i].queryind,j));
		}
	}
	sort(queryinorder.begin(), queryinorder.end());
	for(i=0; i<q; ++i)
		printf("%d\n", queryinorder[i].second);
	return 0;
}