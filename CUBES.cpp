// dict and set problem
// whenever brute force, think about dict/set

#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
	map<int, pair<int, int> > table;
	for(int i=2; i<101; ++i){
		for(int j=101; j>=2; --j){
			table.insert(pair<int, pair<int, int> >((i*i*i)+(j*j*j), pair<int, int>(i,j)));
		}
	}
	for(int i=2; i<101; ++i){
		int cube = i*i*i;
		set<int> bvals;
		for(int j=2; j*j*j < cube; ++j){
			auto it = (table.find(cube-(j*j*j)));
			if(it != table.end()){
				if(bvals.find(j) == bvals.end()){
					printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, it->second.first, it->second.second);
					bvals.insert(it->second.first);
					bvals.insert(it->second.second);
				}
			}
		}
	}

	return 0;
}