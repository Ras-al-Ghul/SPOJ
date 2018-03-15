// <https://oeis.org/search?q=9%2C82%2C756%2C7048&language=english&go=Search>

#include <iostream>
#include <cmath>

using namespace std;

const int MOD = 314159;
const int MAX = 1000000;

int cache10[MAX+2] = {};
int acache[MAX+2] = {};

// int solve(int n){
// 	int ans = 0;
// 	if(n == 1){
// 		if(not cache10[1])
// 			cache10[1] = 10;
// 		return acache[1];
// 	}
// 	if(acache[n])
// 		return acache[n];
// 	ans += solve(n-1);
// 	ans = (ans*8)%MOD;
// 	int temp = cache10[n-1];
// 	if(not cache10[n])
// 		cache10[n] = (temp*10)%MOD;
// 	return (acache[n] = (ans+temp)%MOD);
// }

int main(){
	acache[1] = 9;
	cache10[1] = 10;
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		// iteration better than recursion
		if(not acache[n]){
			for(int i=1; i<=n; ++i){
				if(not cache10[i])
					cache10[i] = (cache10[i-1]*10)%MOD;
				if(not acache[i]){
					acache[i] = (((acache[i-1]*8)%MOD)+cache10[i-1])%MOD;
				}
			}
		}
		printf("%d\n", acache[n]);
	}
	return 0;
}

// the below works for small numbers, but using OEIS is better for larger numbers
// int combi(int n,int k){
//     int ans=1;
//     k=k>n-k?n-k:k;
//     int j=1;
//     for(;j<=k;j++,n--)
//     {
//         if(n%j==0)
//         {
//             ans = (ans * n/j);
//         }else
//         if(ans%j==0)
//         {
//             ans=ans/j*n;
//         }else
//         {
//             ans=(ans*n)/j;
//         }
//     }
//     return ans;
// }

// int main(){
// 	int t; scanf("%d", &t);
// 	while(t--){
// 		int n; scanf("%d", &n);
// 		int ans = pow(10,n);
// 		for(int i=1; i<=n; ++i){
// 			if(i%2 != 0){
// 				ans -= (combi(n,i)*(pow(9,(n-i))));
// 			}
// 		}
// 		printf("%d\n", ans);
// 	}
// 	return 0;
// }