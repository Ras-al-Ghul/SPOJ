#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long g,t,a,d;
	while(scanf("%lld %lld %lld %lld", &g, &t, &a, &d) == 4){
		if(g == -1)
			break;
		long long ngames = g * (t*(t-1)/2);
		long long adv = (g * a) + d;
		double temp = log2(adv);
		temp = ceil(temp);
		long long pow2 = (long long)(1)<<(long long)(temp);
		ngames += (pow2-1);
		printf("%lld*%lld/%lld+%lld=%lld+%lld\n", g, a, t, d, ngames, pow2-adv);
	}
	return 0;
}