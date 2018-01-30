#include <iostream>
#include <cmath>
#include <string>
#include <bitset>

using namespace std;

string to_bin(long num){
    string binary = std::bitset<64>(num).to_string(); //to binary
    return binary;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		long long n; scanf("%lld", &n);
		long long pows = (long long)(log2(n));
		if((long long)(pow(2,pows)) < n)
			pows += 1;
		string temp = to_bin(n);
		long long count = pows;
		for(int i=63; i>=0; --i)
			if(temp[i]=='1')
				break;
			else
				count--;
		printf("%lld %lld\n", (long long)(pow(2,pows)), max(count, (long long)(0)));
	}
	return 0;
}