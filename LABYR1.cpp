// one more double dfs
// implementation was challenging

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <stack>

#define pb push_back

using namespace std;

typedef struct node{
	int val;
	int parent;
	struct node *next;
}NODE;

void addConn(vector<NODE*> &adjlist, int i, int j){
	NODE* cur = adjlist[i];
	while(cur->next!=NULL){
		cur=cur->next;
	}
	cur->next = new NODE[1];
	cur = cur->next;
	cur->val = j; cur->parent = -1; cur->next = NULL;
	
	cur = adjlist[j];
	while(cur->next!=NULL){
		cur=cur->next;
	}
	cur->next = new NODE[1];
	cur = cur->next;
	cur->val = i; cur->parent = -1; cur->next = NULL;
}

int addRow(vector<NODE*> &adjlist, set<int> cur, set<int> prev, int returnval){
	int curval = returnval;
	if(returnval==-1){
		for(auto it=cur.begin(); it!=cur.end(); ++it){
			NODE* temp = new NODE[1];
			++curval;
			temp->val = curval; temp->parent = -1; temp->next = NULL;
			adjlist.pb(temp);
		}
		return curval;
	}
	// key is index, value is nodelabel
	map<int, int> newmap;
	returnval -= prev.size();
	for(auto it=prev.begin(); it!=prev.end(); ++it){
		++returnval;
		newmap.insert(pair<int,int>((*it),returnval));
	}
	for(auto it=cur.begin(); it!=cur.end(); ++it){
		NODE* temp = new NODE[1];
		++curval;
		temp->val = curval; temp->parent = -1; temp->next = NULL;
		adjlist.pb(temp);
		auto iter = newmap.find((*it));
		if(iter!=newmap.end()){
			addConn(adjlist, iter->second, curval);
		}
		if(it!=cur.begin()){
			if((*it)-(*std::prev(it)) == 1){
				addConn(adjlist, curval-1, curval);
			}
		}
	}
	// last allocated value
	return curval;
}

void dfs(int root, vector<NODE*> &adjlist, int lenarr[]){
	NODE *cur; int val, parent;
	stack<NODE *> dfsstack;
	cur = new NODE; cur->val = root; cur->parent = 0; cur->next = NULL;
	dfsstack.push(cur);
	while(!dfsstack.empty()){
		val = (dfsstack.top())->val;
		cur = adjlist[val];
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
	return;
}

void doubleDFS(vector<NODE*> &adjlist, int numnodes){
	int lenarr[numnodes+1] = {0};
	lenarr[0] = -1;

	dfs(1, adjlist, lenarr);
	// for(int i=0;i<numnodes+1;i++){
	// 	cout<<lenarr[i]<<endl;
	// }
	// cout<<endl;
	int i;
	int max = 0;
	int maxindex = 0;
	for(i=1; i<numnodes+1; i++){
		if(lenarr[i] > max){
			max = lenarr[i];
			maxindex = i;
		}
	}

	for(i=1; i<=numnodes; i++){
		adjlist[i]->val = i;
	}
	adjlist[0]->val = -1;
	int lenarr1[numnodes+1] = {0};
	lenarr1[0] = -1;

	// // the new root is max1index
	dfs(maxindex, adjlist, lenarr1);

	max = 0;
	maxindex = 0;
	for(i=1; i<numnodes+1; i++){
		if(lenarr1[i] > max){
			max = lenarr1[i];
			maxindex = i;
		}
	}
	printf("Maximum rope length is %d.\n", max);
	return;
}

int main(){
	int ncases;
	int rows, cols, i, j, k;
	string line, temp;
	getline(cin, line); ncases = stoi(line);

	while(ncases--){
		scanf("%d %d", &cols, &rows);
		getline(cin, line);
		int rowarr[cols] = {0};

		vector<NODE*> adjlist;
		NODE* tempcur = new NODE[1]; tempcur->val=-1;tempcur->next=NULL; adjlist.pb(tempcur);
		set<int> prev, cur;
		int returnval = 0;

		bool atleastflag = false;

		for(i=0;i<rows;++i){
			getline(cin, line);
			for(j=0;j<cols;++j){
				if(line[j] == '.'){
					cur.insert(j);
					atleastflag = true;
				}
			}
			if(!cur.empty()){
				returnval = addRow(adjlist, cur, prev, returnval);
			}
			prev.clear();
			prev = cur;
			cur.clear();
		}

		if(!atleastflag){
			// if there is no free blocks at all
			printf("Maximum rope length is 0.\n");
			continue;
		}
		
		// for(i=0;i<adjlist.size();i++){
		// 	NODE* cur = adjlist[i];
		// 	cout<<i<<" "<<cur->val<<" ";
		// 	cur=cur->next;
		// 	while(cur!=NULL){
		// 		cout<<cur->val<<" ";
		// 		cur=cur->next;
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;
		doubleDFS(adjlist, adjlist.size()-1);
	}
	return 0;
}