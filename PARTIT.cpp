// I figured out 3 state dp and reconstruction was involved
// but I couldn't figure out how to reconstruct solution using my dp state
// had to change dp state to on suggested here to get the answer to suit the question
// <https://apps.topcoder.com/forums/;jsessionid=C7F81460994E1AF7784F3119761204F7?module=Thread&threadID=621940&start=0&mc=8#1014801>
// so if you cannot reconstruct, try modifying state
// here it was [lensofar][last number][sumsofar]
// instead change to [lenleft][last number][sum left]
// this enabled reconstruction

// also precompute DP table wherever possible

#include <iostream>
#include <vector>

#define LL long long
#define pb push_back

using namespace std;

// the table filling is correct here
// but reconstruction for lexicographic order is not possible with this method (dp state)
// because consider how you would reconstruct below, you check for all possible last
// digits, starting from the smallest (for(i=1; i<=m; ++i)) 
// consider last digit 222, then 1 1 1 3 222 will be there
// so will 1 1 2 2 222, but later we do 223, 1 1 1 2 223
// as you see 1 1 1 2 223 is lexicographically smaller than 1 1 1 3 222
// but we count it later which is incorrect
// suppose we to largest to smallest (for(i=m; i>=1; --i)), then
// say we query 223, then it contains say 1 1 1 3 223 and 1 1 2 2 223
// later we query 222, it contains 1 1 1 4 222 - we end up counting
// 1 1 2 2 223 earlier than counting 1 1 1 4 222 which is wrong

// to use this method we may need vector<vector<int> > in each dp[][][] location
// which is tedious and slow, instead change dp state to something else as down below
// int main(){
// 	LL t, m, n, k; scanf("%lld", &t);
// 	while(t--){
// 		scanf("%lld %lld %lld", &m, &n, &k);
// 		// first index is length
// 		// second index is last number
// 		// third index is sum
// 		LL dp[n+1][m+1][m+1] = {};
// 		for(int i=1; i<=m; ++i)
// 			dp[1][i][i] = 1;
// 		// for each length
// 		for(int i=2; i<=n; ++i){
// 			// for each possible last number
// 			for(int j=1; j<=m; ++j){
// 				// for each possible sum
// 				for(int k=i; k<=m; ++k){ // k starts with i because sum can't be less than length
// 					// for each possible len-1 AND
// 					// last number less than current last number
// 					for(int l=1; l<=j; ++l){
// 						dp[i][j][k] += dp[i-1][l][k-j];
// 					}
// 				}
// 			}
// 		}
// 		cout<<dp[8][204][210]<<endl;
// 		// Reconstruction
// 		vector<LL> ans;
// 		LL count = 0;
// 		LL i, j, sum = m;
// 		for(j=n; j>=1; --j){
// 			for(i=1; i<=m; ++i){
// 				count += dp[j][i][sum];
// 				if(count >= k)
// 					break;
// 			}
// 			ans.pb(i);
// 			sum -= i; k = count-k+1; count = 0;
// 		}
// 		// for(int i=1; i<=n; ++i){
// 		// 	for(int j=1; j<=m; ++j){
// 		// 		cout<<i<<" "<<j<<endl;
// 		// 		for(int k=i; k<=m; ++k){
// 		// 			cout<<dp[i][j][k]<<" ";
// 		// 		}
// 		// 		cout<<endl;
// 		// 	}
// 		// }
// 		for(i=ans.size()-1; i>=0; --i)
// 			printf("%lld ", ans[i]);
// 		printf("\n");
// 	}
// 	return 0;
// }

const LL maxN = 11;
const LL maxM = 221;

// new dp state is as shown below
int main(){
	// first index is length left
	// second index is last number
	// third index is sum left
	LL dp[maxN][maxM][maxM] = {};
	// pre construct table
	for(int i=1; i<maxM; ++i)
		dp[1][i][i] = 1;
	// for each length left
	for(int i=2; i<maxN; ++i){
		// for each possible last number
		for(int j=1; j<maxM; ++j){
			// for each possible sum
			// k starts with j*i because minimum sum with i-1 places left
			// and j at this place is j*i because everything to right is >= j
			for(int k=j*i; k<maxM; ++k){
				// for each possible len-1 AND
				// next number >= current number l>=j
				for(int l=j; l<maxM; ++l){
					dp[i][j][k] += dp[i-1][l][k-j];
				}
			}
		}
	}

	LL t, m, n, k; scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld %lld", &m, &n, &k);
		// Reconstruction
		vector<LL> ans;
		LL count = 0;
		LL i=1, j, sum = m;
		for(j=n; j>=1; --j){
			// for each last digit in increasing order
			// notice i is not initialized, it is continued from previous loop
			// because next digit has to be greater than current digit
			for(; i<=m; ++i){
				count += dp[j][i][sum];
				if(count >= k)
					break;
			}
			ans.pb(i);
			// notice how k is set
			// this is like for eg:
			// 1 1 1 6
			// 1 1 2 5
			// 1 1 3 4
			// 1 2 2 4
			// 1 2 3 3
			// you need 4th overall i.e. 1 2 2 4 
			// then initially, k = 4 - (5 - 5) = 4
			// next you will start from box 116, 125 and 134
			// that will make count 3
			// next you will do box 224 and 233 which will make count 5
			// hence k = 4 was correct, you're looking at 1 224 now
			// dp[j][i][sum] is size of last box which increased size of count to >= k
			// k is what to look for in current iteration initialized to input k
			k = k - (count - dp[j][i][sum]); sum -= i; count = 0;
		}
		for(i=0; i<ans.size(); ++i)
			printf("%lld ", ans[i]);
		printf("\n");
	}
	return 0;
}