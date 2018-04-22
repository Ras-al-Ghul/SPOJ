#include <iostream>

#define ull unsigned long long

using namespace std;

const ull MOD = 1000000007;

int main(){
	int t; scanf("%d", &t);
	ull a = 2, b;
	while(t--){
		scanf("%llu", &b);
		--b;
		ull x=1, y=a;
		while(b>0){
			if(b%2==1)
				x=(x*y)%MOD;
			y=(y*y)%MOD;
			b/=2;
		}
		cout<<x%MOD<<endl;
	}
}