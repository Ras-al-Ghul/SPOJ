#include <iostream>

#define ull unsigned long long

using namespace std;

int main(){
	ull numoftestcases;
	scanf("%llu", &numoftestcases);

	ull number;
	ull rangenum, value;
	ull num, den;
	ull temp;
	while(numoftestcases--){
		scanf("%llu", &number);

		rangenum = 1;
		value = 0;
		while(true){
			if(number>value and number<=(value+rangenum)){
				temp = number-value;
				break;
			}
			value += rangenum;
			rangenum += 1;
		}
		if(rangenum%2 == 0){
			num = 1;
			den = rangenum;
			for(int i=1; i<temp; i++){
				num += 1;
				den -= 1;
			}
			printf("TERM %llu IS %llu/%llu\n",number, num, den);
		}
		else{
			num = rangenum;
			den = 1;
			for(int i=1; i<temp; i++){
				num -= 1;
				den += 1;
			}
			printf("TERM %llu IS %llu/%llu\n", number, num, den);
		}
	}
	return 0;
}