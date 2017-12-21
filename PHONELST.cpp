#include <iostream>
#include <string>

using namespace std;

typedef struct Node{
	struct Node * arr[10];
}NODE;

NODE * END;

bool traverseAdd(NODE * root, string num){
	int len = num.length();
	NODE *temp = root;
	for(int i=0; i<len; ++i){
		int cur = num[i]-48;
		if(temp->arr[cur]){
			if(i != len-1){
				temp = temp->arr[cur];
				if(temp->arr[cur] == END)
					return true;
			}
			else
				return true;
		}
		else{
			temp->arr[cur] = new NODE;
			temp = temp->arr[cur];
		}
	}
	temp->arr[num[len-1] - 48] = END;
	return false;
}

int main(){
	int ncases;
	scanf("%d", &ncases);
	END = new NODE;
	while(ncases--){
		int n;
		scanf("%d", &n);
		string num;

		NODE * root = new NODE;

		bool flag = false;
		for(int i=0; i<n; ++i){
			cin>>num;
			if(flag == false){
				flag = traverseAdd(root, num);
			}
		}
		if(not flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}