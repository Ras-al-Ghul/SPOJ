// notice that the answer to how many divisors left will change
// only if a new divisor will be found - so for any i, a new
// divisor will be first found at 2*i, so only at those places
// ans[i] = ans[i-1] - 1; Else it is always ans[i] = ans[i-1]
// and of course, add the current number

#include <iostream>

using namespace std;

const int MAXN = 1000003;

int main(){
	int t, n, i;
	int remains[MAXN] = {};
	int twomul = 2;
	for(i=2; i<=MAXN; ++i){
		remains[i] = remains[i-1];
		if(i==(2*twomul)){
			remains[i]--; ++twomul;
		}
		remains[i]++;
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", remains[n]);
	}
	return 0;
}