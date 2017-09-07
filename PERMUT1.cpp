// look at constraint that n (1<=n<=12) and k (0<=k<=98)
// hence 2D array dp
// construct manually for n = 1, 2, 3 and 4 to see how to come up with solution
// add existing inversions to previous inversions
// for each inversion column in previous row, consider it as a family, hence you've to add properly
// look at lines 27 - 30 - printing table may help understand what is going on

#include <iostream>

#define MAX 98

using namespace std;

int main(){
	int ncases;
	scanf("%d", &ncases);
	while(ncases--){
		int n,k;
		scanf("%d %d", &n, &k);
		int arr[n+1][MAX+1] = {};
		arr[1][0] = 1;
		int i, j, c, temp;
		for(i=2;i<=n;i++){
			j = 0;
			while(arr[i-1][j] != 0){
				c = 0;
				while(c<i){
					temp = (i-1) - c;
					arr[i][temp + j] += arr[i-1][j];
					++c;
				}
				++j;
			}
		}
		printf("%d\n", arr[n][k]);
	}
	return 0;
}