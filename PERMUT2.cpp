// ui(num+1) caused SIGABRT
// forgot to use delete[], caused 1 SIGSEGV

#include <iostream>

#define ui unsigned int

using namespace std;

int main(){
	ui num;
	while(true){
		scanf("%u", &num);
		if(num==0)
			break;

		ui* arr = new ui[num+1];
		ui* inv = new ui[num+1];

		for(ui i=1; i<=num; i++){
			scanf("%u", &arr[i]);
			inv[arr[i]] = i;
		}
		bool flag = true;
		for(ui i=1; i<=num; i++){
			if(arr[i] != inv[i]){
				cout<<"not ambiguous"<<endl;
				flag = false;
				break;
			}
		}
		if(flag)
			cout<<"ambiguous"<<endl;
		delete[] arr;
		delete[] inv;
	}

	return 0;
}