// spoj toolkit was wrong

#include <iostream>

#define ul unsigned long

using namespace std;

int main(){
	ul a, b;
	while(true){
		scanf("%lu %lu", &a, &b);
		if(a == 0)
			break;
		if(a<b){
			ul temp = b;
			b = a;
			a = temp;
		}
		ul num = a;
		while(num%b != 0){
			num += a;
		}
		printf("%lu\n", (num/a)*(num/b));
	}
	return 0;
}