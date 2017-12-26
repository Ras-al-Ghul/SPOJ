// think segment trees automatically, if update and query - many of them
// like always, what are the fields of segement tree node required is important to figure out
// here leftunbalanced and right unbalanced was enough

#include <iostream>
#include <cmath>

using namespace std;

typedef struct node{
	int leftunbalanced;
	int rightunbalanced;
}NODE;

void createTree(NODE * arr[], char inputarr[], int low, int high, int pos){
	if(low == high){
		// set it for leaf nodes, it is trivial
		arr[pos] = new NODE;
		arr[pos]->leftunbalanced = inputarr[low] == '('?1:0;
		arr[pos]->rightunbalanced = inputarr[high] == ')'?1:0;
		return;
	}

	int mid = low + ((high-low)/2);

	int leftchild = (2*pos) + 1;
	int rightchild = (2*pos) + 2;

	createTree(arr, inputarr, low, mid, leftchild);
	createTree(arr, inputarr, mid+1, high, rightchild);

	arr[pos] = new NODE;

	// oc open count, cc closed count, l left, r right
	int loc = arr[leftchild]->leftunbalanced;
	int lcc = arr[leftchild]->rightunbalanced;
	int roc = arr[rightchild]->leftunbalanced;
	int rcc = arr[rightchild]->rightunbalanced;

	arr[pos]->leftunbalanced = 0;arr[pos]->rightunbalanced = 0;
	if(loc>=rcc)
		arr[pos]->leftunbalanced += (loc-rcc);
	else
		arr[pos]->rightunbalanced += (rcc-loc);
	arr[pos]->leftunbalanced += roc;
	arr[pos]->rightunbalanced += lcc;

	return;
}

bool rangeMinQuery(NODE * arr[], int qlow, int qhigh, int low, int high, int pos){
	// total overlap
	if(arr[pos]->leftunbalanced == 0 and arr[pos]->rightunbalanced == 0)
		return true;
	else 
		return false;
}

void update(NODE * arr[], int low, int high, int pos, int change){
	if(low == high){
		// set it for leaf nodes, it is trivial
		arr[pos]->leftunbalanced = arr[pos]->leftunbalanced == 1?0:1;
		arr[pos]->rightunbalanced = arr[pos]->rightunbalanced == 1?0:1;
		// cout<<pos<<" "<<arr[pos]->leftunbalanced<<" "<<arr[pos]->rightunbalanced<<endl;
		return;
	}

	int mid = low + ((high-low)/2);

	int leftchild = (2*pos) + 1;
	int rightchild = (2*pos) + 2;

	if(change<=mid)
		update(arr, low, mid, leftchild, change);
	else
		update(arr, mid+1, high, rightchild, change);

	// oc open count, cc closed count, l left, r right
	int loc = arr[leftchild]->leftunbalanced;
	int lcc = arr[leftchild]->rightunbalanced;
	int roc = arr[rightchild]->leftunbalanced;
	int rcc = arr[rightchild]->rightunbalanced;

	// cout<<loc<<" "<<lcc<<" "<<roc<<" "<<rcc<<endl;

	arr[pos]->leftunbalanced = 0;arr[pos]->rightunbalanced = 0;
	if(loc>=rcc)
		arr[pos]->leftunbalanced += (loc-rcc);
	else
		arr[pos]->rightunbalanced += (rcc-loc);
	arr[pos]->leftunbalanced += roc;
	arr[pos]->rightunbalanced += lcc;

	// cout<<pos<<" "<<arr[pos]->leftunbalanced<<" "<<arr[pos]->rightunbalanced<<endl;
	return;
}

int main(){
	int ncases = 10;
	for(int i=1; i<=ncases; ++i){
		printf("Test %d:\n", i);
		int sizeofarr;
		scanf("%d", &sizeofarr);
		// read input
		char inputarr[sizeofarr];
		char dupiparr[sizeofarr+1];
		scanf("%s", dupiparr);
		for(int i=0;i<sizeofarr;++i)
			inputarr[i] = dupiparr[i];

		// create arr of appropriate size
		int twopow = log2(sizeofarr);
		if(pow(2,twopow) == sizeofarr)
			sizeofarr = (2*sizeofarr) - 1;
		else
			sizeofarr = (2*pow(2,twopow+1)) - 1;

		NODE * arr[sizeofarr];
		
		// createTree where pos indicates root
		createTree(arr, inputarr, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0);

		int nqueries, queries;
		scanf("%d", &nqueries);
		while(nqueries--){
			scanf("%d", &queries);
			if(queries == 0){
				bool temp = rangeMinQuery(arr, 0, sizeofarr-1, 0, (sizeof(inputarr)/sizeof(*inputarr)) - 1, 0);
				if(temp)
					printf("YES\n");
				else
					printf("NO\n");
			}
			else{
				update(arr, 0, (sizeof(inputarr)/sizeof(*inputarr))-1, 0, queries-1);
			}
		}
	}
	return 0;
}