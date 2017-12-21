// <http://codeinblood.blogspot.in/2017/01/decipher-spoj-problem-solution.html>

#include <iostream>

#define ll long long

using namespace std;

int main(){
	int ncases;
	scanf("%d", &ncases);
	ll a, b, c;
	while(ncases--){
		scanf("%lld %lld %lld", &a, &b, &c);
		printf("%lld\n", ((a*a)-(2*b)));
	}
	return 0;
}