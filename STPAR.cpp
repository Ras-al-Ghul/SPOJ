// not emptying stack costed one WA

#include <iostream>
#include <stack>

#define ui unsigned int
#define MAXSIZE 1001;

using namespace std;

int main(){
	ui numofmobiles;
	ui temp;
	ui counter;

	bool flag;

	while(true){
		stack<ui> mobiles;
		scanf("%u", &numofmobiles);
		if(numofmobiles == 0)
			break;

		counter = 1;
		flag = true;
		while(numofmobiles--){
			scanf("%u", &temp);
			if(temp==counter){
				counter += 1;
				while(mobiles.empty() != true && mobiles.top() == counter){
					mobiles.pop();
					counter += 1;
				}
			}
			else{
				if(mobiles.empty() != true && temp>mobiles.top()){
					flag = false;
				}
				else{
					mobiles.push(temp);
				}
			}
		}
		if(flag)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}

	return 0;
}