#include <iostream>
#include <set>

using namespace std;

int main(){
	long num, lastdig, sum = 0, counter = 0;
	bool flag = 1;
	set<long> seennumbers;
	scanf("%ld", &num);
	while(true){
		sum = 0;
		while(num != 0){
			lastdig = num % 10;
			sum += (lastdig*lastdig);
			num /= 10;
		}
		if(seennumbers.find(sum) == seennumbers.end()){
			seennumbers.insert(sum);
			num = sum;
			counter += 1;
		}
		else{
			flag = 0;
			break;
		}
		if(num == 1)
			break;
	}
	if(flag)
		cout<<counter<<endl;
	else
		cout<<-1<<endl;
	return 0;
}