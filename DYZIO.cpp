#include <iostream>
#include <string>

using namespace std;

int count;
int cuts;
int ans;

int recurse(string input, int num, int pos){
	if(pos<input.length() and input[pos] == '1'){
		cuts++;
		if(count < num)
			ans = cuts;
		count = max(count, num);
		pos = recurse(input, num+1, pos+1);
		return recurse(input, num+1, pos+1);
	}
	else
		return pos;
}

int main(){
	int n; string input;
	for(int i=0; i<10; ++i){
		scanf("%d", &n);
		cin>>input;

		count = 0, cuts = 0, ans = 0;
		recurse(input, 1, 0);

		printf("%d\n", ans);
	}
	return 0;
}