// better solution would be to find gcd of all the in between distances
// this - current code - is worst case O(maxDist*n) which is bad
// gcd of n numbers code: gcd can only decrease - so starting from smallest two is best
// int result = numbers[0];
// for(int i = 1; i < numbers.length; i++){
//     result = gcd(result, numbers[i]);
// }
// return result;

#include <iostream>
#include <climits>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	long arr[n];
	long mindist = LONG_MAX;
	scanf("%ld", &arr[0]);
	for(int i=1; i<n; ++i){
		scanf("%ld", &arr[i]);
		if(arr[i] - arr[i-1] < mindist)
			mindist = arr[i] - arr[i-1];
	}
	long numtrees = 0;
	for(long i = mindist; i>=0; i--){
		int j;
		for(j=1; j<n; ++j){
			long temp = arr[j] - arr[j-1];
			if(temp % i == 0){
				numtrees += ((temp/i) - 1);
			}
			else{
				numtrees = 0;
				break;
			}
		}
		if(j == n){
			printf("%ld\n", numtrees);
			break;
		}
	}
	return 0;
}