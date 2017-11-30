// Read about two-pointer algorithm
// <https://tp-iiita.quora.com/The-Two-Pointer-Algorithm>
// Can use in sorted contiguous arrays, sets, sequences (which need not be contiguous)
// Some 'sequence' problems can be sorted and then tried to be solved - if order is not important - last example in the Quora post

// One approach is using below
// Lookup is almost constant but construction takes time
// Note that unordered_map is faster than map in this case
// <https://stackoverflow.com/questions/13799593/how-to-choose-between-map-and-unordered-map>
// Reserve buckets using reserve keyword
// <https://stackoverflow.com/questions/42373232/why-does-stdunordered-map-have-a-reserve-method>

// Other is actually using binary search with sorting c,d list and looking if -(key a,b) exists
// Fast to construct but everytime lookup is logarithmic
// Can use binary_search or equal_range
// <http://www.studytonight.com/cpp/stl/stl-searching>

#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
	int count;
	scanf("%d", &count);
	int arra[count], arrb[count], arrc[count], arrd[count];
	int ac=0,bc=0,cc=0,dc=0;

	unordered_map<int,int> secondpair;
	secondpair.reserve(count*count);

	int i,j;

	while(count--){
		scanf("%d %d %d %d", &arra[ac], &arrb[bc], &arrc[cc], &arrd[dc]);
		++ac;++bc;++cc;++dc;
	}

	// insert key into map if it already exists
	for(i=0;i<cc;++i){
		for(j=0;j<dc;++j){
			secondpair[arrc[i] + arrd[j]] += 1;
		}
	}

	int ans = 0;
	for(i=0;i<ac;++i){
		for(j=0;j<bc;++j){
			auto it = secondpair.find(-(arra[i]+arrb[j]));
			if(it!=secondpair.end()){
				ans += (it->second);
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}