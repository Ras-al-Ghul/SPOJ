// fricking beautiful solution
// I don't think I would've been able to come up with this O(n*k) anytime soon

// I was thinking about all kinds of states and loops and bruteforce
// For eg. 13 3 9 2 1
// 9, 9 2, 9 2 1, 9 9, 9 9 2, etc.
// 9, 9 9, exceed, 9 2, 9 2 1 etc.
// dp state always seemed to be three things - k, n, number of coins of k used
// that's frivoulous, hardly any problem will have 3D dp like that
// another thing I tried later was filling from 1 to n in ascending order
// from left to right for each coin - dp state = [n][k]
// this is again an order like 9, 9 9,.. then 9 2, 9 9 2, etc.
// this was like n*n*k
// didn't know what to store in dp too - whether it is possible to achieve this n
// or highest number of coins used to achieve this i
// other possibility was dp[n][k][num of coins] - is it possible to achieve

// but this solution idea is totally different
// we increase i from 1 to n
// for each i, we try to find if we can use coins to form that i
// so coins - only one way - use c1 or c1 c2 or c1 c2 c3,,...
// now we have to check two things - if sum[c1, .. whatever we've used] <= i
// and also dp[i - sum[..]] = true
// only then dp[i] = true
// this means we've achieved the smaller sum while satisfying the condition
// eg. i = 14, let's say we use 4 c1 and 3 c2, to get 10
// we need to check if i=10 was possible earlier - if it was,
// say 2 c1, 1 c2, then 4+2 and 3+1 still satisfies condition - that is the KEY LOGIC
// if for smaller sum condition satisfied, then for larger sum, the condition will be satisfied
// IF the condition is satisfied for the differnce
// here 10 was the difference in that example
// you only need to check O(k) for each i - cumulsum of coins

#include <iostream>

using namespace std;

int main(){
	// n is x
	int x,k;
	while(scanf("%d", &x) == 1){
		scanf("%d", &k);
		int coins[k];
		for(int i=0; i<k; ++i)
			scanf("%d", &coins[i]);
		
		// to quickly yield sum of coins that are used
		// while satisfying the property
		int cumulsum[k+1] = {};
		for(int i=1; i<=k; ++i)
			cumulsum[i] += (cumulsum[i-1]+coins[i-1]);
		
		bool dp[x+1] = {};
		// so that the i-cumulsum[j] condition holds for base case
		dp[0] = true;

		for(int i=1; i<=x; ++i){
			if(dp[i] == false){
				for(int j=1; j<=k; ++j){
					// coin sum exceeds, needn't check
					if(cumulsum[j]>i)
						break;
					// if for a smaller i, we were able to pay
					// while satisfying the conditions
					if(dp[i-cumulsum[j]] == true)
						dp[i] = true;
					// notice that we're implicitly satisfying the condition
					// for the difference i.e. for cumulsum[j] - by construction
					// if we take current coin, we take 1 of each of previous coins
				}
			}
		}
		if(dp[x] == true)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}