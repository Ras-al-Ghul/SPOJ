// Thales theorem, AB^2 + BC^2 = (2r)^2, because right angled
// differentiate and find value
// sometimes differntiate gives minimia - have to reformulate optimization objective

#include <iostream>

using namespace std;

int main(){
	int ncases,i=1;
	scanf("%d", &ncases);
	while(i<=ncases){
		long r;
		scanf("%ld", &r);

		double sum = 0.25f + (double)(4*r*r);
		printf("Case %d: %0.2f\n", i, sum);
		++i;
	}
	return 0;
}