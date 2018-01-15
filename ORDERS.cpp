// my initial technique was the following:
// given 0 1 2 0 1
// find rightmost smallest number - 0 at posn. 4
// make it INT_MAX and decrement count of everything to its right
// so 0 1 2 M 0 - M will be 5 in final answer,
// next 0 1 2 M M - second M will be 4
// next M 0 1 M M - first M will be 3
// so on - we can use rangeMinQuery/heaps for this, but still worst case O(n^2)

// better is: have a segment tree array with all 0's initially - it should support two ops:
// - find ith cell from left which contains a zero
// - update the value of the ith cell from 0 to 1
// so take input array 0 1 2 0 1 and traverse from right to left
// find 5-1 = 4th 0 in segment tree array
// essentially, we assume that everything to left is sorted, only then we act - because of question
// so if number in 5th position does 1 shift to the left, it means, it ends up in 4th position in final answer
// so it means initially, 4 was in 5th position
// so index of 5-1th zero is newarr[i]
// update segment tree - make that index 1
// next find 4-0 = 4th 0 in updated segment tree - this essentially means, leave out the 4,
// in the remaining indices, find where this element will go if left shifted given number of times
// this has log(n) ops to find ith zero and log(n) ops to update given index to 1

// to find ith zero is one more tricky thing - look at rangeMinQuery below, basically divide and conquer
// can use Fenwick Tree also
// <https://www.quora.com/What-are-the-ways-to-solve-this-spoj-problem-SPOJ-com-Problem-ORDERS>
// <https://stackoverflow.com/questions/17466218/what-are-the-differences-between-segment-trees-interval-trees-binary-indexed-t/17504505>

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

typedef struct node{
	int numofzeros; int index;
}NODE;

void createTree(NODE * arr[], int inputarr[], int low, int high, int pos, int location, int val){
	if(low == high){
		// set it for leaf nodes, it is trivial
		int temp = val;
		if(location == -1){
			arr[pos] = new NODE; temp = 0;
		}
		if(val == -2){
			temp = 1;
		}
		arr[pos]->numofzeros = temp==0?1:0;
		if(temp != 1)
			arr[pos]->index = low;
		else
			arr[pos]->index = -1;
		return;
	}

	int mid = low + ((high-low)/2);

	int leftchild = (2*pos) + 1;
	int rightchild = (2*pos) + 2;

	if(location != -1 and location<=mid){
		createTree(arr, inputarr, low, mid, leftchild, location, val);
	}
	else if(location != -1){
		createTree(arr, inputarr, mid+1, high, rightchild, location, val);
	}
	else{
		createTree(arr, inputarr, low, mid, leftchild, location, val);
		createTree(arr, inputarr, mid+1, high, rightchild, location, val);
	}

	if(location == -1)
		arr[pos] = new NODE;

	int temp1 = arr[leftchild]->numofzeros, temp2 = arr[rightchild]->numofzeros;
	arr[pos]->numofzeros = temp1 + temp2;
	arr[pos]->index = arr[rightchild]->index;
	if(arr[pos]->index == -1)
		arr[pos]->index = arr[leftchild]->index;
	return;
}

NODE * rangeMinQuery(NODE * arr[], int num, int low, int high, int pos){
	if(arr[pos]->numofzeros <= num){
		return arr[pos];
	}

	int mid = low + ((high-low)/2);

	int leftchild = (2*pos) + 1;
	int rightchild = (2*pos) + 2;

	NODE * temp = new NODE;

	NODE * temp1 = rangeMinQuery(arr, num, low, mid, leftchild);

	if(temp1->numofzeros == num){
		return temp1;
	}

	NODE * temp2 = rangeMinQuery(arr, num-temp1->numofzeros, mid+1, high, rightchild);
	temp->numofzeros = num;
	temp->index = temp2->index;
	return temp;
}

int main(){
	int t, oldsizeofarr, sizeofarr;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &oldsizeofarr);

		int inputarr[oldsizeofarr];
		for(int i=0; i<oldsizeofarr; ++i)
			scanf("%d", &inputarr[i]);

		int newarr[oldsizeofarr] = {};
		
		sizeofarr = oldsizeofarr;
		// create arr of appropriate size
		int twopow = log2(sizeofarr);
		if(pow(2,twopow) == sizeofarr)
			sizeofarr = (2*sizeofarr) - 1;
		else
			sizeofarr = (2*pow(2,twopow+1)) - 1;

		NODE * arr[sizeofarr];

		// createTree where pos indicates root
		createTree(arr, inputarr, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0, -1, -1);

		for(int i=oldsizeofarr-1; i>=0; --i){
			int minindex = inputarr[i];

			NODE * temp = rangeMinQuery(arr, i+1-minindex, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0);
				
			newarr[i] = temp->index;
			int location = temp->index+1, val = -2;
			createTree(arr, inputarr, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0, location-1, val);
		}
		for(int i=0; i<oldsizeofarr; ++i){
			printf("%d ", newarr[i] + 1);
		}
		printf("\n");
	}

	return 0;
}