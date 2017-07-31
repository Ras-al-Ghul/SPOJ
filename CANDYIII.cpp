// be careful in seemingly simple looking problems
// in such cases, more often than not Input test cases will be huge, etc.

#include <iostream>

#define ull unsigned long long

using namespace std;

int main(){
	ull numoftestcases;
	scanf("%llu", &numoftestcases);

	ull numofchildren;
	ull sum, tempval;
	while(numoftestcases--){
		scanf("%llu", &numofchildren);
		sum = 0;
		for(ull i=0; i<numofchildren; i++){
			scanf("%llu", &tempval);
			sum = (sum + tempval) % numofchildren;
		}
		if(sum==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}