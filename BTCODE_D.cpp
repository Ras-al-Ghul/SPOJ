#include <iostream>

#define ll long long

using namespace std;

int main(){
	ll t, m, n, i, j, temp; scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld", &m, &n);
		ll arr[m][n];
		for(i=0; i<m; ++i)
			for(j=0; j<n; ++j)
				scanf("%lld", &arr[i][j]);
		for(i=0; i<m; ++i)
			for(j=0; j<n; ++j){
				scanf("%lld", &temp);
				arr[i][j] = min(arr[i][j],temp);
			}
		for(i=0; i<m; ++i)
			for(j=0; j<n; ++j){
				scanf("%lld", &temp);
				arr[i][j] *= temp;
			}
		ll ans = 0;
		for(i=0; i<m; ++i){
			ll maxs = 0;
			for(j=0; j<n; ++j)
				maxs = max(maxs,arr[i][j]);
			ans += maxs;
		}
		printf("%lld\n", ans);
	}
	return 0;
}