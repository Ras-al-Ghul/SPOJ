#include <iostream>

using namespace std;

int main(){
	int n, b;
	while(scanf("%d %d", &n, &b) == 2){
		if(n==0)
			break;
		int arr[b];
		bool possible[n+1] = {};
		for(int i=0; i<b; ++i){
			scanf("%d", &arr[i]);
			for(int j=0; j<=i;  ++j){
				possible[abs(arr[i]-arr[j])] = 1;
			}
		}
		b = 0;
		for(int i=0; i<n+1; ++i)
			if(possible[i])
				++b;
		if(b==n+1)
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}