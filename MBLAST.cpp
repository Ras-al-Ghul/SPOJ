// similar to EDIST which in turn is similar to LCS
// in all these problems, action seems to be happening at the rightmost end
// one possible way to reason about this is that if you claim that x-4,y-4 to
// x,y is optimal, it has to be through sequence of operations,
// you can order the operations incrementally, say x-4,y-4 to x-4,y-3, etc.
// one allowed operation at a time and finally get to x,y - which means if you have
// optimal answer to x-1,y and x,y-1 and x-1,y-1, you can get the final optimal answer using
// one allowed operation
// if you say, you will add/delete/edit to left of x-4,y-4, then you can consider steps after
// starting from that left element and come up to whatever you'll end up with after add/delete/edit
// to left of x-4,y-4 - because the operations are communicative

// look at sequence alignment from Tim Roughgarden <https://www.youtube.com/watch?v=uYH6fSQJmuw>
// he says X,Y if optimal are xm and yn with different number of gaps
// consider rightmost part - 2 possibilities for X and 2 for Y - either letter or gap
// so 4 possibilities when matched, but gap with gap is never done
// so i) if two letters matched and are optimal, then X-xm and Y-yn are optimal
// ii) if xm matched  with gap, then X-xm and Y are optimal iii) if ym matched with gap..
// proof for i) if X-xm and Y-yn are not optimal, then use that optimal solution to match
// X-xm and Y-yn and then match xm and yn to get better than X,Y which is a contradiction
// - so finally, find optimal amongst these three cases

#include <iostream>
#include <string>

using namespace std;

int main(){
	string a, b;
	cin>>a>>b;
	int lena = a.length(), lenb = b.length(), i, j;
	int blank; scanf("%d", &blank);

	int dp[lena+1][lenb+1] = {};
	for(i=1; i<=lena; ++i)
		dp[i][0] = dp[i-1][0] + blank;
	for(i=1; i<=lenb; ++i)
		dp[0][i] = dp[0][i-1] + blank;

	for(i=1; i<=lena; ++i){
		for(j=1; j<=lenb; ++j){
			dp[i][j] = dp[i][j-1] + blank;
			dp[i][j] = min(dp[i][j], dp[i-1][j-1]+blank+blank);
			dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(abs(a[i-1]-b[j-1])));
			dp[i][j] = min(dp[i][j], dp[i-1][j] + blank);
		}
	}

	printf("%d\n", dp[lena][lenb]);
	return 0;
}