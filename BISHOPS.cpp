// straightforward multiply by two and subtract by two

#include <iostream>
#include <string>

#define MAXSIZE 101

using namespace std;

int main(){
	string line;
	int arr[MAXSIZE];
	int arrcounter;
	while(getline(cin, line)){
		int len = line.length();
		if(len == 0)
			break;
		if(len == 1){
			if(line[0] == '1')
				cout<<1<<endl;
			else
				cout<<(line[0] - '0') * 2 - 2<<endl;
			continue;
		}

		arrcounter = MAXSIZE - len;
		for(int i=arrcounter; i<MAXSIZE; i++){
			arr[i] = line[i-MAXSIZE+len] - '0';
		}

		// multiply by 2
		int carry = 0, temp;
		for(int i=MAXSIZE-1; i>=arrcounter; i--){
			temp = (arr[i]*2) + carry;
			arr[i] = temp%10;
			carry = temp/10;
		}
		if(carry != 0){
			while(carry/10 != 0){
				arr[--arrcounter] = carry%10;
				carry/=10;
			}
			arr[--arrcounter] = carry%10;
		}

		// subtract by 2
		int borrowcount = MAXSIZE-1;
		if(arr[MAXSIZE-1] < 2){
			arr[borrowcount] = arr[borrowcount] + 10 - 2;
			borrowcount--;
			while(arr[borrowcount] == 0){
				arr[borrowcount--] = 9;
			}
			arr[borrowcount] = arr[borrowcount] - 1;
		}
		else{
			arr[MAXSIZE-1] = arr[MAXSIZE-1] - 2;
		}

		// skip through 0 terms
		while(arr[arrcounter] == 0)
			arrcounter++;

		for(int i=arrcounter; i<MAXSIZE; i++){
			cout<<arr[i];
		}
		cout<<endl;

	}
	return 0;
}