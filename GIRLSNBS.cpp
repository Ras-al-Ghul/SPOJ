// a=0 b=0 was edge case

#include <iostream>

using namespace std;

int main(){
	int a, b, temp;
	while(true){
		scanf("%d %d", &a, &b);
		if(a==-1 and b==-1)
			break;
		temp = max(a,b);
		b = min(a,b);
		a = temp;
		if(a>b){
			temp = a/(b+1);
			if(a%(b+1)!=0){
				cout<<temp+1<<endl;
			}
			else{
				cout<<temp<<endl;
			}
		}
		else{
			if(a != 0 and b != 0)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
	}
	return 0;
}