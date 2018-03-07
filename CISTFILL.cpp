// similar to PIE except that there we did binary search for 43 iterations
// here it is while(high-low > 0.000001)

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

typedef struct node{
	int b, h, w, d, v;
}NODE;

bool comp(const NODE first, const NODE second){
	return first.b < second.b;
}

int main(){
	int k; scanf("%d", &k);
	while(k--){
		int n; scanf("%d", &n);
		double V;
		vector<NODE> arr(n);
		double maxV = 0;
		for(int i=0; i<n; ++i){
			scanf("%d %d %d %d", &arr[i].b, &arr[i].h, &arr[i].w, &arr[i].d);
			arr[i].v = arr[i].h * arr[i].w * arr[i].d;
			maxV += arr[i].v;
		}
		sort(arr.begin(), arr.end(), comp);
		scanf("%lf", &V);

		if(maxV < V){
			printf("OVERFLOW\n"); continue;
		}

		double low = 0.0, high = 1E7, mid;
	
		while(high-low> 0.000001){
			mid = low + (high-low)/2;
			double vol = 0.0;
			for(auto it = arr.begin(); it != arr.end(); ++it){
				if((*it).b >= mid){
					continue;
				}
				else if(((*it).b < mid) && (((*it).b + (*it).h) >= mid)) {
					vol += ((mid - (*it).b) * ((*it).w) * ((*it).d));
				}
				else if(((*it).b + (*it).h) < mid) {
					vol += ((*it).v);
				}
			}
			if(vol >= V)
				high = mid;
			else
				low = mid;
		}
		printf("%.2lf\n", mid);
	}

	return 0;
}