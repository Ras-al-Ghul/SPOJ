// pattern is pow(n, n-2)
// can be solved using OEIS too
// <http://oeis.org/search?q=1%2C3%2C16%2C125&language=english&go=Search>

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long n;
	long long casenum = 1;
	while(true){
		scanf("%lld", &n);
		if(n == 0)
			break;
		printf("Case %lld, N = %lld, # of different labelings = %lld\n", casenum++, n, (long long)(pow(n,n-2)));
	}
	return 0;
}