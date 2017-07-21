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