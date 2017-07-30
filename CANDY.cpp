// div in long long and unsigned long long fails
// have to use int in such cases

// there is some confusion between where to use int and long long
// as in for counter variables

#include <iostream>

#define MAXSIZE 10001
#define ull unsigned long long

using namespace std;

int main(){
	int block;
	ull blocksize;

	ull arrofcandies[MAXSIZE];
	ull candiescounter;

	ull sum, ineach, tomove;
	while(true){
		scanf("%d", &block);
		if(block==-1)
			break;

		blocksize = block;
		candiescounter = 0;
		sum = 0;
		while(blocksize--){
			scanf("%llu", &arrofcandies[candiescounter++]);
			sum += arrofcandies[candiescounter-1];
		}

		if(sum%candiescounter != 0){
			printf("-1\n");
			continue;
		}

		ineach = sum/candiescounter;
		tomove = 0;
		for(ull i=0; i<candiescounter; i++){
			if(arrofcandies[i] < ineach)
				tomove += (ineach-arrofcandies[i]);
		}
		printf("%llu\n", tomove);

	}

	return 0;
}