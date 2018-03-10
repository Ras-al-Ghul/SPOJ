// <https://www.quora.com/How-do-I-solve-the-problem-SPOJ-SPEED>
// found pattern using spoj toolkit

#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b){
	int temp;
	if(a < b){	
		temp = b; b = a; a = temp;
	}
	while(b != 0){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

int main(){
	int T; scanf("%d", &T);
	int a, b;
	while(T--){
		scanf("%d %d", &a, &b);
		int g = gcd(abs(a),abs(b));
		a /= g; b /= g;
		printf("%d\n", abs(a-b));
	}
	return 0;
}