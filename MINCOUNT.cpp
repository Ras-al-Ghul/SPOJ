// do first few cases properly
// use OEIS <http://oeis.org/search?q=0%2C1%2C2%2C3%2C5%2C7%2C9&sort=&language=english&go=Search>
// quadruples, forms AP

#include <iostream>

#define ull unsigned long long

using namespace std;

int main(){
	ull ncases,h;
	scanf("%llu", &ncases);
	while(ncases--){
		scanf("%llu", &h);
		if(h==0){
			printf("0\n");
			continue;
		}
		h-=1;
		ull rem = h%3;

		ull start = h/3;

		ull commondiff = start + 1;

		start = (3*start*(start+1))/2;

		printf("%llu\n", start+((rem)*commondiff));

	}
	return 0;
}