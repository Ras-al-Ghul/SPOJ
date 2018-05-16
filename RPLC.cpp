#include <iostream>

using namespace std;

int main(){
	long long t, n, ip; scanf("%lld", &t);
	for(long long j=1; j<=t; ++j){
		scanf("%lld", &n);
		long long sum = 0, mins = 0;
		for(long long i=0; i<n; ++i){
			scanf("%lld", &ip);
			sum += ip; mins = min(mins, sum);
		}
		if(mins < 0)
			mins = -mins;
		printf("Scenario #%lld: %lld\n", j, mins+1);
	}
	return 0;
}