#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

#define ul unsigned long

using namespace std;

inline char to_char(ul num){
	if(num==0)
		return ' ';
	else
		return char(num+64);
}

ul to_num(string binary){
    ul decimal = std::bitset<5>(binary).to_ulong();
    return decimal;
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

		for(int i=0; i<r; ++i)
			for(int j=0; j<c; ++j)
				arr[i][j] = input[i*c+(j+1)]-48;

		string output = "", temp = ""; int counter = (r*c)/5;
		int right = c, down = r, left = 0, up = 0;
		int m = 0, n = 0, toggle = 1;
		while(counter--){
			for(int j=0; j<5; ++j){
				temp += char(arr[m][n]+48);
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
			output += to_char(to_num(temp));
			temp = "";
		}
		counter = output.length()-1;
		while(output[counter] == ' ')
			counter--;
		output.erase(counter+1);
		cout<<count<<" "<<output<<endl;
	}
	return 0;
}