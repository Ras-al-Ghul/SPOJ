// can use BIT/Fenwick Tree with lazy propagation too
// <http://codeforces.com/blog/entry/10306>
#include <iostream>

// RELATED TO PROB
// 2^18 = 262144 which is next highest 2^power
// 2^17 = 131072, but we need space for 100000 atleast, so 2*100000 atleast
#define MAX_NODES 262144

using namespace std;

int N, M, a, b, c;

int NODES[MAX_NODES] = {};
bool LAZY[MAX_NODES] = {};

inline void propagate(int index)
{
	// toggling LAZY of children nodes
	LAZY[2*index+1] = !LAZY[2*index+1];
	LAZY[2*index+2] = !LAZY[2*index+2];
}


inline void handle_lazy(int index, int low, int high)
{
	// check if current index lazy is true
	if(LAZY[index]){
		// if children exist, make them lazy i.e. set their lazy
		if(low != high){
			// update NODE index
			NODES[index] = ((high-low+1)-NODES[index]);
			propagate(index);
		}
		// if leaf node, update
		else
			NODES[index] = !NODES[index];
			
		// now this is not lazy anymore
		LAZY[index] = 0;
	}
	return;
}

void update(int index, int low, int high, int range1, int range2){
	// cout<<"u "<<index<<"   "<<low<<" "<<high<<"   "<<range1<<" "<<range2<<endl;

	// checking full overlap first because if lazy, then just toggle lazy - faster
	// full overlap
	if(low>=range1 and high<=range2 and (not LAZY[index])){
		if(low == high)
			NODES[index] = !NODES[index];
		else{
			// if full overlap, make update here and make children LAZY
			// if addition, store value to be added in LAZY array
			propagate(index);
			NODES[index] = ((high-low+1)-NODES[index]);
		}
		return;
	}
	else if(low>=range1 and high<=range2 and LAZY[index]){
		LAZY[index] = !LAZY[index];
		return;
	}

	// this has to come before you even check for no overlap
	// else will lead to errors
	// because if you have parent node with no lazy and two children with lazy
	// if you take value of one of the children and update parent's value, it will be wrong
	// hence you have to update other out of range child first also, if it is lazy
	handle_lazy(index, low, high);

	// no overlap
	if(low>range2 or high<range1)
		return;

	int mid = low + ((high-low)/2);

	int leftchild = (2*index) + 1;
	int rightchild = (2*index) + 2;

	// partial overlap
	update(leftchild, low, mid, range1, range2);
	update(rightchild, mid+1, high, range1, range2);

	NODES[index] = NODES[leftchild] + NODES[rightchild];
	return;
}

int query(int index, int low, int high, int qlow, int qhigh){
	// cout<<"p "<<index<<"   "<<low<<" "<<high<<"   "<<qlow<<" "<<qhigh<<endl;

	// total overlap
	if((not LAZY[index]) and qlow <= low and qhigh >= high){
		return NODES[index];
	}
	else if(LAZY[index] and qlow <= low and qhigh >= high){
		if(low == high)
			NODES[index] = !NODES[index];
		else{
			propagate(index);
			NODES[index] = ((high-low+1)-NODES[index]);
		}
		LAZY[index] = false;
		return NODES[index];
	}

	handle_lazy(index, low, high);

	// no overlap
	if(qlow > high or qhigh < low){
		return 0;
	}
	
	// partial overlap
	int mid = low + ((high-low)/2);

	int leftchild = (2*index) + 1;
	int rightchild = (2*index) + 2;
	// no idea why this seems to be making a huge difference
	return (/*NODES[index] = */query(leftchild, low, mid, qlow, qhigh) + query(rightchild, mid+1, high, qlow, qhigh));
	// okay, got it simple. When out of bounds, you return 0, irrespective of how many ones that child actually has
	// so basically, you're ignoring the values of that child which is wrong - hence don't overwrite
	// NODES[index] here because it is already taken care of in the handle_lazy() part
}	

int main()
{
	scanf("%d %d", &N, &M);
	while(M--){
		scanf("%d %d %d", &a, &b, &c);

		if(a == 0){
			update(0, 0, N-1, b-1, c-1);
		}
		else{
			printf("%d\n", query(0, 0, N-1, b-1, c-1));
		}
		// cout<<endl;
		// for(int i=0; i<15; ++i)
		// 	printf("%d. %d  ", i, NODES[i]);
		// printf("\n");
		// for(int i=0; i<15; ++i)
		// 	printf("%d. %d  ", i, LAZY[i]);
		// cout<<endl<<endl;
	}
	return 0;
}