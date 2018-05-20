// obv1: within a row, say if we have 5 columns, can pick 1,3,5 or 2,4
// kinda method, hence dp technique - use i = max(i-1,i+(i-2))
// obv2: now you know how much max you can get from each row -
// if you pick a candy on a row, upper row and bottom row vanish
// - so you have to select certain set of rows to maximize candies
// - use i = max(i-1,i+(i-2)) dp technique to find which rows to select

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int m, n, i, j, ip;
	while(scanf("%d %d", &m, &n)==2){
		if(m==0)
			break;
		int rowarr[3];
		memset(rowarr, 0, sizeof(rowarr));

		for(i=0; i<m; ++i){
			int colarr[3];
			memset(colarr, 0, sizeof(colarr));
			for(j=0; j<n; ++j){
				scanf("%d", &colarr[2]);
				colarr[2] = max(colarr[2]+colarr[0], colarr[1]);
				colarr[0] = colarr[1];
				colarr[1] = colarr[2];
			}
			rowarr[2] = colarr[2];
			rowarr[2] = max(rowarr[2]+rowarr[0], rowarr[1]);
			rowarr[0] = rowarr[1];
			rowarr[1] = rowarr[2];
		}
		printf("%d\n", rowarr[2]);
	}
	return 0;
}