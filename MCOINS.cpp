// can make it bottom up easily

#include <iostream>

using namespace std;

int k,l;

int recurse(int n, int val[], char person){
	char newperson = person == 'A'? 'B':'A';
	if(val[n] != 0)
		return val[n];
	if(n == 1){
		val[1] = 1;
		return 1;
	}
	if(n == 0){
		val[0] = 2;
		return 2;
	}
	if(n < 0)
		return -1;

	int first = recurse(n-k, val, newperson);
	int second = recurse(n-l, val, newperson);
	int third = recurse(n-1, val, newperson);

	if(first == 2 or second == 2 or third == 2){
		val[n] = 1;
	}
	else{
		val[n] = 2;
	}
	return val[n];
}

int main(){
	int m, n;
	scanf("%d %d %d", &k, &l, &m);
	while(m--){
		scanf("%d", &n);
		// 1 means indicated person wins, 2 means loses
		int val[n+1] = {};
		recurse(n, val, 'A');
		if(val[n] == 1)
			printf("A");
		else
			printf("B");
	}
	printf("\n");
	return 0;
}