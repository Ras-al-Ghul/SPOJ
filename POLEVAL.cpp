// look up <https://en.wikipedia.org/wiki/Horner's_method>
// look up <https://en.wikipedia.org/wiki/Polynomial_remainder_theorem>
// one can also solve in naive method - multiply x progressively
// like to calculate x^5, do x^4 * x, instead of math.pow(x,5)

#include <iostream>

#define ll long long

using namespace std;

int main(){
	ll degree, k, ans, i, temp;
	ll count = 1;
	while(true){
		scanf("%lld", &degree);
		if(degree == -1)
			break;
		ll arr[degree+1];
		for(i=0;i<degree+1;++i){
			scanf("%lld", &arr[i]);
		}
		printf("Case %lld:\n", count);
		scanf("%lld", &k);
		while(k--){
			scanf("%lld", &temp);
			ans = arr[0];
			for(i=1;i<degree+1;++i){
				ans = arr[i] + (ans*temp);
			}
			printf("%lld\n", ans);
		}
		++count;
	}
	return 0;
}