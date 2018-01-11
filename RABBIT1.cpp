// look at FIBOSUM
// sum to n terms of Fibonacci series is S(n) = F(n+2) - 1

#include <iostream>

#define ll long long

using namespace std;

ll MOD;

void fib(ll a, ll b, ll arr[2]){
	if(a == 0){
		arr[0] = 0; arr[1] = 1;
		return;
	}
	else if(a == 1){
		arr[0] = 1; arr[1] = 1;
		return;
	}

	if(a % 2 == 0){
		fib(a/2, (a/2) + 1, arr);
		// temp1 = F(n), temp2 = F(n+1)
		ll temp1 = arr[0], temp2 = arr[1];
		ll c = 2*temp2 - temp1;
		if(c<0)
			c+=MOD;
		else
			c%=MOD;
		arr[0] = (temp1 * c)%MOD;
		arr[1] = (((temp2*temp2)%MOD) + ((temp1*temp1)%MOD))%MOD;
		return;
	}
	else{
		fib((b/2)-1, b/2, arr);
		// temp1 = F(n-1), temp2 = F(n)
		ll temp1 = arr[0], temp2 = arr[1];
		ll c = (2*(temp1 + temp2)) - temp2;
		if(c<0)
			c+=MOD;
		else
			c%=MOD;
		arr[0] = (((temp2*temp2)%MOD) + ((temp1*temp1)%MOD))%MOD;
		arr[1] = (temp2 * c)%MOD;
		return;
	}
}

int main(){
	int ncases;
	scanf("%d", &ncases);
	ll n, m;
	while(ncases--){
		scanf("%lld %lld", &n, &m);
		MOD = (1<<m);
		ll arr[2] = {};
		if(n%2 == 0){
			fib(n, n+1, arr);
			printf("%lld\n", arr[1]);
		}
		else{
			fib(n+1, n+2, arr);
			printf("%lld\n", arr[0]);
		}
	}
	return 0;
}