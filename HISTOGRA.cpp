// RMQ takes 0.1 - O(nlogn), Stack takes 0.04 - O(n)

// Material links: 
// upvoted answers in this - <https://www.quora.com/What-is-the-algorithmic-approach-to-find-the-maximum-rectangular-area-in-a-histogram>

// RMQ based: in a given range, find minimum height - that height * range width is one possible area
// recurse to left of this bar, and to right of this bar
// take best of the three
// to find minimum height = use Segment Tree - for RMQ queries

// Stack based: Two passes - one from left, one from right
// arrleftpos and arrrightpos - for each index, it indicates
// number of left (right) contiguous blocks - sum left + right to get
// continguous block that includes that index - multiply with height of that
// index to get area - do for all indices
// to do this, you need two stacks - one to store values, the other to store number of indices
// let's see how to do it for left pass
// while current index val is less than equal to stack top, keep popping
// keep track of indices too - the current val at this index can be extended to the left by that many indices
// if curval > stacktop, push on top of stack
// similar for right pass
// to do everything in one pass, calculate area on popping
// maxarea = max(maxarea, curarea)
// for each popped element, it can extend to right (previous popped elements), but not to left - hence update count using number of indices stack

// this is a special case of All Nearest Smaller Values problem - which exhibits stack based solutions

#include <iostream>
#include <stack>
#include <cmath>
#include <climits>

#define ll long long
#define pll pair<long long, long long>

using namespace std;

void createTree(ll arr[][2], ll inputarr[], ll low, ll high, ll pos){
	if(low == high){
		// set it for leaf nodes, it is trivial
		arr[pos][0] = inputarr[low];
		arr[pos][1] = low;
		return;
	}

	int mid = low + ((high-low)/2);

	int leftchild = (2*pos) + 1;
	int rightchild = (2*pos) + 2;

	createTree(arr, inputarr, low, mid, leftchild);
	createTree(arr, inputarr, mid+1, high, rightchild);

	arr[pos][0] = min(arr[leftchild][0], arr[rightchild][0]);
	arr[pos][1] = arr[pos][0] == arr[leftchild][0] ? arr[leftchild][1] : arr[rightchild][1];
	return;
}

pll rangeMinQuery(ll arr[][2], ll qlow, ll qhigh, ll low, ll high, ll pos){
	// total overlap
	if(qlow <= low and qhigh >= high){
		return pll(arr[pos][0], arr[pos][1]);
	}
	// no overlap
	if(qlow > high or qhigh < low){
		return pll(LLONG_MAX, -1);
	}

	// partial overlap
	int mid = low + ((high-low)/2);

	int leftchild = (2*pos) + 1;
	int rightchild = (2*pos) + 2;

	pll temp1 = rangeMinQuery(arr, qlow, qhigh, low, mid, leftchild);
	pll temp2 = rangeMinQuery(arr, qlow, qhigh, mid+1, high, rightchild);

	ll temp = min(temp1.first, temp2.first);
	ll tempindex = temp == temp1.first ? temp1.second : temp2.second;
	return pll(temp, tempindex);
}

ll calcMaxArea(ll treearr[][2], ll sizeofarr, ll begin, ll end){
	pll minnow = rangeMinQuery(treearr, begin, end, 0, sizeofarr - 1, 0);

	if(minnow.first == LLONG_MAX)
		return 0;
	ll curarea = (end-begin+1)*minnow.first;
	
	ll left = calcMaxArea(treearr, sizeofarr, begin, minnow.second-1);
	ll right = calcMaxArea(treearr, sizeofarr, minnow.second+1, end);

	return max(curarea, max(left, right));
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(not n)
			break;
		ll arr[n];
		for(int i=0; i<n; ++i)
			scanf("%lld", &arr[i]);
		
		// Stack based solution
		// ll maxarea = 0;

		// // first holds height, second holds count
		// stack<pll > height;
		// for(int i=0; i<n; ++i){
		// 	ll count = 0;
		// 	while(height.size() and height.top().first >= arr[i]){
		// 		maxarea = max(maxarea, height.top().first*(height.top().second+1+count));
		// 		count += (height.top().second + 1);
		// 		height.pop();
		// 	}
		// 	// nothing has been popped case is also taken care of
		// 	// count will be 0 in that case
		// 	height.push(pll(arr[i], count));
		// }
		// ll count = 0;
		// while(not height.empty()){
		// 	maxarea = max(maxarea, height.top().first*(height.top().second+1+count));
		// 	count += (height.top().second+1);
		// 	height.pop();
		// }
		// printf("%lld\n", maxarea);




		// Range Min Query based solution
		ll sizeofarr = (ll)(n);

		// create arr of appropriate size
		ll twopow = log2(sizeofarr);
		if(pow(2,twopow) == sizeofarr)
			sizeofarr = (2*sizeofarr) - 1;
		else
			sizeofarr = (2*pow(2,twopow+1)) - 1;

		// 0th is value, 1th is index
		ll treearr[sizeofarr][2];

		// createTree where pos indicates root
		createTree(treearr, arr, 0, (sizeof(arr)/sizeof(*arr)) - 1, 0);

		ll maxarea = 0;
		sizeofarr = (sizeof(arr)/sizeof(*arr));
		maxarea = calcMaxArea(treearr, sizeofarr, 0, (ll)(n)-1);
		printf("%lld\n", maxarea);
	}

	return 0;
}