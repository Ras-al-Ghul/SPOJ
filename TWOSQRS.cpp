// https://www.quora.com/How-do-I-check-if-a-number-can-be-expressed-as-x-raised-to-power-y
// brute force with some optimization steps
// optimization where low incremented, high decremented

#include <iostream>
#include <cmath>

#define ll long long
#define MAX 1000000

using namespace std;

int main(){
	ll i, ncases, n, low, high, sum, llarr[MAX+1];
	bool flag;
	for(i=0;i<MAX+1;i++){
		llarr[i] = i*i;
	}
	scanf("%lld", &ncases);
	while(ncases--){
		scanf("%lld", &n);
		high = sqrt(n);
		low = 0;
		flag = false;
		while(low<=high){
			sum = llarr[low] + llarr[high];
			if(sum == n){
				flag = true; break;
			}
			if(sum > n){
				high--;
				continue;
			}
			low++;
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}