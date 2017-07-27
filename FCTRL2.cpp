// the number of digits in a number n is log(n)
// number of digits in n! is log(n!) = log(n) + log(n-1) + ...
// to base 10 because we use decimals
// for approximation, use Stirling's approximation

// here largest val is 100!
// pretty straightforward once you realize that carry need not be an array as it can only grow so big - three or four digits max
// that will fit in ull
// use same datatypes ull throughout, do not mix up with signed numbers
// can also optimize for direct solving up until a particular point and then using array for solving
// source code size limit was 2000 bytes = 2 kB for this problem

#include <iostream>

#define ull unsigned long long
#define MAXSIZE 160

using namespace std;

int main(){
	ull num;
	scanf("%llu", &num);

	ull result, input;

	ull product[MAXSIZE];
	ull productcount;
	ull productlenmin;
	ull carry; // the carry number
	ull curmultiplier; // number >= 14
	ull tempprod; // product of product[productcount] and curmultiplier
	while(num--){
		result = 1;
		scanf("%llu", &input);
		for(ull i=1; i<=min(input, (ull)(13)); i++)
			result *= i;
		if(input > 13){
			productcount = MAXSIZE - 1;
			while(result/10 != 0){
				product[productcount--] = result%10;
				result /= 10;
			}
			product[productcount] = result%10;
			productlenmin = productcount;
			// 13! is stored in product and productlenmin is the index
			
			curmultiplier = 14;
			while(curmultiplier <= input){
				// initialize carry
				carry = 0;
				for(ull i=MAXSIZE-1; i>=productlenmin; i--){
					tempprod = (product[i] * curmultiplier) + carry;
					product[i] = tempprod%10;
					carry = tempprod/10;
					productcount = i-1; // note that this index is empty
				}
				while(carry/10 != 0){
					product[productcount--] = carry%10;
					carry /= 10;
				}
				product[productcount] = carry%10;
				productlenmin = productcount;
				curmultiplier++;
			}
			for(ull i=productcount; i<MAXSIZE; i++){
				printf("%llu", product[i]);
			}
			printf("\n");
		}
		else
			printf("%llu\n", result);
	}
	return 0;
}