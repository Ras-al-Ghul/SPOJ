// notice that if you draw line on diagonal, you split polygon into two,
// next again you can split the already split part into two,..
// so powers of two - log2

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t, n; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n&1)
			++n;
		printf("%d\n", int(ceil(log2(n)))+1);
	}
	return 0;
}