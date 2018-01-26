#include <iostream>
#include <cmath>

#define ull unsigned long long

using namespace std;

ull gcd(ull a, ull b){
	ull temp;
	if(a<b){
		temp = b; b = a; a = temp;
	}
	while(b != 0){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

int main(){
	ull n;
	while(true){
		scanf("%llu", &n);
		if(n == 0)
			break;
		ull level = (ull)(log2(n));
		ull num = 1, den = 1;
		ull cur = 1<<level;
		ull temp = cur-(cur+cur-1-n);
		ull tempnum;
		ull count = 1;
		while(level){
			tempnum = (1<<(--level));
			if(temp<=tempnum){
				num = num;
				den = num+den;
			}
			else{
				den = den;
				num = num+den;
			}
			if(temp>tempnum)
				temp-=tempnum;
		}
		ull gcdab = gcd(num, den);
		printf("%llu/%llu\n", num/gcdab, den/gcdab);
	}
	return 0;
}