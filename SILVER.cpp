// Given a rod of length n, divide it into minimum number of parts 
// such that you can generate a rod of each length from 1 to number n.
// For given n, 2^m<= n < 2^(m+1) , number of cuts will be m and
// hence numbers of parts will be m+1. In present case n=7 lies in the
// range [4,8), so number of cuts(divide/break) = 2

// think of it as binary number representation - 0 - you don't give, 1 you give -
// least number of bits needed to represent a number - brilliant

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	while(true){
		scanf("%d", &n);
		if(n==0)
			break;
		int x = int(log2(n));
		printf("%d\n", x);
	}
	return 0;
}