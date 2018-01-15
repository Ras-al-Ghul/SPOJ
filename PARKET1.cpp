#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int R, B;
	scanf("%d %d", &R, &B);
	int temp = int(sqrt(((4-R)*(4-R))-(4*2*(2*B))));
	int l, b;
	if((R-4) - temp > 0)
		l = ((R-4) - temp)/(2*2);
	else
		l = ((R-4) + temp)/(2*2);
	b = B/l;
	printf("%d %d\n", max(l+2,b+2), min(l+2,b+2));
	return 0;
}