// sieve used for other purposes

#include <iostream>

#define MAX 34000

using namespace std;

int main(){
	bool list[MAX] = {};
	list[0] = 1; list[1] = 1;
	for(int i=2; i<MAX; ++i){
		if(not list[i]){
			int count = 0;
			for(int j=i+1; j<MAX; ++j){
				if(not list[j])
					++count;
				if(count == i){
					list[j] = 1;
					count = 0;
				}
			}
		}
	}
	int ones = 0;

	int lucky[3001];

	for(int i=0;i<MAX;++i)
		if(not list[i])
			lucky[++ones] = i;

	int num;
	while(true){
		scanf("%d", &num);
		if(num == 0)
			break;
		cout<<lucky[num]<<endl;
	}


	return 0;
}