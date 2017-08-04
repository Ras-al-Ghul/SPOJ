// triangle recursion formulation to deriving a one shot constant time formula
// is a long process

// oeis.org is awesome
// look for first few terms, enter the series, get the formula

// special series some

// <https://math.stackexchange.com/questions/203873/how-many-triangles>

#include <iostream>
#define ull unsigned long long
using namespace std;
int main(){
	ull n;
	scanf("%llu", &n);
	ull t, s, r, p;
	while(n--){
		scanf("%llu", &t);
		// r = 0, s = 0;
		// r += (((t*(t+1))/2) + (((t-1)*(t))/2));
		// p = t;
		// if(p>3)
		// 	s = t-3;
		// while(p--){
		// 	if(p==s){
		// 		r+=(2*((p*(p+1))/2));
		// 		s-=2;
		// 	}
		// 	else
		// 		r+=((p*(p+1))/2);
		// }
		cout<<(t*(t+2)*(2*t+1))/8<<endl; 
	}
	return 0;
}