#include <iostream>

using namespace std;

int main(){
	int n, ip; scanf("%d", &n);
	int sieve[1000000+1][2] = {};
	for(int i=2; i<=100; ++i){
		int temp = i*i*i, counter = 2, num = i*i*i;
		while(temp<=1000000){
			sieve[temp][0] = 1;
			temp = num*(counter++);
		}
	}
	int c = 1;
	for(int i=1; i<=1000000; ++i){
		if(sieve[i][0] == 0){
			sieve[i][1] = c++;
		}
	}
	for(int i=1; i<=n; ++i){
		scanf("%d", &ip);
		if(sieve[ip][0])
			printf("Case %d: Not Cube Free\n", i);
		else
			printf("Case %d: %d\n", i, sieve[ip][1]);
	}
	return 0;
}