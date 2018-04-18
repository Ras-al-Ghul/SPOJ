// had got it as 2D dp similar to PIGBANK, answer depends on everything smaller than current pair
// so for i,j, dp has to be calculated for everything upto i,j-1 and i-1,j
// now I didn't know what to store in dp[i][j] - after some trials it is obvious
// that storing sum of rows as dp[i][j][0] and sum of cols as dp[i][j][1] will not help
// seems like have to store either either max(total filled area) or min(total wasted area) at each i,j
// since we're looking at min wasted area, makes sense to store that.

// MAIN IDEA was can cut slab either horizontally OR vertically
// and cutting COMPLETELY through that piece
// so read such statements in question carefully
// then considering each of the N input slabs and performing dp[i][j] = min(dp[i][j], min(vertical cut, horizontal cut))
// will NOT work - as that slab can be placed anywhere within the i,j slab and then min taken - 
// if you do that then it will work
//                 x
// +-------------------+
// |         y |_ _ _ _|   
// |           |       |   H
// |           |       |
// +-------------------+
//                   W
// vs.             
// +-------------------+
// |      _ _x_        |   
// |     |_ _ _| y     |   H
// |                   |
// +-------------------+
//                   W
// but if you place at one corner of rectangle and perform min there, it won't work, as slab may
// well have been placed in the center for minimum wastage

// what we need to do is to consider cutting at ALL possible intermediate i's
// and ALL possible intermediate j's and take min of all of those
// so O(W*H*max(W,H)) complexity, cannot do in O(W*H*N)

#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int t, W, H, N; scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &W, &H, &N);
		int dp[W+1][H+1] = {};
		// max initialize
		memset(dp, 0x3f, sizeof(dp));
		int arr[N][2];
		for(int i=0; i<N; ++i){
			scanf("%d %d", &arr[i][0], &arr[i][1]);
			// these will be 0 wastage
			dp[arr[i][0]][arr[i][1]] = 0;
		}

		for(int i=0; i<=W; ++i){
			for(int j=0; j<=H; ++j){
				// set it to zero wastage or max possible wastage at this point
				dp[i][j] = min(dp[i][j],i*j);
				// cannot be less than 0 wastage
				if(dp[i][j] == 0)
					continue;
				// for each possible vertical cut
				for(int k=1; k<i; k++)
					dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]);
				// for each possible horizontal cut
      			for(int k=1; k<j; k++)
      				dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]);
			}
		}
		printf("%d\n", dp[W][H]);
	}
	return 0;
}
