// learned iterative DFS
// learned how to handle parent flag
// while(cur != NULL)
// 	if(cur->val == parent)
// 		dfsstack.push(pair<NODE*, int>(cur, parent));
// 	else
// 		dfsstack.push(pair<NODE*, int>(cur, value));

// IMPORTANT
// note that almost any recursion can be converted to iteration
// notice that in recursion, the topmost element on the stack gets
// evaluated first. So if you're looking for an order in which to do
// iteration, go to the end of the list and come back to front.
// This problem is a perfect example. So is calculating nCr using iteration

// IMPORTANT
// BFS can also be used for this problem. For each node in the queue,
// maintain a parent, parent is the one who added into the queue.
// And DONT add current element's parent to the queue.
// For eg.
// 1 2
// 2 1
// When you get to processing 2, 2, parent is 1, so don't add 1.
// SAME THING COULD'VE been done here instead of while loop above
// If you encounted an element which is already in the VISITED list,
// it will necessarily mean that it is NOT A GRAPH.

#include <iostream>
#include <stack>

using namespace std;

typedef struct node{
	int val;
	struct node* next;
} NODE;

int main(){
	int nodes, edges, vone, vtwo;
	scanf("%d %d", &nodes, &edges);

	if(nodes==0){
		cout<<"NO"<<endl;
		return 0;
	}

	NODE* arr[nodes+1];
	int i;
	for(i=1; i<=nodes; i++){
		arr[i] = new NODE;
		arr[i]->val = -1;
		arr[i]->next = NULL;
	}

	NODE* cur;
	for(i=0; i<edges; i++){
		scanf("%d %d", &vone, &vtwo);

		cur = arr[vone];
		while(cur->next != NULL){
			cur = cur->next;
		}
		cur->next = new NODE;
		cur = cur->next;
		cur->val = vtwo; cur->next = NULL;

		cur = arr[vtwo];
		while(cur->next != NULL){
			cur = cur->next;
		}
		cur->next = new NODE;
		cur = cur->next;
		cur->val = vone; cur->next = NULL;
	}

	// for(i=1; i<=nodes; i++){
	// 	cur = arr[i];
	// 	cout<<i<<" ";
	// 	while(cur != NULL){
	// 		cout<<cur->val<<" ";
	// 		cur = cur->next;
	// 	}
	// 	cout<<endl;
	// }

	int count = 0;
	int parent = -1; bool flag = false;
	// cout<<endl;
	stack<pair<NODE*, int> > dfsstack; int value;
	cur = new NODE;
	cur->val = 1; cur->next = NULL;
	dfsstack.push(pair<NODE*, int>(cur, -1));
	while(!dfsstack.empty()){
		value = (dfsstack.top()).first->val;
		parent = (dfsstack.top()).second;
		cur = arr[value];
		dfsstack.pop();
		if(cur->val==0){
			if(value != parent){
				flag = true;
				break;
			}
			continue;
		}
		count += 1;
		cur->val = 0;
		// cout<<value<<" "<<parent<<endl;
		cur=cur->next;
		while(cur != NULL){
			if(cur->val == parent)
				dfsstack.push(pair<NODE*, int>(cur, parent));
			else
				dfsstack.push(pair<NODE*, int>(cur, value));
			cur = cur->next;
		}
	}

	if(count == nodes && !flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}