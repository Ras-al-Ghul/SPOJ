// don't use string problem

#include <iostream>
#include <string>

#define ll long long

using namespace std;

int main(){
	ll ncases;
	scanf("%lld", &ncases);
	string op;
	ll ans, temp;
	while(ncases--){
		ans = 0;
		
		scanf("%lld", &ans);
		cin>>op;

		for(;op != "=";){
			scanf("%lld", &temp);
			if(op == "+")
				ans += temp;
			else if(op == "-")
				ans -= temp;
			else if(op == "*")
				ans *= temp;
			else
				ans /= temp;
			cin>>op;
		}
		printf("%lld\n", ans);
	}
	return 0;
}