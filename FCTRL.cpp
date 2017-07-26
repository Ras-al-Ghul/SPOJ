// so I luckily stumbled upon the correct solution
// it wasn't about the number of continuous 5's and 0's from the last that I'd thought about
// i did a %5 and /5 to stumble upon the correct solution
// but it was TLE
// the missing link was the number of 'powers' of 5
// multiples of 5 and even numbers, these give 0s
// even numbers are more than the number of multiples of 5
// so just count the number of multiples of 5

#include <iostream>

#define ull unsigned long long

using namespace std;

int main(){
	ull num;
	scanf("%llu", &num);

	ull input, zn, base, quo;
	while(num--){
		scanf("%llu", &input);
		zn = 0;
		base = 5;
		while(true){
			if(base <= input){
				quo = input/base;
				zn += quo;
			}
			else
				break;
			base *= 5;
		}
		printf("%llu\n", zn);
	}
	return 0;
}

// my soln

// int main(){
// 	ull num;
// 	scanf("%llu", &num);

// 	ull input;
// 	ull temp, zn, rem;
// 	bool flag;
// 	while(num--){
// 		scanf("%llu", &input);
// 		zn = 0;
// 		flag = false;
// 		for(ull i=5; i<=input; i+=5){
// 			temp = i;
// 			// zn += 1;
// 			rem = temp % 5;
// 			temp = temp / 5;
// 			while(rem == 0){
// 				zn += 1;
// 				rem = temp % 5;
// 				temp = temp / 5;
// 			}
// 		}
// 		printf("%lld\n", zn);
// 	}
// 	return 0;
// }
