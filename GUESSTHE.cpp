// instead of the below for 'Y' case, we can do it together at the end
// find lcm of all 'Y''s and later, together check if 'N''s divide it

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findlcm(int a, int b){
	int temp;
	if(a<b){
		temp = b;
		b = a;
		a = temp;
	}
	temp = b;
	while(b % a != 0){
		b += temp;
	}
	return b;
}

int main(){
	string input;
	while(true){
		cin>>input;
		if(input[0] == '*')
			break;
		
		int ans = 1;
		vector<int> divs;

		for(int i=0; i<input.length(); ++i){
			if(input[i] == 'Y'){
				ans = findlcm(ans, i+1);
				for(auto it = divs.begin(); it!=divs.end(); ++it){
					if(ans%(*it) == 0){
						ans = -1;
						break;
					}
				}
				if(ans == -1)
					break;
			}
			else{
				if(ans % (i+1) == 0){
					ans = -1;
					break;
				}
				divs.push_back(i+1);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}