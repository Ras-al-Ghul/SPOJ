#include <iostream>
#include <string>

using namespace std;

int main(){
	int t = 1;
	string input;
	while(getline(cin, input)){
		int ans = 0;
		int toggle = 0;
		for(int i=0; i<input.length(); ++i){
			if(input[i] == '1'){
				if(toggle == 0){
					++ans; toggle = 1;
				}
			}
			else{
				if(toggle == 1){
					++ans; toggle = 0;
				}
			}
		}
		printf("Game #%d: %d\n", t++, ans);
	}
	return 0;
}