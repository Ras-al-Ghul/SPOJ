// <https://github.com/stranger9811/spoj/blob/master/MATSUM.cpp>
// <https://www.geeksforgeeks.org/two-dimensional-binary-indexed-tree-or-fenwick-tree/>
// <https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/>
// <https://www.quora.com/How-do-I-implement-a-2D-binary-indexed-tree-for-range-update-and-range-query-operations>
// <https://www.quora.com/How-does-a-2D-segment-tree-work>
// <https://stackoverflow.com/questions/25121878/2d-segment-quad-tree-explanation-with-c>

// segment tree can also be made 2D - called quad tree
// 2D Fenwick tree is straightforward extension to grid
// each index of 1D Fenwick tree is now another Fenwick tree

// indices can get pretty confusing, when to use >0, <n, <=n, etc.
// also to update (x,y) to val, you have to find actual existing value at (x,y) first
// this is done by using (x+1,y+1), (x+1,y), (x,y+1), (x,y)
// then update with relevant value i.e. (val - (above sum))

// adding elements to tree is simply update

// sum uses similar concepts - (x1, y1), (x2, y2) - but remember to take (x2+1,y2+1)

#include <iostream>
#include <cstring>

#define MAX 1024

using namespace std;

long long arr[MAX+1][MAX+1];

// from (0,0) to (x,y)
long long getSum(long long x, long long y){
	long long sum = 0, y1;
	for(; x>0; x -= (x&-x)){
		for(y1 = y; y1>0; y1 -= (y1&-y1)){
			sum += arr[x][y1];
		}
	}
	return sum;
}

void update(long long n, long long x, long long y, long long val){
	long long y1;
	for(; x<=n; x += (x&-x)){
		for(y1 = y; y1<=n; y1 += (y1&-y1)){
			arr[x][y1] += val;
		}
	}
}

int main(){
	long long n, ncases;
	char command[4];
	scanf("%lld", &ncases);

	long long x1, x2, y1, y2;
	long long v1, v2, v3, v4, val;

	while(ncases--){
		scanf("%lld", &n);

		memset(arr,0,sizeof(arr));

		while(scanf("%s",command) == 1){
			if(!strcmp(command,"END"))
				break;

			if(!strcmp(command,"SUM")){
				scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
				v1 = getSum(x2+1,y2+1);
				v2 = getSum(x2+1,y1);
				v3 = getSum(x1,y1);
				v4 = getSum(x1,y2+1);
				printf("%lld\n", v1-v2-v4+v3);
			}

			if(!strcmp(command,"SET")){
				scanf("%lld %lld %lld", &x1, &y1, &val);
				v1 = getSum(x1+1,y1+1);
				v2 = getSum(x1+1,y1);
				v3 = getSum(x1,y1);
				v4 = getSum(x1,y1+1);
				update(n,x1+1,y1+1,val-(v1-v2-v4+v3));
			}
		}

		printf("\n");
	}
	return 0;
}