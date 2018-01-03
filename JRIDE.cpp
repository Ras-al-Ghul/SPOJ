#include <iostream>

using namespace std;

int main(){
	int b;
	scanf("%d", &b);
	for(int j=1; j<=b; ++j){
		int s;
		scanf("%d", &s);

		int temp;
		int bestsofar = 0, bestcount = 0, beststartindex = -1, bestend = -1; 
		int cursum = -1;
		int startindex = -1, counter = 0;
		bool feasible = false;
		for(int i=0; i<s-1; ++i){
			scanf("%d", &temp);
			if(temp>0){
				feasible = true;
				++counter;
				if(cursum == -1){
					cursum = 0;
					startindex = i+1;
				}
				cursum += temp;
				if(bestsofar <= cursum){
					if(bestsofar < cursum){
						bestsofar = cursum; bestcount = counter;
						beststartindex = startindex; bestend = i+2;
					}
					else{
						if(bestcount < counter){
							bestcount = counter;
							beststartindex = startindex;
							bestend = i+2;
						}
					}
				}
			}
			else{
				if(cursum + temp >= 0){
					cursum += temp; ++counter;
				}
				else{
					cursum = -1; counter = 0;
				}
			}
		}
		if(feasible){
			printf("The nicest part of route %d is between stops %d and %d\n", j, beststartindex, bestend);
		}
		else{
			printf("Route %d has no nice parts\n", j);
		}
	}
	return 0;
}