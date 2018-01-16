#include <cstdio>

int main(){
	int n, temp;
	while(1){
		scanf("%d", &n);
		if(n==0)
			break;

		int arr[n+1][2];
		for(int i=1; i<=n; ++i){
			scanf("%d %d", &arr[i][0], &arr[i][1]);
		}

		int final[n+1];
		for(int i=1; i<=n; ++i)
			final[i] = 0;
		int flag = 1;
		for(int i=1; i<=n; ++i){
			temp = i + arr[i][1];
			if(temp >= 1 && temp <= n && final[temp] == 0){
				final[temp] = arr[i][0];
			}
			else{
				flag = 0; break;
			}
		}
		if(flag){
			for(int i=1; i<=n; ++i){
				printf("%d ", final[i]);
			}
			printf("\n");
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}