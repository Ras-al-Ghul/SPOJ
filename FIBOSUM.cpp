// in modular ops, be careful when negative numbers arise
// have to do a '+ MOD' when such a case arises
// fastfib <https://www.nayuki.io/page/fast-fibonacci-algorithms>

#include <iostream>

#define ll long long

using namespace std;

const long long MOD = 1000000007;

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
	ll ncases;
	scanf("%lld", &ncases);
	ll a, b;
	while(ncases--){
		scanf("%lld %lld", &a, &b);
		ll arr1[2] = {};
		// first number should be even number for the above fib function

		// what we need is:
		// sum = (f(b)+f(b+1)) - (f(a-1) + f(a))
		if(b%2 == 0){
			fib(b, b+1, arr1);
		}
		else{
			fib(b-1, b, arr1);
			ll temp = arr1[0];
			arr1[0] = arr1[1];
			arr1[1] = (temp + arr1[1])%MOD;
		}
		ll arr2[2] = {};
		if(a%2 == 0){
			if(a>0){
				fib(a-2, a-1, arr2);
				ll temp = arr2[0];
				arr2[0] = arr2[1];
				arr2[1] = (temp + arr2[1])%MOD;
			}
			else{
				arr2[0] = 0, arr2[1] = 1;
			}
		}
		else{
			fib(a-1, a, arr2);
		}
		ll temp = ((arr1[0]+arr1[1])%MOD) - ((arr2[0]+arr2[1])%MOD);
		temp = temp<0? temp+MOD:temp;
		printf("%lld\n", temp);
	}
	return 0;
}