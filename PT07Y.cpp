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
// it will necessarily mean that it IS A GRAPH.

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
	// start from node with label 1
	cur->val = 1; cur->next = NULL;
	// first is value, second is parent
	// push first node on to stack
	dfsstack.push(pair<NODE*, int>(cur, -1));
	while(!dfsstack.empty()){
		// get value from stack top element
		value = (dfsstack.top()).first->val;
		// get parent value from stack top element
		parent = (dfsstack.top()).second;
		// point cur to relevant pointer - starts with 1
		cur = arr[value];
		// pop element from stack top
		dfsstack.pop();
		// if visited
		if(cur->val==0){
			// if it's parent doesn't equal itself, then it means that it is a cycle
			// means that you're visiting the parent from a node other than the child
			if(value != parent){
				// it is a graph
				flag = true;
				break;
			}
			continue;
		}
		// to say that all nodes have been visited
		count += 1;
		// mark as visited
		cur->val = 0;
		// cout<<value<<" "<<parent<<endl;
		cur=cur->next;
		// traverse to the depth of the tree all the while adding to stack
		while(cur != NULL){
			// if 'cur' is parent of 'value - from above'
			if(cur->val == parent)
				// mark that parent's parent as itself
				dfsstack.push(pair<NODE*, int>(cur, parent));
			else
				// this means that 'value' node is parent of cur
				// i.e. 'value' node has added it to the stack
				dfsstack.push(pair<NODE*, int>(cur, value));
			cur = cur->next;
		}
	}
	// standard edge case check - 'if connected' and 'no cycles'
	if(count == nodes && !flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}