// direct formula uses float ops, hence use modified method
// <http://www.geeksforgeeks.org/eulers-totient-function/>

#include <iostream>

using namespace std;

int main(){
	long ncases;
	scanf("%ld", &ncases);
	while(ncases--){
		long num;
		scanf("%ld", &num);
		long result = num;
		for(int i=2; i*i<=num; ++i){
			if(num%i == 0){
				// it is prime factor
				while(num%i == 0){
					num /= i;
				}
				result -= (result/i);
			}
		}
		if(num > 1)
			result -= (result/num);
		printf("%ld\n", result);
	}


	return 0;
}