#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

int main(){
	ll t, n, p; scanf("%lld", &t);
	string ip;
	while(t--){
		scanf("%lld", &n);
		int arr[n];
		for(ll i=0; i<n; ++i)
			cin>>ip>>arr[i];
		sort(arr, arr+n);
		ll ans = 0;
		for(ll i=1; i<=n; ++i)
			ans += abs(arr[i-1]-i);
		printf("%lld\n", ans);
	}
	return 0;
}