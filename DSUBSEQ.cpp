// long arr[26][input.length()+1] = {}; where input is a string
// was giving compiler internal error - no idea why

// adding mod where answer can go negative is very important
// i.e. ((2*x - y)+MOD)%MOD instead of (2*x - y)%MOD

// logic eg:
// BADA
// for each letter encountered, two ways,
// add this current letter to all previous subsequences
// don't add this current letter
// hence, ans[i] = ans[i-1]*2
// when you encounter a letter for second time, you subtract everything (all cases)
// to the left of the previously encountered index of same letter
// i.e. A in above = ans[D] - ans[B]

#include <iostream>
#include <string>

using namespace std;

const long MOD = 1000000007;

int main(){
	int t, index; scanf("%d", &t);
	long ans = 0, temp;
	string input;
	while(t--){
		cin>>input;
		long len = input.length();
		long arr[26][len];
		for(int i=0; i<26; ++i)
			arr[i][0] = 0;
		arr[int(input[0])-65][1] = 1;
		arr[int(input[0])-65][0] = 1;
		ans = 2;
		for(int i=1; i<input.length(); ++i){
			if(arr[int(input[i])-65][0] != 0){
				index = arr[int(input[i])-65][0];
				temp = arr[int(input[i])-65][index];
				arr[int(input[i])-65][index+1] = ans;
				arr[int(input[i])-65][0] = index+1;
				ans = ((ans*2)-temp+MOD)%MOD;
			}
			else{
				arr[int(input[i])-65][1] = ans;
				arr[int(input[i])-65][0] = 1;
				ans = (ans*2)%MOD;
			}
		}
		printf("%ld\n", ans);
	}

	return 0;
}