// tried to be too smart

// one mistake was putting the print statment outside loop for " " and endl
// never do this without checking some condition - this means you're blindly printing
// some edge case will fail

// second mistake was using ull instead of ll
// d can be -ve, though all the terms in the AP are positive
// so always remember to check if values can go negative whenever using unsigned numbers

#include <iostream>

#define ll long long

using namespace std;

int main(){
	ll numoftestcases;
	scanf("%llu", &numoftestcases);

	ll third, thirdlast, sum;
	ll a, n, d;
	while(numoftestcases--){
		scanf("%llu %llu %llu", &third, &thirdlast, &sum);

		n = (sum * 2)/(third + thirdlast);
		d = (third - thirdlast)/(5-n);
		a = third - (2*d);

		cout<<n<<endl;
		ll i = 0;
		for(i=0; i<n; i++){
			if(i==n-1)
				cout<<a+(i*d)<<endl;
			else
				cout<<a+(i*d)<<" ";
		}
			
	}

	return 0;
}