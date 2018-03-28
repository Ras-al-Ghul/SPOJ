// standard dp on a tree
#include <iostream>
#include <cstring>

#define mp make_pair

using namespace std;

char input[10000+2];
int len = 0;

typedef struct node{
	struct node *left = nullptr;
	struct node *right = nullptr;
}NODE;

pair<NODE*,int> constructTree(int ind){
	if(ind == len)
		return mp(nullptr,-1);

	NODE *cur = new NODE;

	if(input[ind] == '0'){
		return mp(cur,ind+1);
	}
	pair<NODE*,int> next;
	if(input[ind] == '1'){
		next = constructTree(ind+1);
		cur->left = next.first;
		return mp(cur,next.second);
	}
	if(input[ind] == '2'){
		next = constructTree(ind+1);
		cur->left = next.first;
		next = constructTree(next.second);
		cur->right = next.first;
		return mp(cur,next.second);
	}
}

// to see if the tree construction function is working correctly
// void traverse(NODE * root){
// 	if(root->left and root->right){
// 		cout<<2;
// 		traverse(root->left);
// 		traverse(root->right);
// 	}
// 	else if(root->left and (not root->right)){
// 		cout<<1;
// 		traverse(root->left);
// 	}
// 	else{
// 		cout<<0;
// 		return;
// 	}
// }

typedef struct no{
	// pair first is coloring green, pair second is not coloring green
	// maxi is maximal
	pair<int,int> maxi;
	// mini is minimal
	pair<int,int> mini;
}NO;

NO traverse(NODE *root){
	if(root->left and root->right){
		NO left = traverse(root->left);
		NO right = traverse(root->right);
		NO temp;
		temp.maxi.first = left.maxi.second + right.maxi.second + 1;
		temp.maxi.second = max(left.maxi.first+right.maxi.second, left.maxi.second+right.maxi.first);
		temp.mini.first = left.mini.second + right.mini.second + 1;
		temp.mini.second = min(left.mini.first+right.mini.second, left.mini.second+right.mini.first);
		return temp;
	}
	else if(root->left){
		NO left = traverse(root->left);
		NO temp;
		temp.maxi.first = left.maxi.second+1; temp.maxi.second = max(left.maxi.first,left.maxi.second);
		temp.mini.first = left.mini.second+1; temp.mini.second = min(left.mini.first,left.mini.second);
		return temp;
	}
	else{
		NO temp;
		temp.maxi.first = 1; temp.maxi.second = 0;
		temp.mini.first = 1; temp.mini.second = 0;
		return temp;
	}
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		scanf("%s", input);
		len = strlen(input);
		// printf("%s\n", input);
		auto root = constructTree(0);
		NO ans = traverse(root.first);
		printf("%d %d\n",max(ans.maxi.first, ans.maxi.second), min(ans.mini.first, ans.mini.second));
	}
	return 0;
}