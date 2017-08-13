// http://www.mathsisfun.com/combinatorics/combinations-permutations.html
// https://en.wikipedia.org/wiki/Stars_and_bars_%28combinatorics%29
// https://www.statlect.com/mathematical-tools/combinations
// https://stackoverflow.com/questions/15301885/calculate-value-of-n-choose-k    --- look up Pascal triangle
// https://en.wikipedia.org/wiki/Multiset
// https://www.quora.com/How-do-I-divide-a-given-number-into-a-given-number-of-parts-randomly-and-uniformly

#include <iostream>

#define ull unsigned long long
#define ll long long

using namespace std;

int main(){
	ull numoftestcases;
	scanf("%llu", &numoftestcases);
	ull n, k;
	ull basen, basek, i, ans;
	while(numoftestcases--){
		scanf("%llu %llu", &n, &k);
		n--; k--;
		if((n-k)<k)
			k = n-k;
		ans = 1;
		basen = n - k + 1; basek = 1;
		while(basen <= n){
			ans = ((ans * basen)/basek);
			basek++; basen++;
		}
		cout<<ans<<endl;
	}
	return 0;
}