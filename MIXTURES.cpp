// feels good to solve this
// try to find the ordering using pen and paper in dp algos
// modified version of matrix chain multiplication
// two important things
// find order in which they're filled - diagonal at a time
// account for all combinations - mentioned below
#include <iostream>
#include <string>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
	string line;
	ll ncolors,i,j,k,l,m;
	while(true){
		line = "";
		getline(cin, line);
		if(line.empty())
			break;
		ncolors = stoll(line);
		ll arr[ncolors];
		for(i=0;i<ncolors;i++)
			scanf("%lld", &arr[i]);
		getline(cin,line);

		if(ncolors==1){
			cout<<0<<endl;
			continue;
		}

		// first holds value
		// second holds cumulative sum
		pair<ll,ll> grid[ncolors][ncolors]={};

		// initialize all main diagonal elements and
		// the diagonal above - the diagonal above is direct product
		for(i=0;i<ncolors;i++){
			grid[i][i].f = arr[i];grid[i][i].s = arr[i];
			
			grid[i-1][i].f = grid[i-1][i-1].f*grid[i][i].f;
			grid[i-1][i].s = (grid[i-1][i-1].s+grid[i][i].s)%100;
		}
		// for(i=0;i<ncolors;i++){
		// 	for(j=0;j<ncolors;j++)
		// 		cout<<grid[i][j].f<<"-"<<grid[i][j].s<<" ";
		// 	cout<<endl;
		// }
		
		// temp is ncolors - 1 because the diagonal above the main diagonal is
		// already done
		// we need to solve one diagonal in every iteration
		// each element [i][j] is min([i][j-1], [i+1][j]) and multiply accordingly

		// the problem with just the above is some combinations are not considered
		// for example, for {a,b,c,d}, the above considers
		// (abc)(d) = (ab)(c)(d) and (a)(bc)(d)
		// (a)(bcd) = (a)(bc)(d) and (a)(b)(cd)
		// but it does not cover (ab)(cd)
		// have to account for this
		// similar for {a,b,c,d,e}
		// luckily this can be done in one loop - the while(count) loop
		// for [i][j], initialize to [i][j-2] and [i+1+count][j] and decrement
		// column in the first and row in the second - these both form a pair - like (ab)(cd)
		int temp = ncolors-1; int count;
		for(k=2;k<ncolors;k++){
			temp--;
			for(i=0;i<temp;i++){
				j = k+i;
				grid[i][j].f = min((grid[i][j-1].f+(grid[i][j-1].s*grid[j][j].s)),(grid[i+1][j].f+(grid[i+1][j].s*grid[i][i].s)));
				grid[i][j].s = (grid[i][j-1].s+grid[j][j].s)%100;

				count = k-2;
				l = j-2; m = i+1+count;
				while(count--){
					//l is cols & m is rows
					grid[i][j].f = min(grid[i][j].f, (grid[i][l].f+grid[m][j].f)+(grid[i][l].s*grid[m][j].s));
					l--;m--;
				}
			}

			// for(i=0;i<ncolors;i++){
			// 	for(j=0;j<ncolors;j++)
			// 		cout<<grid[i][j].f<<" ";
			// 	cout<<endl;
			// }
		}
		// for(i=0;i<ncolors;i++){
		// 	for(j=0;j<ncolors;j++)
		// 		cout<<grid[i][j].f<<"-"<<grid[i][j].s<<" ";
		// 	cout<<endl;
		// }
		cout<<grid[0][ncolors-1].f<<endl;
	}
	return 0;
}