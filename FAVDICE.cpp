// <http://www.geeksforgeeks.org/expected-number-of-trials-before-success/>
// Coupon Collector problem

#include <iostream>

using namespace std;

int main(){
	int ncases;
	scanf("%d", &ncases);
	while(ncases--){
		int N;
		scanf("%d", &N);
		double sum = 0.0f;
		for(int i=1; i<=N; ++i){
			sum += ((double)1/i);
		}
		printf("%0.2f\n", sum*N);
	}
	return 0;
}