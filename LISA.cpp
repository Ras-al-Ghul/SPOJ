#include <iostream>
#include <string>
#include <climits>

#define ll long long
#define to_num(temp) temp-'0'

inline ll sign(ll a, ll b, char temp){
	return temp=='+'?a+b:a*b;
}

using namespace std;

int main(){
	int k; scanf("%d", &k);
	string input;
	while(k--){
		cin>>input;
		ll len = input.length();
		ll numlen = (len+1)/2;
		// 0 is max, 1 is min for third index
		ll arr[numlen][numlen][2] = {};

		arr[0][0][0] = arr[0][0][1] = to_num(input[0]);
		for(int i=1; i<numlen; ++i){
			arr[i][i][0] = arr[i][i][1] = to_num(input[2*i]);
			for(int j=i-1; j>=0; --j){
				arr[j][i][0] = 0; arr[j][i][1] = LONG_LONG_MAX;
				for(int k=i; k>j; --k){
					arr[j][i][0] = max(arr[j][i][0], sign(arr[j][k-1][0],arr[k][i][0],input[(2*k)-1]));
					arr[j][i][1] = min(arr[j][i][1], sign(arr[j][k-1][1],arr[k][i][1],input[(2*k)-1]));
				}
			}
		}
		printf("%lld %lld\n", arr[0][numlen-1][0], arr[0][numlen-1][1]);
	}
	return 0;
}