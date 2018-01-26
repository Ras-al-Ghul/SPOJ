#include <iostream>

#define ull unsigned long long

using namespace std;

const int MOD = 1000007;

int main(){
	int t, n; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ull a = ((ull)(n)*((ull)(2*2)+((ull)(n-1)*(ull)(2))))/(ull)(2);
		ull b = (ull)(n)*(ull)(n-1)/(ull)(2);
		a = a % MOD; b = b % MOD;
		printf("%llu\n", (a+b)%MOD);
	}
	return 0;
}