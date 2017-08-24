// reasoning using first few test cases
// try for npieces = 1, 2, 3, 4, 5, 6, 7
// by then you'll be clear that first player can win no matter what
// hence the pattern must continue for higher numbers as well

#include <iostream>

#define ll long long

using namespace std;

int main(){
	ll ncases;
	scanf("%lld", &ncases);
	ll npieces, whofirst;
	while(ncases--){
		scanf("%lld %lld", &npieces, &whofirst);
		if(whofirst)
			cout<<"Pagfloyd wins."<<endl;
		else
			cout<<"Airborne wins."<<endl;
	}
	return 0;
}
