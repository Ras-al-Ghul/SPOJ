// logic very similar to GSS1

#include <iostream>
#include <cmath>

using namespace std;

// 0 is value 1 is frequency
typedef struct node{
	int prefix[2];
	int suffix[2];
	int best[2];
}NODE;

void createTree(NODE * arr[], int inputarr[], int low, int high, int pos){
	if(low == high){
		// set it for leaf nodes, it is trivial
		arr[pos] = new NODE;
		arr[pos]->best[0] = inputarr[low]; arr[pos]->best[1] = 1;
		arr[pos]->prefix[0] = inputarr[low]; arr[pos]->prefix[1] = 1;
		arr[pos]->suffix[0] = inputarr[low]; arr[pos]->suffix[1] = 1;
		return;
	}

	int mid = low + ((high-low)/2);

	int leftchild = (2*pos) + 1;
	int rightchild = (2*pos) + 2;

	createTree(arr, inputarr, low, mid, leftchild);
	createTree(arr, inputarr, mid+1, high, rightchild);

	arr[pos] = new NODE;

	arr[pos]->prefix[0] = arr[leftchild]->prefix[0]; arr[pos]->prefix[1] = arr[leftchild]->prefix[1];
	if(arr[pos]->prefix[0] == arr[leftchild]->suffix[0]){
		arr[pos]->prefix[1] = arr[leftchild]->best[1];
		if(arr[pos]->prefix[0] == arr[rightchild]->prefix[0]){
			arr[pos]->prefix[1] += arr[rightchild]->prefix[1];
			if(arr[pos]->prefix[0] == arr[rightchild]->suffix[0]){
				arr[pos]->prefix[1] -= arr[rightchild]->prefix[1];
				arr[pos]->prefix[1] += arr[rightchild]->best[1];
			}
		}
	}

	arr[pos]->suffix[0] = arr[rightchild]->suffix[0]; arr[pos]->suffix[1] = arr[rightchild]->suffix[1];
	if(arr[pos]->suffix[0] == arr[rightchild]->prefix[0]){
		arr[pos]->suffix[1] = arr[rightchild]->best[1];
		if(arr[pos]->suffix[0] == arr[leftchild]->suffix[0]){
			arr[pos]->suffix[1] += arr[leftchild]->suffix[1];
			if(arr[pos]->suffix[0] == arr[leftchild]->prefix[0]){
				arr[pos]->suffix[1] -= arr[leftchild]->suffix[1];
				arr[pos]->suffix[1] += arr[leftchild]->best[1];
			}
		}
	}

	arr[pos]->best[0] = arr[leftchild]->best[0]; arr[pos]->best[1] = arr[leftchild]->best[1];
	if(arr[pos]->best[1] < arr[rightchild]->best[1]){
		arr[pos]->best[0] = arr[rightchild]->best[0];
		arr[pos]->best[1] = arr[rightchild]->best[1];
	}
	
	if(arr[leftchild]->suffix[0] == arr[rightchild]->prefix[0] and arr[pos]->best[1] < (arr[leftchild]->suffix[1] + arr[rightchild]->prefix[1])){
		arr[pos]->best[0] = arr[leftchild]->suffix[0];
		arr[pos]->best[1] = arr[leftchild]->suffix[1] + arr[rightchild]->prefix[1];
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
		temp->prefix[0] = temp1->prefix[0]; temp->prefix[1] = temp1->prefix[1];
		if(temp->prefix[0] == temp1->suffix[0]){
			temp->prefix[1] = temp1->best[1];
			if(temp->prefix[0] == temp2->prefix[0]){
				temp->prefix[1] += temp2->prefix[1];
				if(temp->prefix[0] == temp2->suffix[0]){
					temp->prefix[1] -= temp2->prefix[1];
					temp->prefix[1] += temp2->best[1];
				}
			}
		}

		temp->suffix[0] = temp2->suffix[0]; temp->suffix[1] = temp2->suffix[1];
		if(temp->suffix[0] == temp2->prefix[0]){
			temp->suffix[1] = temp2->best[1];
			if(temp->suffix[0] == temp1->suffix[0]){
				temp->suffix[1] += temp1->suffix[1];
				if(temp->suffix[0] == temp1->prefix[0]){
					temp->suffix[1] -= temp1->suffix[1];
					temp->suffix[1] += temp1->best[1];
				}
			}
		}

		temp->best[0] = temp1->best[0]; temp->best[1] = temp1->best[1];
		if(temp->best[1] < temp2->best[1]){
			temp->best[0] = temp2->best[0];
			temp->best[1] = temp2->best[1];
		}
		
		if(temp1->suffix[0] == temp2->prefix[0] and (temp->best[1] < (temp1->suffix[1] + temp2->prefix[1]))){
			temp->best[0] = temp1->suffix[0];
			temp->best[1] = temp1->suffix[1] + temp2->prefix[1];
		}
	}
	else{
		NODE * tempdup = temp1 == nullptr? temp2 : temp1;

		temp->prefix[0] = tempdup->prefix[0];
		temp->prefix[1] = tempdup->prefix[1];
		temp->suffix[0] = tempdup->suffix[0];
		temp->suffix[1] = tempdup->suffix[1];
		temp->best[0] = tempdup->best[0];
		temp->best[1] = tempdup->best[1];
	}

	return temp;
}

int main(){

	while(true){
		int sizeofarr, queries;
		scanf("%d", &sizeofarr);
		if(sizeofarr == 0)
			break;

		scanf("%d", &queries);

		// read input
		int inputarr[sizeofarr];
		for(int i=0;i<sizeofarr;++i)
			scanf("%d", &inputarr[i]);

		// create arr of appropriate size
		int twopow = log2(sizeofarr);
		if(pow(2,twopow) == sizeofarr)
			sizeofarr = (2*sizeofarr) - 1;
		else
			sizeofarr = (2*pow(2,twopow+1)) - 1;

		NODE * arr[sizeofarr];
		
		// createTree where pos indicates root
		createTree(arr, inputarr, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0);

		int begin, end;
		while(queries--){
			scanf("%d %d", &begin, &end);
			NODE * temp = rangeMaxQuery(arr, begin-1, end-1, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0);
			printf("%d\n", temp->best[1]);
		}
	}

	return 0;
}