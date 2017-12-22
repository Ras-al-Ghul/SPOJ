// <https://www.geeksforgeeks.org/count-digits-factorial-set-2/>

#include <bits/stdc++.h>

using namespace std;

long long findDigits(long long n)
{
    // factorial of -ve number doesn't exists
    if (n < 0)
        return 0;
 
    // base case
    if (n <= 1)
        return 1;
 
    // Use Kamenetsky formula to calculate the
    // number of digits
    double x = ((n*log10(n/M_E)+log10(2*M_PI*n)/2.0));
 
    return floor(x)+1;
}

int main(){
	int ncases;
	scanf("%d", &ncases);
	while(ncases--){
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", findDigits(n));
	}
	return 0;
}