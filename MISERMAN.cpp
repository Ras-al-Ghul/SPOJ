#include <iostream>
#include <climits>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	int curarr[m] = {};
	int prevarr[m];
	for(int i=0; i<m; ++i){
		scanf("%d", &prevarr[i]);
	}

	for(int i=1; i<n; ++i){
		for(int j=0; j<m; ++j){
			scanf("%d", &curarr[j]);
		}
		for(int j=0; j<m; ++j){
			if(j-1>=0 and j+1<m){
				curarr[j] += min(prevarr[j-1], min(prevarr[j], prevarr[j+1]));
			}
			else if(j-1>=0){
				curarr[j] += min(prevarr[j-1], prevarr[j]);
			}
			else if(j+1<m){
				curarr[j] += min(prevarr[j], prevarr[j+1]);
			}
		}
		for(int j=0; j<m; ++j)
			prevarr[j] = curarr[j];
	}
	int mini = INT_MAX;
	for(int i=0; i<m; ++i)
		mini = min(mini, prevarr[i]);
	printf("%d\n", mini);
	return 0;
}