#include <iostream>

using namespace std;

int main(){
	int n; scanf("%d", &n);
	int arr[n][2];
	for(int i=0; i<n; ++i)
		scanf("%d %d", &arr[i][0], &arr[i][1]);

	int a = max(arr[0][0], arr[0][1]);
	int b = min(arr[0][0], arr[0][1]);
	// 0 th is best you get if you place horizontally
	// 1 th is best you get if you place vertically
	int cur[2];
	cur[0] = a; cur[1] = b;
	int nexth = b, nextv = a;
	int temp1, temp2;
	for(int i=1; i<n; ++i){
		a = max(arr[i][0], arr[i][1]);
		b = min(arr[i][0], arr[i][1]);

		if(max(nexth,b)-min(nexth,b)+cur[0]>max(nextv,b)-min(nextv,b)+cur[1])
			temp1 = max(nexth,b)-min(nexth,b)+cur[0]+a;
		else
			temp1 = max(nextv,b)-min(nextv,b)+cur[1]+a;

		if(max(nexth,a)-min(nexth,a)+cur[0]>max(nextv,a)-min(nextv,a)+cur[1])
			temp2 = max(nexth,a)-min(nexth,a)+cur[0]+b;
		else
			temp2 = max(nextv,a)-min(nextv,a)+cur[1]+b;
		cur[0] = temp1, cur[1] = temp2;
		nexth = b, nextv = a;
	}
	printf("%d\n", max(cur[0], cur[1]));
	return 0;
}