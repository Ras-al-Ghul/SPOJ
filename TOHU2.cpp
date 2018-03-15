// very cryptic problem statement
// he just guesses the character of the possible numbers
// the possible numbers are 9, 18, 27, ... 81
// see the commented loop below for that
// so if char[9] = char[18] = ..
// he just says one of them and that is equal to answer for any number

#include <iostream>

using namespace std;

int main(){
	// for(int i=10; i<100; ++i){
	// 	int sum = 0, temp = i;
	// 	while(temp != 0)
	// 		sum += (temp%10), temp/=10;
	// 	cout<<i<<" "<<sum<<" "<<i-sum<<endl;
	// }
	int t; scanf("%d", &t);
	while(t--){
		char intmaps[100] = {};
		int n; char c;
		bool flag = true;
		for(int i=1; i<=99; ++i){
			scanf("%d %c", &n, &intmaps[i]);
		}
		for(int i=18; i<=81; i+=9){
			if(intmaps[i] != intmaps[i-9])
				flag = false;
		}
		if(not flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}