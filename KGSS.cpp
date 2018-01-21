// range max query - segment tree with update

#include <iostream>
#include <cmath>

using namespace std;

typedef struct node{
	int maxvalue, maxindex;
}NODE;

void createTree(NODE * arr[], int inputarr[], int low, int high, int pos, int location, int val){
	if(low == high){
		// set it for leaf nodes, it is trivial
		int temp = val;
		if(location == -1){
			arr[pos] = new NODE; temp = inputarr[low];
		}
		arr[pos]->maxvalue = temp;
		arr[pos]->maxindex = low;
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

	if(arr[leftchild]->maxvalue >= arr[rightchild]->maxvalue){
		arr[pos]->maxvalue = arr[leftchild]->maxvalue;
		arr[pos]->maxindex = arr[leftchild]->maxindex;
	}
	else{
		arr[pos]->maxvalue = arr[rightchild]->maxvalue;
		arr[pos]->maxindex = arr[rightchild]->maxindex;	
	}
	
	return;
}

NODE * rangeMaxQuery(NODE * arr[], int qlow, int qhigh, int low, int high, int pos){
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

	NODE * temp1 = rangeMaxQuery(arr, qlow, qhigh, low, mid, leftchild);
	NODE * temp2 = rangeMaxQuery(arr, qlow, qhigh, mid+1, high, rightchild);

	NODE * temp = new NODE;

	if(temp1 != nullptr and temp2 != nullptr){
		if(temp1->maxvalue >= temp2->maxvalue){
			temp->maxvalue = temp1->maxvalue;
			temp->maxindex = temp1->maxindex;
		}
		else{
			temp->maxvalue = temp2->maxvalue;
			temp->maxindex = temp2->maxindex;	
		}
	}
	else{
		NODE * tempdup = temp1 == nullptr? temp2 : temp1;

		temp->maxvalue = tempdup->maxvalue;
		temp->maxindex = tempdup->maxindex;
	}

	return temp;
}

int main(){
	int n; scanf("%d", &n);
	int inputarr[n];
	for(int i=0; i<n; ++i)
		scanf("%d", &inputarr[i]);

	int sizeofarr = n;

	// create arr of appropriate size
	int twopow = log2(sizeofarr);
	if(pow(2,twopow) == sizeofarr)
		sizeofarr = (2*sizeofarr) - 1;
	else
		sizeofarr = (2*pow(2,twopow+1)) - 1;

	NODE * arr[sizeofarr];

	// createTree where pos indicates root
	createTree(arr, inputarr, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0, -1, -1);
	int queries, begin, end; char type;
	scanf("%d ", &queries);
	while(queries--){
		scanf("%c %d %d ", &type, &begin, &end);
		if(type == 'Q'){
			NODE * temp = rangeMaxQuery(arr, begin-1, end-1, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0);
			NODE * left = nullptr, * right = nullptr;
			if(temp->maxindex+1>begin){
				left = rangeMaxQuery(arr, begin-1, temp->maxindex-1, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0);
			}
			if(temp->maxindex+1<end){
				right = rangeMaxQuery(arr, temp->maxindex+1, end-1, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0);
			}
			if(left != nullptr and right != nullptr)
				printf("%d\n", temp->maxvalue+max(left->maxvalue, right->maxvalue));
			else{
				NODE * tempnew = left==nullptr?right:left;
				printf("%d\n", temp->maxvalue+tempnew->maxvalue);
			}
		}
		else{
			int location = begin, val = end;
			createTree(arr, inputarr, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0, location-1, val);
		}
	}

	return 0;
}