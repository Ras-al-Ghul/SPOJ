// I'd got so far as to realize that the dp state consists of
// string length, adj. bit count - also had realized that there are
// two or four possible cases - stings ending with 0, strings ending with 1,
// and/or maybe even strings beginning with 1 and strings beginning with 0
// append to this - also realized that answer depends on answers of same string
// length and answer of (string length - 1) - but could not figure out how to
// avoid repetition - i.e. some were repeating - mistake was I was considering
// current case as a whole - but in fact, since answer to previous stage is stored
// in terms of ending with 0 and ending with 1, answer to current stage should
// also be stored in terms of ending with 0 and ending with 1 - then it is easy
// no repetitions

#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

int main(){
	int p; scanf("%d", &p);
	// [][][2] - 0 is ending with 0, 1 is ending with 1
	int dp[MAX+1][MAX+1][2] = {};
	dp[0][1][0] = 1; dp[0][1][1] = 1;

	for(int i=2; i<=MAX; ++i){
		dp[0][i][0] = dp[0][i-1][0] + dp[0][i-1][1];
		dp[0][i][1] = dp[0][i-1][0];
		for(int j=1; j<i; ++j){
			dp[j][i][0] = dp[j][i-1][0] + dp[j][i-1][1];
			dp[j][i][1] = dp[j][i-1][0] + dp[j-1][i-1][1];
		}
	}
	while(p--){
		int num, n, k; scanf("%d %d %d", &num, &n, &k);
		printf("%d %d\n", num, dp[k][n][0]+dp[k][n][1]);
	}
	return 0;
}