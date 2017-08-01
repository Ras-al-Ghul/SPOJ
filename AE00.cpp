// try to simplify the math even though it may take time
// this will lead to faster solutions
// be careful of underflows wherever there are subtractions involved and
// you are using unsigned numbers

#include <iostream>

#define ll long long

using namespace std;

int main(){
	ll input;
	scanf("%lld", &input);

	ll sum = 0, diff;
	for(ll i = 1; i<=input; i++){
		ll div = input/i;
		diff = div - i;
		if(diff>=0)
			sum = sum + (diff+1);
	}
	printf("%lld\n", sum);
	return 0;
}