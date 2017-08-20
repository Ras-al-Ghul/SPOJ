// if approach is not sure, do not start, it is a waste of time and doesn't help

// taught me that there can be so many edge cases that you haven't thought about

// two times dfs
// second time with the deepest node
// second time max depth is the longest path

// using parent in dfs seems to be usual
// increment using depth of parent to find depth of current node

#include <iostream>
#include <stack>

using namespace std;

typedef struct node{
	int val;
	int parent;
	struct node *next;
}NODE;

void dfs(int root, NODE* arr[], int lenarr[]){
	NODE *cur; int val, parent;
	stack<NODE *> dfsstack;
	cur = new NODE; cur->val = root; cur->parent = 0; cur->next = NULL;
	dfsstack.push(cur);
	while(!dfsstack.empty()){
		val = (dfsstack.top())->val;
		cur = arr[val];
		parent = (dfsstack.top())->parent;
		dfsstack.pop();
		if(cur->val == 0){
			continue;
		}
		lenarr[val] = lenarr[parent] + 1;
		cur->val = 0;
		cur->parent = parent;
		cur = cur->next;
		while(cur != NULL){
			if(!(parent==cur->val)){
				cur->parent = val;
				dfsstack.push(cur);
			}
			cur = cur->next;
		}
	}
}

int main(){
	int numnodes, i, v1, v2, val, parent;
	scanf("%d", &numnodes);
	if(numnodes==0){
		cout<<0<<endl;
		return 0;
	}

	NODE* arr[numnodes];
	NODE* cur;
	for(i=0; i<=numnodes; i++){
		arr[i] = new NODE;
		arr[i]->val = -1;
		arr[i]->next = NULL;
	}
	for(i=0; i<numnodes-1; i++){
		scanf("%d %d", &v1, &v2);
		cur = arr[v1];
		while(cur->next != NULL){
			cur=cur->next;
		}
		cur->next = new NODE; cur=cur->next;
		cur->val = v2; cur->next = NULL;
		cur = arr[v2];
		while(cur->next != NULL){
			cur=cur->next;
		}
		cur->next = new NODE; cur=cur->next;
		cur->val = v1; cur->next = NULL;
	}

	// distance from root
	int lenarr[numnodes+1] = {0};
	// so that distance from root to root becomes 0
	lenarr[0] = -1;

	// root is 1
	dfs(1, arr, lenarr);

	arr[0]->val = 0;

	cur = arr[1]->next; val = 0;
	while(cur != NULL){
		val += 1;
		cur = cur->next;
	}

	int max = 0;
	int maxindex = 0;
	for(i=1; i<numnodes+1; i++){
		if(lenarr[i] > max){
			max = lenarr[i];
			maxindex = i;
		}
	}
	if(val==1){
		cout<<max<<endl;
		return 0;
	}
	else if(numnodes==1){
		cout<<1<<endl;
		return 0;
	}
	else{
		// reinitialize
		for(i=0; i<=numnodes; i++){
			arr[i]->val = -1;
		}
		arr[0]->val = 0;
		int lenarr1[numnodes+1] = {0};
		lenarr1[0] = -1;

		// the new root is max1index
		dfs(maxindex, arr, lenarr1);

		max = 0;
		maxindex = 0;
		for(i=1; i<numnodes+1; i++){
			if(lenarr1[i] > max){
				max = lenarr1[i];
				maxindex = i;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}