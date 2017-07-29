// pattern identification

#include <iostream>

using namespace std;

int main(){
	int numoftestcases;
	scanf("%d", &numoftestcases);

	int x, y;
	while(numoftestcases--){
		scanf("%d %d", &x, &y);
		if((x-y) == 2){
			if(x>=2){
				if(x%2 == 0)
					printf("%d\n", x+y);
				else
					printf("%d\n", (x-1)+(y-1)+1);
			}
		}
		else if(x==y){
			if(x%2 == 0)
				printf("%d\n", x+y);
			else
				printf("%d\n", (x-1)+(y-1)+1);
		}
		else
			printf("No Number\n");
	}

	return 0;
}