// how to decide it is greedy is the question - seems DP at first glance
// they're saying that if lot of constraints + optimal substructure, then greedy might work
// why greedy works here and not in PARTY?

// optimal substructure is key
// two vertical cuts in a row make no differnce
// same holds for two horizontal cuts one after the other
// the question is when you have chance of both vertical and horizontal cut, what to choose?
// you should choose costlier cut first - because it will be applied to less number of pieces

// but it doesn't end there, there may be cases like 4*3 + 5*3 vs. 5*2 + 4*4
// where first index is cost, second is number of cuts to make
// the latter is actually better though we would choose the former by above rule
// so one step ahead has to be considered

// turns out above is redundant because just costs need to be considered, no need of (cost*number of cuts)
// because total number of cuts we need to make is same in whole problem
// we can change costs by ordering the costlier ones first - only across row and column
// row after row or col after col makes no difference
// when you apply costlier cut first, you ensure it is applied on less number of pieces
// cheaper cut is applied on more pieces
// above eg: 4*3 + 5*3
// 5*2 + 4*4
// latter is better because 5 is applied to 2 instead of 3
// and whenever we cut a row, it will have impact on column, and vice versa

// most important, in choice betw. DP and greedy, see if greedy works in a DP problem
// try to come up with counter example that it doesn't

// multimap if same key has multiple values
// remove specific key,value from multimap 
// <https://stackoverflow.com/questions/3952476/how-to-remove-a-specific-pair-from-a-c-multimap>

#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main(){
	int numoftestcases;
	int m,n, temp, index, totalcost;
	scanf("%d", &numoftestcases);
	while(numoftestcases--){
		scanf("%d %d", &m, &n);
		// key is cost, value is index
		multimap<int, int> xs, ys;
		for(int i=0;i<m-1;++i){
			scanf("%d", &temp);
			xs.insert(pair<int,int>(temp,i+1));
		}
		for(int i=0;i<n-1;++i){
			scanf("%d", &temp);
			ys.insert(pair<int,int>(temp,i+1));
		}

		totalcost = 0;
		// arrrow will be updated everytime there is cut along column
		// arrcol whenever there is cut along row
		int arrrow[m] = {}, arrcol[n] = {};
		while((!xs.empty()) or (!ys.empty())){
			int numofrows = 0, numofcols = 0;
			if(xs.begin() != xs.end()){
				int tempxcost = prev(xs.end())->first;
				for(int i=1;i<n;++i){
					if(arrcol[i])
						++numofrows;
				}
				if(ys.begin() != ys.end()){	
					for(int i=1;i<m;++i){
						if(arrrow[i])
							++numofcols;
					}
					int tempycost = prev(ys.end())->first;
					// you have to think of next step as well, hence the +
					// turns out the above comment is not required
					// because you just compare costs, no need to compare (cost*no.of cuts)
					if(tempycost>tempxcost/*(tempxcost*(numofrows+1) + tempycost*(numofcols+2))>(tempycost*(numofcols+1) + tempxcost*(numofrows+2))*/){
						index = prev(ys.end())->second;
						auto iterpair = ys.equal_range(prev(ys.end())->first);
						ys.erase(prev(iterpair.second));
						arrcol[index] = 1;
						totalcost += (tempycost * (numofcols + 1));
					}
					else{
						index = prev(xs.end())->second;
						auto iterpair = xs.equal_range(prev(xs.end())->first);
						xs.erase(prev(iterpair.second));
						arrrow[index] = 1;
						totalcost += (tempxcost * (numofrows + 1));
					}
				}
				else{
					index = prev(xs.end())->second;
					auto iterpair = xs.equal_range(prev(xs.end())->first);
					xs.erase(prev(iterpair.second));
					arrrow[index] = 1;
					totalcost += (tempxcost * (numofrows + 1));
				}
			}
			else{
				for(int i=1;i<m;++i){
					if(arrrow[i])
						++numofcols;
				}
				int tempycost = prev(ys.end())->first;
				index = prev(ys.end())->second;
				auto iterpair = ys.equal_range(prev(ys.end())->first);
				ys.erase(prev(iterpair.second));
				arrcol[index] = 1;
				totalcost += (tempycost * (numofcols + 1));
			}
		}
		printf("%d\n", totalcost);
	}

	return 0;
}