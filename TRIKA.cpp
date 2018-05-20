#include <iostream>

using namespace std;

int main(){
	int n, m, x, y, i, j; scanf("%d %d %d %d", &n, &m, &x, &y);
	int arr[n][m];
	for(i=0; i<n; ++i)
		for(j=0; j<m; ++j)
			scanf("%d", &arr[i][j]);
	
	// base cases, cols and rows
	// x,y given in one based indexing
	for(j=y; j<m; ++j)
		arr[x-1][j] = arr[x-1][j-1] - arr[x-1][j];
	for(i=x; i<n; ++i)
		arr[i][y-1] = arr[i-1][y-1] - arr[i][y-1];

	for(i=x; i<n; ++i)
		for(j=y; j<m; ++j)
			arr[i][j] = max(arr[i-1][j]-arr[i][j],arr[i][j-1]-arr[i][j]);
		
	if(arr[n-1][m-1] < 0)
		printf("N\n");
	else
		printf("Y %d\n", arr[n-1][m-1]);

	return 0;
}