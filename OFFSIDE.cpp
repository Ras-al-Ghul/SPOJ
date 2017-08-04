#include <iostream>

using namespace std;

int main(){
	int a, d, temp;
	int first, second;
	int p;
	while(true){
		scanf("%d %d", &a, &d);

		if(a == 0 and d == 0)
			break;

		p = 10001;
		while(a--){
			scanf("%d", &temp);
			if(temp < p)
				p = temp;
		}
		first = 10001, second = 10001;
		while(d--){
			scanf("%d", &temp);
			if(temp < second){
				second = temp;
				if(temp < first){
					second = first;
					first = temp;
				}
			}
		}
		if(p < second)
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}

	return 0;
}