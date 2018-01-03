#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		string input; cin>>input;
		int len = input.length();
		if(input[len-1] == ' '){
			printf("%c\n", input[len-2]);
		}
		else{
			printf("%c\n", input[len-1]);	
		}
	}
	return 0;
}