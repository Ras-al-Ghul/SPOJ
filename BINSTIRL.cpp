// <https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind>

#include <iostream>

using namespace std;

int main(){
	int d;
	scanf("%d", &d);
	long n, m;
	while(d--){
		scanf("%ld %ld", &n, &m);
		printf("%d\n", !((n-m)&((m-1)/2)));
	}
	return 0;
}