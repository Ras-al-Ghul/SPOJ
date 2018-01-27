#include <iostream>
#include <stack>

#define pii pair<int,int>
#define mp make_pair

using namespace std;

int rect_size(int arr[], int len){
	stack<pii > width;
	int maxarea = 0;
	for(int i=0; i<len; ++i){
		if((not width.empty()) and width.top().first <= arr[i]){
			width.push(mp(arr[i],1));
		}
		else if(width.empty()){
			width.push(mp(arr[i],1));
		}
		else{
			int temp = 0;
			while((not width.empty()) and width.top().first > arr[i]){
				temp += width.top().second;
				maxarea = max(maxarea, temp*width.top().first);
				width.pop();
			}
			width.push(mp(arr[i],temp+1));
		}
	}
	if(not width.empty()){
		int temp = 0;
		while((not width.empty())){
			temp += width.top().second;
			maxarea = max(maxarea, temp*width.top().first);
			width.pop();
		}
	}
	return maxarea;
}

int main(){
	int k; scanf("%d", &k);
	while(k--){
		int m, n; scanf("%d %d ", &m, &n);
		char arr[m][n];
		for(int i=0; i<m; ++i){
			for(int j=0; j<n; ++j){
				scanf("%c ", &arr[i][j]);
			}
		}
		int span[m] = {}, ans = 0;
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				if(span[j] == 0){
					if(arr[j][i] == 'F'){
						int k = 0;
						while(arr[j][k+i] == 'F' and (k+i)<n){
							++k;
						}
						span[j] = k;
					}
				}
				else{
					span[j]--;
				}
			}
			ans = max(ans, rect_size(span, m));
		}
		printf("%d\n", ans*3);
	}
	return 0;
}