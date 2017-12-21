#include <iostream>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	long ans = 0;
	long temp;
	for(int i=0; i<n; ++i){
		scanf("%ld", &temp);
		ans = ans ^ temp;
	}
	printf("%ld", ans);
	return 0;
}