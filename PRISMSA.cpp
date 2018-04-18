// diff. S formula with respect to a and substitue for h using V and a
// diff. = 0, solve for a
// plug a in S formula written only in terms of a

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t; scanf("%d", &t);
	double vol, S, a;
	while(t--){
		scanf("%lf", &vol);
		a = pow(4*vol,0.3333333333333333333333333);
		S = 3*a*a*sqrt(3)/2;
		printf("%.10lf\n", S);
	}
	return 0;
}