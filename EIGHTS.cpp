// 192
// 442
// 692
// 942

// look for patterns
// in this case 888 ending means only 4 numbers within 1000 gave that
// looked up until 2000, it was 1192, 1442, 1692, 1942, hence the pattern
// increment counters quickly
// if even faster desired, then cannot increment counters, have to set counters
// in this case array positions are being set, not counted

#include <iostream>

#define MAXSIZE 64
#define ull unsigned long long

using namespace std;

int main(){
	ull numoftestcases;
	scanf("%llu", &numoftestcases);

	int arr[MAXSIZE];
	int arrcounter;
	ull toggle;
	// toggle 0 is 192, etc.

	ull number;
	while(numoftestcases--){
		scanf("%llu", &number);
		toggle = -1;
		for(int i=0; i<MAXSIZE-3; i++){
			arr[i] = 0;
		}
		bool flag = false;
		toggle = (number+3)%4;
		ull div_four;
		if(toggle == 3)
			div_four = (ull)(number/4) - 1;
		else
			div_four = (ull)(number/4);

		int i;
		
		for(i=MAXSIZE-4; i>=0; i--){
			int tempdigit = div_four%10;
			arr[i] = tempdigit;
			div_four/=10;
			if(div_four==0)
				break;
		}
		arr[i-1] = div_four%10;

		for(i=0; i<MAXSIZE-3; i++){
			if(arr[i] != 0)
				break;
		}
		for(;i<MAXSIZE-3; i++)
			cout<<arr[i];
		switch(toggle){
			case 0:
				cout<<192<<endl;
				break;
			case 1:
				cout<<442<<endl;
				break;
			case 2:
				cout<<692<<endl;
				break;
			case 3:
				cout<<942<<endl;
				break;
		}
	}
	return 0;
}