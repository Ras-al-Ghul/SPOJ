// create equation and solve

#include <iostream>

#define ll long long

using namespace std;

int main(){
	ll ncases;
	scanf("%ld", &ncases);
	while(ncases--){
		ll n, k, t, f;
		scanf("%ld %ld %ld %ld", &n, &k, &t, &f);
		printf("%ld\n", (n + (t*k*(f-n))/(t*(k-1))));
	}

	return 0;
}