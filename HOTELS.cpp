// sliding window, two pointer + prefix sum

#include <iostream>

#define ull unsigned long long

using namespace std;

int main(){
	ull  n, m; scanf("%llu %llu", &n, &m);
	ull sumarr[n+1] = {};
	ull ans = 0, left = 0, right = 1;
	for(int i=1; i<=n; ++i){
		scanf("%llu", &sumarr[i]);
		sumarr[i] += sumarr[i-1];
		while(sumarr[right]-sumarr[left] > m){
			left++;
		}
		ans = max(ans, sumarr[right]-sumarr[left]);
		right++;
	}
	printf("%llu\n", ans);
	return 0;
}