// first problem, simple brute force
// scanf, printf is faster than cin, cout
// lookout for memory optimization, not just for runtime
// scanf uses & for input

#include <iostream>

using namespace std;

int main(){
	int number;
	while(true){
		scanf("%d", &number);
		if(number == 42)
			break;
		else
			printf("%d\n", number);
	}
	
	return 0;
}