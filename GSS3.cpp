// GSS1 + update
// for update, just set the leaf node appropriately and update upper nodes, lazy propagation is harder to implement

#include <iostream>
#include <cmath>

using namespace std;

typedef struct node{
	long maxnonemptyprefix;
	long maxnonemptysuffix;
	long maxnonemptysum;
	long totalsum;
}NODE;

void createTree(NODE * arr[], long inputarr[], int low, int high, int pos, int location, int val){
	if(low == high){
		// set it for leaf nodes, it is trivial
		int temp = val;
		if(location == -1){
			arr[pos] = new NODE; temp = inputarr[low];
		}
		arr[pos]->totalsum = temp;
		arr[pos]->maxnonemptyprefix = temp;
		arr[pos]->maxnonemptysuffix = temp;
		arr[pos]->maxnonemptysum = temp;
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

	arr[pos]->totalsum = arr[leftchild]->totalsum + arr[rightchild]->totalsum;
	
	arr[pos]->maxnonemptyprefix = arr[leftchild]->totalsum + arr[rightchild]->maxnonemptyprefix;
	arr[pos]->maxnonemptyprefix = max(arr[pos]->maxnonemptyprefix, arr[leftchild]->maxnonemptyprefix);

	arr[pos]->maxnonemptysuffix = arr[leftchild]->maxnonemptysuffix + arr[rightchild]->totalsum;
	arr[pos]->maxnonemptysuffix = max(arr[pos]->maxnonemptysuffix, arr[rightchild]->maxnonemptysuffix);

	arr[pos]->maxnonemptysum = arr[leftchild]->maxnonemptysum;
	arr[pos]->maxnonemptysum = max(arr[pos]->maxnonemptysum, arr[rightchild]->maxnonemptysum);
	arr[pos]->maxnonemptysum = max(arr[pos]->maxnonemptysum, arr[leftchild]->maxnonemptysuffix + arr[rightchild]->maxnonemptyprefix);

	return;
}

NODE * rangeMinQuery(NODE * arr[], int qlow, int qhigh, int low, int high, int pos){
	// total overlap
	if(qlow <= low and qhigh >= high){
		return arr[pos];
	}
	// no overlap
	if(qlow > high or qhigh < low){
		return nullptr;
	}

	// partial overlap
	int mid = low + ((high-low)/2);

	int leftchild = (2*pos) + 1;
	int rightchild = (2*pos) + 2;

	NODE * temp1 = rangeMinQuery(arr, qlow, qhigh, low, mid, leftchild);
	NODE * temp2 = rangeMinQuery(arr, qlow, qhigh, mid+1, high, rightchild);

	NODE * temp = new NODE;

	if(temp1 != nullptr and temp2 != nullptr){
		temp->totalsum = temp1->totalsum + temp2->totalsum;

		temp->maxnonemptyprefix = temp1->totalsum + temp2->maxnonemptyprefix;
		temp->maxnonemptyprefix = max(temp->maxnonemptyprefix, temp1->maxnonemptyprefix);

		temp->maxnonemptysuffix = temp1->maxnonemptysuffix + temp2->totalsum;
		temp->maxnonemptysuffix = max(temp->maxnonemptysuffix, temp2->maxnonemptysuffix);

		temp->maxnonemptysum = temp1->maxnonemptysum;
		temp->maxnonemptysum = max(temp->maxnonemptysum, temp2->maxnonemptysum);
		temp->maxnonemptysum = max(temp->maxnonemptysum, temp1->maxnonemptysuffix + temp2->maxnonemptyprefix);
	}
	else{
		NODE * tempdup = temp1 == nullptr? temp2 : temp1;

		temp->totalsum = tempdup->totalsum;
		temp->maxnonemptyprefix = tempdup->maxnonemptyprefix;
		temp->maxnonemptysuffix = tempdup->maxnonemptysuffix;
		temp->maxnonemptysum = tempdup->maxnonemptysum;
	}

	return temp;
}

int main(){
	int sizeofarr;
	scanf("%d", &sizeofarr);

	// read input
	long inputarr[sizeofarr];
	for(int i=0;i<sizeofarr;++i)
		scanf("%ld", &inputarr[i]);

	// create arr of appropriate size
	int twopow = log2(sizeofarr);
	if(pow(2,twopow) == sizeofarr)
		sizeofarr = (2*sizeofarr) - 1;
	else
		sizeofarr = (2*pow(2,twopow+1)) - 1;

	NODE * arr[sizeofarr];
	
	// createTree where pos indicates root
	createTree(arr, inputarr, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0, -1, -1);

	int queries, begin, end, type;
	scanf("%d", &queries);
	while(queries--){
		scanf("%d %d %d", &type, &begin, &end);
		if(type == 1){
			NODE * temp = rangeMinQuery(arr, begin-1, end-1, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0);
			printf("%ld\n", temp->maxnonemptysum);
		}
		else{
			int location = begin, val = end;
			createTree(arr, inputarr, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0, location-1, val);
		}
	}

	return 0;
}