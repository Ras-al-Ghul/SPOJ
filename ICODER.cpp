// no idea how it is working, but it is working!

// ADD does not change the number of values - though it may change the values themselves
// since it acts only like a circular shift

// MUL changes - only if you multiply by even number
// procedure:
// 1) find out if number to be multiplied is even
// 2) if yes, take gcd of number with the number of unique numbers left (modded number 65536 initially)
// 3) find nearest power of 2 of the gcd
// 4) divide number of unique numbers left by this nearest power
// multiplying by odd number does not change the number of unique numbers

// Eg: consider modded number to be 8
// 000  001  010  011  100  101  110  111
// 0	 1	  2	   3	4	 5	  6	   7

// mul by 2
// 0000 0010 0100 0110 1000 1010 1100 1110 - notice that it is left shift by 1
// 0	 2    4	   6	8	 10	  12   14
// after mod by 8:
// 000  010  100  110  000  010  100  110 - truncate up until 3 LSB
// you can see that LSB is 0 by virtue of left shift by 1
// the remaining two bits can be filled in 4 ways, giving rise to a cycle length of 4
// hence 8/2 = 4 unique numbers will be left on mul by 2

// mul by 6
// 0|000 0|110 1|100 10|010 11|000 11|110 ...
// cycle length is 4 again. It can be thought of as: you're doing left shift by atleast 2
// which is the GCD(6,8) so right most bit will be 0 - if GCD = 4, two right most bits will be 0
// GCD can be thought of as a measure which indicates that you will atleast left shift by atleast this many bits
// so divide number of unique numbers left - say 8 in this case by nearest power of 2 i.e. 2 in this case

// notice that if GCD is 4, all the rightmost two bits will be 00 because it is multiple of 4
// hence you only get to vary the bits to the left within whatever is possible by the mod

// mul by odd number say 3
// 0|000 0|011 0|110 1|001 1|100 1|111 10|010 10|101
// 0     3     6     1     4     7     2      5
// LSB can be 0 or 1, so all possible combinations possible
// if for 8 itself, nothing repeats in mod 8, metareason would mean, nothing will
// repeat for something less than 8, so conclue that mul by odd numbers does nothing to
// number of unique numbers

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int gcd(int a, int b){
	int temp;
	if(b>a)
		temp = a, a = b, b = temp;
	while(b != 0){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

int main(){
	string input;
	while(true){
		int n; scanf("%d", &n);
		if(n == 0)
			break;
		int num = 65536, m;
		while(n--){
			cin>>input>>m;
			if(input == "MUL" and m%2==0){
				int g = gcd(num, m);
				int l = int(log2(g));
				int temp = num/int(pow(2,l));
				num = temp;
			}
		}
		printf("%d\n", num);
	}
	return 0;
}