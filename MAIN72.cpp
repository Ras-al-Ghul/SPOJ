// brilliant, but you have to sort and elements have to be unique
// <https://stackoverflow.com/questions/18305843/find-all-subsets-that-sum-to-a-particular-value>
// more general
// <https://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/>

#include <iostream>

using namespace std;

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int N; scanf("%d", &N);
		int arr[N];
		int maxi = 0;
		for(int i=0; i<N; ++i){
			scanf("%d", &arr[i]);
			maxi = max(maxi, arr[i]);
		}

		int up = N*maxi;
		bool sumarr[N+1][up+1] = {};
		sumarr[0][0] = 1;

		int oldnum=0, num=0, i, j;
		for(i=1; i<=N; ++i){
			oldnum = num;
			for(j=0; j<=oldnum; ++j){
				if(sumarr[i-1][j] == 1){
					sumarr[i][j] = 1;
					sumarr[i][arr[i-1]+j] = 1;
					num = max(num, arr[i-1]+j);
				}
			}
		}
		long sums = 0;
		for(i=0; i<=up; ++i){
			sums += long(sumarr[N][i] * i);
		}
		printf("%ld\n", sums);
	}

	return 0;
}