#include <iostream>

using namespace std;

int main(){
	int t, n, temp; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n==1)
			printf("poor conductor\n");
		else{
			printf("%d ", ((n-2)/5) + 1);
			temp = (n-2)%5;
			if((((n-2)/5) + 1)%2==1){
				if(temp==0)
					printf("W L\n");
				else if(temp==1)
					printf("A L\n");
				else if(temp==2)
					printf("A R\n");
				else if(temp==3)
					printf("M R\n");
				else
					printf("W R\n");
			}
			else{
				if(temp==0)
					printf("W R\n");
				else if(temp==1)
					printf("M R\n");
				else if(temp==2)
					printf("A R\n");
				else if(temp==3)
					printf("A L\n");
				else
					printf("W L\n");
			}
		}
	}
	return 0;
}