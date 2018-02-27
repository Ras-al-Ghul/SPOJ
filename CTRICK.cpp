#include <iostream>
#include <cmath>

using namespace std;

// Doubly Linked List based solution - bottom up - start from last
// say 5 - 5
// then 4 5 - add 4 to left of cur, rotate 4 times to find new cur
// then 3 4 5 - add 3 to left of cur, rotate 3 times to find new cur
// then 2 3 4 5 - add 2 to left of cur, rotate 2 times to find new cur
// it becomes 4 5 2 3 now
// then 1 4 5 2 3 - add 1 to left of cur, rotate 1 time to find new cur
// it becomes 3 1 4 5 2

// typedef struct node{
// 	struct node * back = nullptr;
// 	struct node * front = nullptr;
// 	int val;
// 	node(int v):val(v){};
// }NODE;

// int main(){
// 	int n; scanf("%d", &n);
// 	int ip, tempn;
// 	while(n--){
// 		scanf("%d", &ip);
// 		NODE * cur = new NODE(ip);
// 		cur->front = cur; cur->back = cur;
// 		for(int i=ip-1; i>0; --i){
// 			NODE * temp = new NODE(i);
// 			tempn = i%(ip-i+1);
// 			temp->front = cur;
// 			temp->back = cur->back;
// 			cur->back->front = temp;
// 			cur->back = temp;
// 			cur = temp;
// 			for(int j=0; j<tempn; ++j){
// 				cur = cur->front;
// 			}
// 			cur = cur->front;
// 		}
// 		cur = cur->back;
// 		for(int i=0; i<ip; ++i){
// 			printf("%d ", cur->val);
// 			cur = cur->back;
// 		}
// 		printf("\n");
// 	}
// 	return 0;
// }

// segment tree - rangeMinQuery etc. - find ith zero technique
// top down - start from 1, go to n
// for 1 --> 2, 2 --> 3, 3 --> 4 rotates
// find 2nd zero - (1 rotate + next) is for 1
// make that 1
// find 3rd zero starting from cur of above - 2 rotate + next is for 2
// make that 2
// wrap around if array index exceeds - do %numofzeroesleft ops

typedef struct node{
	int numofzeros; int index;
}NODE;

void createTree(NODE * arr[], int low, int high, int pos, int location, int val){
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
		createTree(arr, low, mid, leftchild, location, val);
	}
	else if(location != -1){
		createTree(arr, mid+1, high, rightchild, location, val);
	}
	else{
		createTree(arr, low, mid, leftchild, location, val);
		createTree(arr, mid+1, high, rightchild, location, val);
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
		createTree(arr, 0, oldsizeofarr-1, 0, -1, -1);

		int zeroind = 2; int queryind = zeroind;
		int nzeros = oldsizeofarr;
		int zerostoright, tempo;
		int newzeroind;
		for(int i=1; i<=oldsizeofarr; ++i){

			NODE * temp = rangeMinQuery(arr, queryind, 0, oldsizeofarr-1, 0);
			
			newarr[temp->index] = i;
			// have to store it as it gets modified in next createTree part
			tempo = temp->numofzeros;

			int location = temp->index+1, val = -2;
			createTree(arr, 0, oldsizeofarr-1, 0, location-1, val);
			
			// zeroind is independent, increment independently
			++zeroind;
			// keep track of zeroes to the right
			zerostoright = nzeros - tempo;
			--nzeros;
			
			// else will get divide by zero error
			if(nzeros == 0)
				break;

			// this part took a long time to figure out
			// basically have to maintain cyclic property with right indices
			if(zeroind>nzeros)
				newzeroind = ((zeroind-1)%(nzeros))+1;
			else
				newzeroind = zeroind;
			
			if(newzeroind<=zerostoright){
				// add the zeroes in the left part (tempo-1) + whatever is needed (newzeroind)
				// that will give queryindex
				queryind = (tempo-1)+newzeroind;
			}
			else{
				// you will need zerostoright more zeros from beginning after this step
				// the rest of the zeros are covered by the zeros to the right
				zerostoright = newzeroind - zerostoright;
				queryind = zerostoright;
			}
		}
		for(int i=0; i<oldsizeofarr; ++i){
			printf("%d ", newarr[i]);
		}
		printf("\n");
	}

	return 0;
}