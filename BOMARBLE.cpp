// OEIS saved the day again
// they say that it's an easy patter/recurrence to spot - dp

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n;
	while(true){
		scanf("%d", &n);
		if(n == 0)
			break;
		int offset = n+1;
		int ans = 0;
		for(int i=0; i<offset; ++i){
			ans += (offset+i);
		}
		printf("%d\n", ans);
	}
	return 0;
}