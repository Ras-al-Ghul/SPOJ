// In problems like these, see the number, here the % number
// notice that it is prime - 4000000007 - may have some helpful property

// these two links suffice
// given n and prime p, check if square root of n under %p exists or not
// i.e. if x exists such that (x*x)%p = n
// uses Fermat's Little theorem
// ? means congruence relation in the below link
// <https://www.geeksforgeeks.org/eulers-criterion-check-if-square-root-under-modulo-p-exists/>
// find square root under %p given n if p is of form 4i+3
// <https://www.geeksforgeeks.org/find-square-root-under-modulo-p-set-1-when-p-is-in-form-of-4i-3/>
// p = ((+-n)^((p + 1)/4)) 

// quadratic residue of prime or prime power modulus
// quadratic residue is: x^2 cong q(mod n)
// q is the quadratic residue
// <https://en.wikipedia.org/wiki/Quadratic_residue#Prime_or_prime_power_modulus>

#include <iostream>
#include <ctime>
#include <string>

#define ull unsigned long long

using namespace std;

const ull p = 4000000007;

int main(){
	
	ull a;
	scanf("%llu", &a);
	ull b=(p+(ull)(1))/(ull)(4);
	ull x = 1, y = a;
	while(b>0){
		if(b%2==1)
			x=(x*y)%p;
		y=(y*y)%p;
		b/=2;
	}
	x = x%p;

	// p or p-x, minimum of those
	// (+n^((p + 1)/4)) or (-n ^ ((p + 1)/4))
	// like example: 3%7 = 3, (-3)%7 = 7-3 = 4
	time_t rawtime = min(x,p-x);
	struct tm * ptm;
	ptm = gmtime(&rawtime);

	const char* days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	printf("%s %s %02d %02d:%02d:%02d %d\n", days[ptm->tm_wday], months[ptm->tm_mon], ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, ptm->tm_year+1900);

	return 0;
}