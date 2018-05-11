#include <iostream>

#define ull unsigned long long

using namespace std;

const ull MOD = 10000007;

ull modexp(ull a, ull b){
	ull x=1, y=a;
	while(b>0){
		if(b%2==1)
			x=(x*y)%MOD;
		y=(y*y)%MOD;
		b/=2;
	}
	return x%MOD;
}

int main(){
	ull n,k;
	while(true){
		scanf("%llu %llu", &n,  &k);
		if(n == 0)
			break;
		ull ans = 0;
		ans += modexp(n,k);
		ans += ((2*modexp(n-1,k))%MOD);
		ans = ans%MOD;
		ans += modexp(n,n);
		ans += ((2*modexp(n-1,n-1))%MOD);
		ans = ans%MOD;
		printf("%llu\n", ans);
	}
	return 0;
}