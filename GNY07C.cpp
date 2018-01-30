#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

using namespace std;

inline int to_dig(char c){
	if(c==' ')
		return 0;
	else
		return c-64;
}

string to_bin(int num){
    string binary = std::bitset<5>(num).to_string(); //to binary
    return binary;
}

int main(){
	int n; scanf("%d", &n);
	string input, cur; getline(cin, input);
	for(int count=1; count<=n; ++count){
		int r, c;
		getline(cin, input);
		stringstream ss(input);
		ss>>r>>c;
		getline(ss, input);
		// first char of input is space which has to be ignored
		
		int arr[r][c] = {};
		int right = c, down = r, left = 0, up = 0;
		int m = 0, n = 0, toggle = 1;
		for(int i=1; i<input.length(); ++i){
			cur = to_bin(to_dig(input[i]));
			for(int j=0; j<5; ++j){
				arr[m][n] = cur[j]-48;
				switch(toggle){
					case 1:
						if(n+1 < right)
							++n;
						else{
							right -= 1;
							toggle = 2;
							++m;
						}
						break;
					case 2:
						if(m+1 < down)
							++m;
						else{
							down -= 1;
							toggle = 3;
							--n;
						}
						break;
					case 3:
						if(n-1 >= left)
							--n;
						else{
							left += 1;
							toggle = 4;
							--m;
						}
						break;
					case 4:
						if(m-1 > up)
							--m;
						else{
							up += 1;
							toggle = 1;
							++n;
						}
						break;
				}
			}
		}
		printf("%d ", count);
		for(int i=0; i<r; ++i)
			for(int j=0; j<c; ++j)
				printf("%d", arr[i][j]);
		printf("\n");
	}
	return 0;
}