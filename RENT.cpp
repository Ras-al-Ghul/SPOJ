// initial thought was it is like knapsack problem
// standard job scheduling problem
// sort jobs according to increasing order of finish times
// now standard dp way of thinking is: two cases for each job - either include or don't
// that can be made faster here - if we include certain jobs, certain others can't be included
// those certain others are the ones whose times intersect with current job
// that is where sorting helps - O(n^2)
// for each job - newarr[i] will store the best profit obtained 'including' that job and
// considering all preceding jobs - hence initialize it to profit(i) for all i
// starting from left, for each job i, consider 0 to last non intersecting job - j's
// for each j, and this current i, do newarr[i] = max(newarr[i], newarr[j]+profit[i])
// finally do a linear sweep of newarr to get max possible profit

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct node{
	long long arr[3];
}NODE;

long long compares(const NODE a, const NODE b){
	return (a.arr[0]+a.arr[1]) < (b.arr[0]+b.arr[1]);
}

int main(){
	long long t; scanf("%lld", &t);
	while(t--){
		long long n; scanf("%lld", &n);
		NODE jobs[n];
		long long newarr[n];
		for(long long i=0; i<n; ++i){
			scanf("%lld %lld %lld", &jobs[i].arr[0], &jobs[i].arr[1], &jobs[i].arr[2]);
		}

		sort(jobs, jobs+n, compares);
		for(long long i=0; i<n; ++i)
			newarr[i] = jobs[i].arr[2];

		long long maxele = 0;
		for(long long i=1; i<n; ++i){
			long long low=0, high=i-1, mid;
			while(low < high){
				mid = low + (high-low)/2;
				if(mid == low)
					mid++;
				if(jobs[mid].arr[0] + jobs[mid].arr[1] <= jobs[i].arr[0]){
					low = mid;
				}
				else{
					high = mid-1;
				}
			}
	
			if(jobs[low].arr[0] + jobs[low].arr[1] > jobs[i].arr[0])
				low--;

			for(long long j=0; j<=low; ++j){
				newarr[i] = max(newarr[i], jobs[i].arr[2]+newarr[j]);
			}
			maxele = max(maxele, newarr[i]);
		}

		// for(long long i=1; i<n; ++i){
		// 	for(long long j=0; j<i; ++j){
		// 		if((jobs[j].arr[0] + jobs[j].arr[1]) <= jobs[i].arr[0])
		// 			newarr[i] = max(newarr[i], jobs[i].arr[2]+newarr[j]);
		// 		else
		// 			break;
		// 	}
		// 	maxele = max(maxele, newarr[i]);
		// }
		printf("%lld\n", maxele);
	}

	return 0;
}