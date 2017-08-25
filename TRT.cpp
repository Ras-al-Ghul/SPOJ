// map lookup is not O(1), but array lookup is O(1)
// so if memo table fits in memory, go for array - 1D or 2D
// https://www.quora.com/Are-there-any-good-resources-or-tutorials-for-dynamic-programming-DP-besides-the-TopCoder-tutorial
// Mimino's answer
// identify that the level is not required as part of the key
// this is great as well - another one from Mimino
// https://www.quora.com/How-do-I-figure-out-how-to-iterate-over-the-parameters-and-write-bottom-up-solutions-to-dynamic-programming-related-problems

#include <iostream>

#define ll long long
#define MAX 2000

using namespace std;

ll n = 0;
ll memo[MAX][MAX] = {0};

ll recurse(ll up, ll down, ll arr[]){
	ll level = n - (down-up);
	if(memo[up][down] != 0)
		return memo[up][down];
	if(up == down){
		memo[up][down] = (level*arr[up]);
		return (level*arr[up]);
	}
	ll val1 = (arr[up]*level) + recurse(up+1,down,arr);
	ll val2 = (arr[down]*level) + recurse(up,down-1,arr);
	ll val = max(val1, val2);
	memo[up][down] = val;
	return val;
}

int main(){
	ll ncases, i;
	scanf("%lld", &ncases);
	n = ncases;
	ll arr[ncases];
	for(i=0; i<ncases; i++)
		scanf("%lld", &arr[i]);

	ll tempval = recurse(0,ncases-1,arr);
	cout<<tempval<<endl;
	return 0;
}