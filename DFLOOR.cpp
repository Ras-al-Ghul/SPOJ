// beautiful application of Linear Algebra and observations/deductions
// OBV1: Visiting a cell odd number of times will invert state, even number, same state
// So useless to visit more than once - so either visit or not
// OBV2: State of cell is dependent only on at max 4 neighbours - so write
// eqn. in terms of neighbours i.e. ans[i][j] + ans[i+1][j] +.. if the sum
// turns out to be odd, then final state of i,j will be inverted, else same as orig state
// To conclude, we need it to be odd if 0 inititally, even otherwise
// OBV3: Carrying on from above, value of every cell on particular row will
// depend on values of cells on previous row - so apply equation for top row
// and if 0 initially, we need sum to be odd and sum even if 1 initially
// So if somehow we fix the values of top row, we will know what value to use
// for cell immediately below - to make the top row cell 1 or 0
// And this is an induction and continues downwards
// So for top row, try all possible combinations
// Then for all the next rows, if top row respective col is 0, flip, else let it remain same
// finally bottom row, check if you have all ones, then possible, else not

// This was computational approach given on
// <https://www.quora.com/How-can-I-solve-DFLOOR-problem-on-SPOJ>
// Mathematical approach is to write it as Mx = y and solve for x
// <http://aix1.uottawa.ca/~jkhoury/game.html>
// <http://aix1.uottawa.ca/~jkhoury/gamesolution.htm>
// by solving a set of linear equations - also can find path with minimum possible steps with this

#include <iostream>
#include <vector>

#define mp make_pair
#define pb push_back

using namespace std;

int main(){
	int y, x, i, j, k;
	while(true){
		cin>>y>>x;
		if(x == 0)
			break;
		bool orig[x][y]; char c;
		for(i=0; i<x; ++i){
			for(j=0; j<y; ++j){
				cin>>c;
				orig[i][j] = (c=='1');
			}
		}

		vector<pair<int, int> > finalmoves;
		bool dup[x][y]; bool overallflag = false;
		for(i=0; i<(1<<y); ++i){
			vector<pair<int, int> > moves;
			// copy from orig array
			for(j=0; j<x; ++j){
				for(k=0; k<y; ++k){
					dup[j][k] = orig[j][k];
				}
			}

			// set the topmost row - drawn from all possible subsets of topmost row
			// if bit of that subset is one, means that you flip bit at that position
			j = i;
			// first col
			if(j&1){
				moves.pb(mp(1,1));
				dup[0][0] = !dup[0][0]; dup[0][1] = !dup[0][1]; dup[1][0] = !dup[1][0];
			}
			// between cols
			j = j>>1;
			for(k=1; k<y-1; ++k){
				if(j&1){
					moves.pb(mp(k+1,1));
					dup[0][k] = !dup[0][k]; dup[0][k+1] = !dup[0][k+1];
					dup[0][k-1] = !dup[0][k-1]; dup[1][k] = !dup[1][k];
				}
				j = j>>1;
			}
			// j>>1 for this is already done
			// last col
			if(j&1){
				moves.pb(mp(y,1));
				dup[0][y-1] = !dup[0][y-1]; dup[0][y-2] = !dup[0][y-2]; dup[1][y-1] = !dup[1][y-1];
			}

			// in between rows
			for(j=1; j<x-1; ++j){
				// make j-1 row all 1
				// first col
				if(dup[j-1][0] == 0){
					moves.pb(mp(1,j+1));
					dup[j-1][0] = !dup[j-1][0];
					dup[j][0] = !dup[j][0]; dup[j][1] = !dup[j][1];
					dup[j+1][0] = !dup[j+1][0];
				}
				// between cols
				for(k=1; k<y-1; ++k){
					if(dup[j-1][k] == 0){
						moves.pb(mp(k+1,j+1));
						dup[j-1][k] = !dup[j-1][k];
						dup[j][k] = !dup[j][k]; dup[j][k-1] = !dup[j][k-1]; dup[j][k+1] = !dup[j][k+1];
						dup[j+1][k] = !dup[j+1][k];
					}
				}
				// last col
				if(dup[j-1][y-1] == 0){
					moves.pb(mp(y,j+1));
					dup[j-1][y-1] = !dup[j-1][y-1];
					dup[j][y-1] = !dup[j][y-1]; dup[j][y-2] = !dup[j][y-2];
					dup[j+1][y-1] = !dup[j+1][y-1];
				}
			}

			// make j-1 row all 1
			// first col
			if(dup[x-2][0] == 0){
				moves.pb(mp(1,x));
				dup[x-2][0] = !dup[x-2][0];
				dup[x-1][0] = !dup[x-1][0]; dup[x-1][1] = !dup[x-1][1];
			}
			// between cols
			for(k=1; k<y-1; ++k){
				if(dup[x-2][k] == 0){
					moves.pb(mp(k+1,x));
					dup[x-2][k] = !dup[x-2][k];
					dup[x-1][k] = !dup[x-1][k]; dup[x-1][k-1] = !dup[x-1][k-1]; dup[x-1][k+1] = !dup[x-1][k+1];
				}
			}
			// last col
			if(dup[x-2][y-1] == 0){
				moves.pb(mp(y,x));
				dup[x-2][y-1] = !dup[x-2][y-1];
				dup[x-1][y-1] = !dup[x-1][y-1]; dup[x-1][y-2] = !dup[x-1][y-2];
			}

			bool flag = false;
			for(k=0; k<y; ++k)
				if(dup[x-1][k] == 0){
					flag = true; break;
				}
			if(flag == false){
				overallflag = true;
				for(j=0; j<moves.size(); ++j)
					finalmoves.pb(moves[j]);
				break;
			}
		}
		if(overallflag){
			printf("%d\n", int(finalmoves.size()));
			for(i=0; i<finalmoves.size(); ++i)
				printf("%d %d\n", finalmoves[i].first, finalmoves[i].second);
		}
		else
			printf("-1\n");
	}
	return 0;
}