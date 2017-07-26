// the number of digits in a number n is log(n)
// number of digits in n! is log(n!) = log(n) + log(n-1) + ...
// to base 10 because we use decimals
// for approximation, use Stirling's approximation

// here largest val is 100!

#include <iostream>

#define ull unsigned long long
#define MAXSIZE 100

using namespace std;

int main(){
	ull num;
	scanf("%llu", &num);

	ull result, input;

	ull product[MAXSIZE], carry[MAXSIZE];
	ull productcount, carrycount;
	ull productlenmin, carrylenmin;
	while(num--){
		result = 1;
		scanf("%llu", &input);
		for(ull i=1; i<=min(input, (ull)(50)); i++)
			result *= i;
		if(input > 50){
			productcount = MAXSIZE - 1;
			while(result/10 != 0){
				product[productcount--] = result%10;
				result /= 10;
			}
			product[productcount] = result%10;
			productlenmin = productcount;
			
			for(ull i=productlenmin; i<MAXSIZE; i++){
				// printf("%llu", product[i]);
			}
			printf("\n");
		}
		else
			printf("%llu\n", result);
	}
	return 0;
}