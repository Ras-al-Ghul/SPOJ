// <https://math.stackexchange.com/questions/1230223/finding-sum-k-1na-k-knowing-that-a-1-2a-2-ka-k-frack1k2>
// think if telescopic cancellation is possible
// generate eqn. for a(i), using sum(a(i))-sum(a(i-1))
// then sum a(i) for all i and see that it cancels telescopically

#include <iostream>

using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		double sum = (double(3)/4) - (double(1)/(2*(1+n))) + (double(1)/(2*(2+n)));
		printf("%.11lf\n", sum);
	}

	return 0;
}