#include <iostream>

#define ull unsigned long long

using namespace std;

int main(){
	ull numoftestcases;
	scanf("%llu", &numoftestcases);
	
	ull a, b;
	while(numoftestcases--){
		scanf("%llu %llu", &a,  &b);
		ull x=1, y=a;
		while(b>0){
			if(b%2==1)
				x=(x*y)%10;
			y=(y*y)%10;
			b/=2;
		}
		cout<<x%10<<endl;
	}
	return 0;
}