#include <iostream>

#define MAX 10000

using namespace std;

int main(){
	bool arr[MAX] = {};
	int n, m, id;
	scanf("%d", &n);
	int* arrofarr[n];
	for(int i=0; i<n; ++i){
		scanf("%d %d", &id, &m);
		arr[id] = 1;
		arrofarr[i] = new int[m+1];
		arrofarr[i][0] = m;
		for(int j=1; j<=m; ++j){
			scanf("%d", &arrofarr[i][j]);
		}
	}
	int count = 0;
	for(int i=0; i<n; ++i){
		for(int j=1; j<=arrofarr[i][0]; ++j){
			if(arr[arrofarr[i][j]] == 0){
				count += 1;
				arr[arrofarr[i][j]] = 1;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}